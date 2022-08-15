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
## Permission là gì ?
- Permissions bảo vệ quyền riêng tư người dùng bằng cách:
    + Giới hạn quyền truy cập dữ liệu: Tình trạng hệ thống (wifi, bluetooth), thông tin liên lạc 
    + Giới hạn hành động được phép làm: Kết nối đến thiết bị không dây: tai nghe. Sử dụng camera, microphone
- Workflow sử dụng permission trên Android
![](/doc-kotlin/res/workflow-overview.svg)
1. Tính năng có hoạt động được mà không cần thiết phải cấp quyền không ?
- True -> Bước 2a
- False -> Bước 2b

2.  a) ĐÃ THOẢ: Đã có thể sử dụng tính năng ở đây
    b) Thêm `<user-permission>` vào trong Manifest -> Bước 4

3. Permission này có phải là runtime permission ?
- True -> Bước 2a
- False -> Bước 4

4. Request quyền từ user -> Bước 2a
## Các loại permissions (phạm vi truy cập/mức độ nguy hiểm)
### Install-time Permissions (cấp khi tải ứng dụng)
- Được truy cập giới hạn vào dữ liệu đặc biệt
- Được phép làm các hành động nếu nó không gây ảnh hướng lớn tới hệ thống Android
- Android sẽ tự cấp cho app quyền này khi user tải
![](/doc-kotlin/res/install-time.svg)
> Hình 2. Danh sách một loạt các permission được cấp khi tải ứng dụng
- Bao gồm normal permissions and signature permissions - các permission mà được viết nên bởi 1 tổ chức và được sử dụng bởi 1 số lượng các app (không phải common, public)

### Runtime Permissions (cấp khi chạy app - nguy hiểm)
- Được nới giới hạn truy cập vào dữ liệu đặc biệt
- Được phép làm các hành động có sức ảnh hưởng lớn hơn tới hệ thống Android
- App cần được người dùng cho phép trước khi có thể truy cập dữ liệu/thực hiện hành động.
![](/doc-kotlin/res/runtime.svg)
> Hình 3. Thông báo yêu cầu cho phép runtime permission

### Special permissions (rất nguy hiểm)
- Loạt các hành động có ảnh hướng lớn, trực tiếp tới hệ thống Android:
- Truy cập: `Settings` -> `App and Notification` -> `Special App Access`
- Ví dụ: 
    + Device admin apps: `Find My Device`
    + Notification access: `My Viettel`
    + Install unknown apps: `Chrome, Zalo`

## Yêu cầu permission
- Workflow
![](/doc-kotlin/res/workflow-runtime.svg)
### Kiểm tra permission đã được cấp hay chưa
- Truyền vào bên trong `ContextCompat.checkSelfPermission()` tên permission cần kiểm tra. Hàm này sẽ trả về`PERMISSION_GRANTED` hoặc `PERMISSION_DENIED` tương ứng

### Các quy tắc cần tuân thủ
- Khi nào cần quyền thì mới xin, không xin một loạt từ lúc mới vào app
- Không được chặn không cho người dùng sử dụng app nếu người dùng từ chối trao quyền
- Nếu người dùng thu hồi quyền, tắt đi tính năng không sử dụng được và vẫn phải cho người dùng sử dụng app như thường
- Giải thích tại sao app cần quyền này

### Làm thế nào để request permission
#### Dùng requestPermissions()
```kt
// MainActivity.kt

fun requestPermission() {
    when {
        ContextCompat.checkSelfPermission(
                [CONTEXT],
                Manifest.permission.[REQUESTED_PERMISSION]
                ) == PackageManager.PERMISSION_GRANTED -> {
            
            // Quyền đã được cấp. Làm gì thì làm đi.
            performAction(...)
        }
        shouldShowRequestPermissionRationale(...) -> {
        /*
            Hàm shouldShowRequestPermissionRationale() returns true nếu app đã 1 lần yêu cầu quyền và người dùng đã từ chối.
            Nếu người dùng đã từ chối, và lần này tiếp tục ấn từ chối lần thứ 2 (hoặc ấn Don't ask again ở các API Android thấp hơn), hàm sẽ trả về false.
        */
            showMessage()
            requestPermissions(...)
        }
        else -> {
            // Dùng hàm này để yêu cầu quyền
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
            // Nếu Request không có phản hồi (user bấm ra ngoài thông báo, mảng grantResults sẽ empty)
            if ((grantResults.isNotEmpty() &&
                    grantResults[0] == PackageManager.PERMISSION_GRANTED)) {
                // Quyền đã được cấp
                // Làm gì thì làm đi.
            } else {
                // Giải thích tại sao feature này không khả dụng lí do rằng user đã từ chối cấp quyền
                // Tôn trọng quyết định của user. Không được chuyển hướng sang Setting của app để buộc người dùng phải cấp quyền.
            }
            return
        }

        else -> {
            // Bỏ qua các yêu cầu khác
        }
    }
}
```
#### Sử dụng contract RequestPermission()

