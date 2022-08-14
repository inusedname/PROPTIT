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
### Permissions changelog by API
1. From [Android 6.0](https://developer.android.com/about/versions/marshmallow/android-6.0-changes#behavior-runtime-permissions)
    + New: Runtime Permissions
    + Hardware Identifier
        + To get nearby external device's hardware identifier, must have `ACCESS_FINE_LOCATION` or `ACCESS_COARSE_LOCATION`
2. From [Android 7.0](https://developer.android.com/about/versions/nougat/android-7.0-changes#perm)
    + Private files has restricted access to avoid leakage of metadata (size, date...)
3. From [Android 8.0](https://developer.android.com/about/versions/oreo/android-8.0-changes#rmp)
    + Before 8.0: In Manifest, if there are >= 2 permissions declared and they are in the same Permission group, when one of them is granted, System will incorrectly grant the rest permission.
    + For example, suppose an app lists both `READ_EXTERNAL_STORAGE` and `WRITE_EXTERNAL_STORAGE` in its manifest. The app requests `READ_EXTERNAL_STORAGE` and the user grants it. If the app targets API level 25 or lower, the system also grants `WRITE_EXTERNAL_STORAGE` at the same time, because it belongs to the same STORAGE permission group and is also registered in the manifest.

4. From [Android 9.0](https://developer.android.com/about/versions/pie/android-9.0-changes-all#privacy-changes-all)
    - Limited access to sensors in background: 
        + Camera: No access
        + Continuous Report Sensor (accelerometers, gyroscope): Don't receive events
        + On-change Report Sensor: Don't receive events
        + To receive events, use foreground service.
    - New: `CALL_LOG` permission group, previously located in `PHONE` permission group.
    - Reading `phone numbers` or `phone state` take more steps.
    - Performing Wifi scans, getting connect info require more steps

5. From [Android 10](https://developer.android.com/about/versions/10/privacy/changes#top-changes)
    - App now can access scoped storage (app-specific dir) without needing to request any storage-related permissions
    - To access to files outside app-specific dir, use [MANAGE_EXTERNAL_STORAGE](https://developer.android.com/training/data-storage/manage-all-files) permission.
    - Access to device location background requires permission `ACCESS_BACKGROUND_LOCATION`
6. From [Android 11](https://developer.android.com/about/versions/11/privacy)
    - Scoped storage enforcement: Apps that target Android 11 or higher are always subject to scoped storage behaviors: 
        + Starting in Android 11, apps cannot create their own app-specific directory on external storage. To access the directory that the system provides for your app, call getExternalFilesDirs()
    - One-time permissions
    - Permissions auto-reset
    - Background location access
    - [Foreground services](https://developer.android.com/about/versions/11/privacy/foreground-services):
        If your app targets Android 11 or higher and accesses the camera or microphone in a foreground service, you must include the camera and microphone foreground service types.