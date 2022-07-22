# Layout trong Android và Cấu trúc thư mục 1 project Android

## Cấu trúc thư mục 1 project Android
### Manifest
- File Manifest là file chưa toàn bộ thông tin về app này: bao gồm Android Build Tools, Android OS, Google Play
    + Manifest khai báo các Activity, Services, Broadcast Receiver được sử dụng trong app. Mỗi thành phần này sẽ bao gồm các thông tin quan trọng: tên class của nó, device config, intent filter
    + Những cái permissions mà app cần để hoạt động một tính năng có trong app
    + Sys requirement để lọc ra các điện thoại có thể hoạt động ổn định khi đăng lên CH Play.
### Res
- Toàn bộ tài nguyên sử dụng cho app được lưu tại đây
    + drawable: các icon, logo, tranh ảnh... lưu dưới dạng xml hoặc png...
    + layout: Các bản vẽ cho giao diện, hoặc element của app (button, view, cardview)
    + values: Các con số cố định được sử dụng trong project: ví dụ khoảng cách từ chân màn hình tới FAB.
    + string: lưu các xâu như một biến, để sau này sử dụng biến này trong project, thay vì code cứng cái xâu vào project
    + theme: thiết đặt màu sắc chủ đạo, màu sắc phụ, hay default theme cho 1 element trong project đó. Ngoài ra còn có 2 file riêng là dark theme và light theme.
    + mipmap: Icon của app trên điện thoại
    + font: lưu font sử dụng trên project
    + etc
### Gradle
- Gradle là một tool để quản lý project và build Java được Android sử dụng
- Có hai file quan trọng nhất:
    + build gradle Project: Tạm thời em chỉ sử dụng để: Thêm các source repo: Google, Maven và định nghĩa một số biến để lưu version (ví dụ room_version = "2.4.2)
    + build gradle App: 
        * chứa config của Project: minimum sdk, target sdk, tên app, tên version
        * các tính năng: proguard, viewbinding
        * dependencies: Các thư viện ngoài (trên internet hoặc local) sử dụng trong project

## Layout
### View
View là tất cả những thứ đập vào mắt chúng ta trên App Android. Từ button, một cái text, một cái ô nhập liệu, một hình ảnh, cho tới cả cái màn hình cũng là một View.
### GroupView 
Là nhóm các View nhỏ lại thành một nhóm để dễ quản lý hoặc muốn sắp xếp chúng theo một trật tự mong muốn.
### Các GroupView
- Linear: Các layout con sắp xếp thẳng hàng theo một cột (chiều dọc) hay một hàng (chiều ngang)
- Frame: Để hiện popup: Hiển thị một cái view con nằm chình ình trên màn hình. Chỉ chứa duy nhất 1 child
- Relative: Vị trí của child A có thể liên quan tới child B và ngược lại. Vậy nên ta mới gọi là tương đối
- Constraint: ViewGroup sắp xếp, resize child một cách cơ động.
- Coordinator: Layout cho phép ta dịch chuyển vị trí các child.
- CardView: FrameLayout + rounded corner + shadow
### View
- Button: Một cái nút
- TextView: Một cái text không thể sửa được
- EditText: Một cái text sửa được
- ImageView: Một cái View để đựng ảnh
### Other
- ScrollView: FrameLayout View dùng để cuộn content, child bên trong nó
- Include Layout: ở trong file xml: nơi mà ta muốn thêm một thành phần child vào: sử dụng tag `include`
```xml
<include
   android:layout_width="match_parent"
   android:layout_height="wrap_content"
   layout="@layout/yourlayout" />
```
- Ripple: Hiệu ứng gợn sóng
![ripple](/doc-kotlin/res/60Byk.gif)
- LayerList: Kết hợp nhiều hình khối đơn giản (shape xml) lại với nhau để tạo thành một khối phức tạp và mới mẻ.