1. Tạo một biến loại `ActivityResultCallback` gọi tới `registerForActivityResult()`. Callback này sẽ xử lý khi có kết quả yêu cầu quyền từ người dùng 
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
2. Gọi hàm `launch()` ở cái launcher vừa tạo:
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
            showInContextUI(...)
        }
        else -> {
            // Callback đã nghe được
            requestPermissionLauncher.launch(
                    Manifest.permission.REQUESTED_PERMISSION)
        }
    }
}
```
### Changelog permission theo API
1. Kể từ [Android 6.0](https://developer.android.com/about/versions/marshmallow/android-6.0-changes#behavior-runtime-permissions)
    + Mới: Runtime Permissions
    + ID của phần cứng:
        + Để có được thông tin MAC/IP/Bluetooth Address của phụ kiện (tai nghe, bàn phím), cần khai báo `ACCESS_FINE_LOCATION` hoặc `ACCESS_COARSE_LOCATION`
2. Kể từ [Android 7.0](https://developer.android.com/about/versions/nougat/android-7.0-changes#perm)
    + Tệp tin riêng tư sẽ được bảo vệ chặt chẽ tránh việc lộ metadata (kích thước file, ngày tạo, ngày chỉnh sửa)
3. Kể từ [Android 8.0](https://developer.android.com/about/versions/oreo/android-8.0-changes#rmp)
    + Trước 8.0, Nếu có một loạt các quyền được khai báo bên trong file Manifest, khi người dùng cho phép 1 quyền, thì toàn bộ các quyền khác mà nằm chung nhóm permission đó sẽ được cấp theo.
    + 8.0 sửa lỗi này
    + Ví dụ, App yêu cầu 2 quyền `READ_EXTERNAL_STORAGE` `WRITE_EXTERNAL_STORAGE`. Khi ứng dụng yêu cầu `READ_EXTERNAL_STORAGE` và người dùng cho phép quyền này. Ở các API level 25 và thấp hơn, hệ thống cũng sẽ tự động trao luôn quyền `WRITE_EXTERNAL_STORAGE`, bởi vì cả hai quyền trên đều nằm trong nhóm permission STORAGE và được liệt kê bên trong file Manifest

4. Kể từ [Android 9.0](https://developer.android.com/about/versions/pie/android-9.0-changes-all#privacy-changes-all)
    - Giới hạn thông tin truy cập được từ các cảm biến ở trạng thái background
        + Camera: Không được phép
        + Continuous Report Sensor (accelerometers, gyroscope): Không nhận được events
        + On-change Report Sensor: Không nhận được events
        + Để nhận event, cần chuyển sang service foreground
    - Mới: Nhóm quyền `CALL_LOG` tách ra từ nhóm quyền `PHONE`.
    - Truy cập `số điện thoại` hoặc `trạng thái điện thoại (đang gọi, đang quay số)` cần thêm nhiều bước
    - Quét wifi, lấy thông tin mạng đang sử dụng sẽ cần thêm nhiều bước

5. Kể từ [Android 10](https://developer.android.com/about/versions/10/privacy/changes#top-changes)
    - Ứng dụng từ giờ sẽ chỉ được truy cập vào scoped storage (thư mục riêng của app, được hệ thống Android cấp riêng) và không cần phải khai báo quyền truy cập bộ nhớ trong file Manifest
    - Để đọc các file bên ngoài thư mục riêng của app, sử dụng quyền [MANAGE_EXTERNAL_STORAGE](https://developer.android.com/training/data-storage/manage-all-files).
    - Khi cần theo dõi vị trí người dùng ở trạng thái background, cần cung cấp quyền `ACCESS_BACKGROUND_LOCATION`
6. Kể từ [Android 11](https://developer.android.com/about/versions/11/privacy)
    - Tăng cường tính năng scoped storage:
        + Ứng dụng sẽ không còn có thể tự tạo thư mục riêng trong bộ nhớ. Để truy cập vào cái của riêng nó mà được hệ thống cấp cho, sử dụng getExternalFilesDirs()
    - Hỗ trợ Chỉ cho phép cung cấp quyền 1 lần
    - Tự động xoá quyền nếu không sử dụng app 1 thời gian
    - [Foreground services](https://developer.android.com/about/versions/11/privacy/foreground-services):
        Nếu app target Android11+ và sử dụng camera hoặc microphone ở foreground, cần phải khai báo các thuộc tính camera và microphone ở `<service>`