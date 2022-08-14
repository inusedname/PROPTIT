# Service - Broadcast - Permission

> Cần nắm:
Service: Khái niệm về service, các loại service.\
Broadcast: Broadcast là gì? Cách sử dụng broadcast\
Permission: Khái niệm về permission, cách kiểm tra ứng dụng của mình đã được cấp quyền hay chưa?. Cách xin permission từ hệ thống. Những điều cần lưu ý khi xin permission. (Lưu ý có sự khác nhau giữa các API cần tìm hiểu rõ điều này.)\
Chuẩn bị bài tập:\
Service: Tạo 1 service cung cấp location và hiển thị lên màn hình.\
Brocast Receiver: Tạo 1 broacast receiver nhận trạng thái của pin và show lên màn hình.\
Permission: Áp dụng permission để xin quyền cấp vị trí hiện tại.\

# Service
## What is service ?
- Application Component ([same level](https://developer.android.com/guide/components/fundamentals#Components) with Activities, Broadcast Listeners, Content Providers)
- Run in background
- Perform long-running, continuously operations
- No UI

### Types of services
- __Started service__: The service is unbounded to any other components, just itself. 
    + __Foreground__ (example: Music App)
    Users want to hear it (Music Playback) as long as they done the job. No interceptions should occurs during the experience.
    + __Background__ (example: Syncing data)
    User doesn't care much about the job, so system has more freedom in managing service. Service can be killed, and then be restarted later.
- __Bound service__: There are other components wants to interact with the service, send request, receive result... The service provides an API to another process. 

### Lifecycle
![](/doc-kotlin/res/1b404092-6a5e-4525-8ae6-7932f4336e45.jpg)
### Note:
- Service runs in main thread by default.
- Service runs indefinitely, until `stopSelf()` or `stopService()` is called.

# Broadcast Receiver
## What is broadcast ?
- Application Component
- When an event occurs
- App which registered to receive specific broadcast (subscribed) will be notify about the event.
- App no need to run
- Broadcast from system: screen turn off, battery low, picture was captured...
## How to use
- Creat a Broadcast which is a subclass of `BroadcastReceiver`
- Each Broadcast is delivered as an `Intent` object.

# Permissions
## What is permission ?
- Permissions protect user privacy by protect access to:
    + Restricted data: System state, user's contact information
    + Restricted actions: Connecting to a paired devices, recording audio.
- Workflow for using permission on Android
![](/doc-kotlin/res/workflow-overview.svg)
## Types of permissions (by scope)
### Install-time permissions
- Give limited access to restricted data
- Allow restricted actions if not heavily impacted to system.
- Automatically granted when user install apps.
![](/doc-kotlin/res/install-time.svg)
> Figure 2. The list of an app's install-time permissions, which appears in an app store.

- Include normal permissions and signature permissions - permissions which are custom defined and used in a bunch of app. 

### Runtime permissions (dangerous)
- Additional access to restricted data
- Perform more heavily affected actions to system.
- App have to request runtime permissions before accesss data/performs actions
![](/doc-kotlin/res/runtime.svg)
> Figure 3. The system permission prompt that appears when your app requests a runtime permission.

### Special permissions (above dangerous)
- Powerful actions, directly relates to system:
- `Settings` -> `App and Notification` -> `Special App Access`
- Some of them: 
    + Device admin apps: `Find My Device`
    + Notification access: `My Viettel`
    + Install unknown apps: `Chrome, Zalo`

## Request permission
- Workflow
![](/doc-kotlin/res/workflow-runtime.svg)
### Check whether your app was already granted the permission
- Pass permission into `ContextCompat.checkSelfPermission()` method. This method will return either `PERMISSION_GRANTED` or `PERMISSION_DENIED`

### Rules
- Ask only when the user starts to interact with feature require permission
- Don't block the user. You shouldn't stop user from using app if they deny granting permission
- If user denies/revokes a permission, degrade app so user can still normally use your app, by disabling feature
- Explain user why your app need the permission if neccessary

### Requesting permission
#### Using requestPermissions()
```kt
// MainActivity.kt

fun requestPermission() {
    when {
        ContextCompat.checkSelfPermission(
                [CONTEXT],
                Manifest.permission.[REQUESTED_PERMISSION]
                ) == PackageManager.PERMISSION_GRANTED -> {
            
            // Now do the job require permission
            performAction(...)
        }
        shouldShowRequestPermissionRationale(...) -> {
        /*
            The shouldShowRequestPermissionRationale() function returns true if the app has requested this permission
            previously and the user denied the request.
            If the user turned down the permission request in the past and chose
            the Don't ask again option, this method returns false.
        */
            showMessage()
            requestPermissions(...)
        }
        else -> {
            // You can directly ask for the permission.
            requestPermissions(CONTEXT,
                    arrayOf(Manifest.permission.REQUESTED_PERMISSION),
                    REQUEST_CODE)
        }
    }
}
```
```kt
// MainActivity.kt
// 

override fun onRequestPermissionsResult(requestCode: Int,
        permissions: Array<String>, grantResults: IntArray) {
    when (requestCode) {
        PERMISSION_REQUEST_CODE -> {
            // If request is cancelled, the result arrays are empty.
            if ((grantResults.isNotEmpty() &&
                    grantResults[0] == PackageManager.PERMISSION_GRANTED)) {
                // Permission is granted. Continue the action or workflow
                // in your app.
            } else {
                // Explain to the user that the feature is unavailable because
                // the features requires a permission that the user has denied.
                // At the same time, respect the user's decision. Don't link to
                // system settings in an effort to convince the user to change
                // their decision.
            }
            return
        }

        // Add other 'when' lines to check for other
        // permissions this app might request.
        else -> {
            // Ignore all other requests.
        }
    }
}
```
#### Using RequestPermission() contract

1. Create an implementation of `ActivityResultCallback` into a call to `registerForActivityResult()`. The `ActivityResultCallback` defines how your app handles the user's response to the permission request.
```kt
val requestPermissionLauncher =
    registerForActivityResult(RequestPermission()
    ) { isGranted: Boolean ->
        if (isGranted) {
            // Permission is granted. Continue the action or workflow in your
            // app.
        } else {
            // Explain to the user why they can't use this function
        }
    }
```
2. Call the `launch()` method on the instance of `ActivityResultLauncher` when neccessary
```kt
fun requestPermission() {
    when {
        ContextCompat.checkSelfPermission(
                CONTEXT,
                Manifest.permission.REQUESTED_PERMISSION
                ) == PackageManager.PERMISSION_GRANTED -> {
            // You can use the API that requires the permission.
        }
        shouldShowRequestPermissionRationale(...) -> {
            // In an educational UI, explain to the user why your app requires this
            // permission for a specific feature to behave as expected. In this UI,
            // include a "cancel" or "no thanks" button that allows the user to
            // continue using your app without granting the permission.
            showInContextUI(...)
        }
        else -> {
            // You can directly ask for the permission.
            // The registered ActivityResultCallback gets the result of this request.
            requestPermissionLauncher.launch(
                    Manifest.permission.REQUESTED_PERMISSION)
        }
    }
}
```