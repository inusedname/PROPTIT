# Fragment
>   1. Nội dung buổi học:
        Fragment, vòng đời Fragment.
        Chuyển dữ liệu giữa fragment-fragment, fragment-activity
    2. Doc và bài tập
    Doc sau khi chuẩn bị gửi vào link sau (trước buổi học 10 tiếng): https://drive.google.com/.../1GxbTyZxwZJlIdQQbHRRSn0WQWOA...
    Chuẩn bị bài tập: Thiết kế 3 màn login, sign up, main như hình.
    Mô tả bài tập: 1 activity chứa 2 fragmnet (login, sign up), 1 activity main. Sau khi login thành công chuyển username sang activity main và hiển thị, sau khi đăng kí thành công chuyển username sang màn login và đợi nhập mật khẩu. Data user fix cứng dưới dạng list trong code.
    Yêu cầu bắt buộc: sử dụng FragmentTransaction để navigate giữa các fragment.

> Link tham khảo:\
    https://guides.codepath.com/android/creating-and-using-fragments#understanding-fragments
## Fragment
- Fragment là một phần diện tích của màn hình, activity được tái sử dụng. 
- Một fragment có layout, và cũng có một file class Java/Kt, nên nó rất giống với Activity
- Fragment encapsulate View và Logic, nên ta có thể bưng nó đi bất cứ đâu và tái sử dụng được. 
=> Áp dụng kiến trúc thiết kế "Hướng Fragment", ta có thể biến Activity trở thành một trạm trung chuyển dùng để điều hướng UI, là nơi trung gian để truyền dữ liệu, hiển thị fragment và goto Activity khác. 
### Fragment Lifecycle
### Sử dụng Fragment
0. Cách ít sử dụng: Nhúng cứng một fragment vào Activty: tương tự như `<include>`: dùng `<fragment>`
1. Thêm dependencies (có vẻ không cần thiết ở các bản Android mới hơn) :
```groovy
dependencies {
    def fragment_version = "1.5.0"

    // Java language implementation
    implementation "androidx.fragment:fragment:$fragment_version"
    // Kotlin
    implementation "androidx.fragment:fragment-ktx:$fragment_version"
}
```
2. Tạo một Fragment
```kt
class LoginFragment : Fragment(R.layout.fragment_login) {

}
```
3. Tạo nơi chứa Fragment bên trong Activity:
```xml
<!-- res/layout/example_activity.xml -->
<androidx.fragment.app.FragmentContainerView
    xmlns:android="http://schemas.android.com/apk/res/android"
    android:id="@+id/fragment_container_view"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:name="com.example.ExampleFragment" />
```
- Lưu ý: Thuộc tính `android:name` là để khai báo tên của Fragment đầu tiên sẽ xuất hiện khi Activity được bắt đầu
- Quy trình
    1. Activity chứa `FragmentContatinerView` được inflate() 
    2. Trong `FragmentContainerView`, Fragment trong thuộc tính `android:name` được khởi tạo 
    3.  Một `FragmentTransaction` được tạo ra để add fragment bên trên vào `FragmentManager`

### FragmentTransaction
- Khi activity đang chạy, ta có thể thêm, xoá hay thay thế một fragment trong stack fragment.
- Chúng ta sẽ sử dụng `FragmentManager` để tạo ra một hợp đồng `FragmentTransaction`. Cách để lấy `FragmentManager` như sau:
    + Nếu muốn lấy từ trong Activity: sử dụng `getSupportFragmentManager`
    + Nếu muốn lấy từ trong Fragment: sử dụng 
    `getParentFragmentManager` để lấy cái mà quản lý Fragment đó, và `getChildFragmentManager` để lấy cái mà quản lý các Fragment con nằm bên trong Fragment đó.
- Các hàm hay sử dụng:
    + add(): Thêm fragment mới vào FragManager
    + attach(): Attach lại một fragment sau khi nó bị detach() khỏi UI.
    + commit(): Submit hợp đồng Transaction này.
    + detach(): Detach fragment ra khỏi UI. Toàn bộ các View của nó(fragment bị detached) bị destroyed, tuy nhiên state của nó thì vẫn nằm trong sự quản lý của FragMananger
    + remove(): Xoá một Fragment ra khỏi FragManager
    + replace(): Xoá toàn bộ Fragment có trong FragManager và gọi add() với Fragment là tham số được truyền vào trong replace
```kt
class ExampleActivity : AppCompatActivity(R.layout.example_activity) {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        if (savedInstanceState == null) {
            supportFragmentManager.commit { // this: FragmentTransaction
                setReorderingAllowed(true)
//              ^^^ phải có
                add<ExampleFragment>(R.id.fragment_container_view)
//              Đổi sang ExampleFragment ở FragmentContainerView
            }
        }
    }
}
```
### Pass data giữa các Fragment
https://developer.android.com/guide/fragments/communicate#fragment-result
- Kể từ fragment v1.3 trở lên, `FragmentManager` sẽ implement `FragmentResultOwner`, giúp thuận tiện cho việc pass data từ frag này sang frag kia
- Giả sử A -> B, B là người đưa ra result, rồi quay lại A sẽ sử dụng result đó: 
    + A sẽ cần implement
        ```kt
        setFragmentResultListener(requestKey: String,
                                 (requestKey: String, bundle: Bundle) -> Unit
        )
        ```
    + B sẽ cần implement 
        ```kt
        setFragmentResult(requestKey: String, bundle: Bundle)
        ```
- Ngược lại ta cũng có thể chuyển dữ liệu từ A sang B bằng cách tương tự
![](/doc-kotlin/res/fragment-a-to-b.png)

### Pass data giữa Fragment và Activity
- Lần này chúng ta sẽ áp dụng `setFragmentResultListener` lên trên `FragmentManager` nằm ở Activity.
```kt
class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        supportFragmentManager
                .setFragmentResultListener("requestKey", this) { requestKey, bundle ->
            // We use a String here, but any type that can be put in a Bundle is supported
            val result = bundle.getString("bundleKey")
            // Do something with the result
        }
    }
}
```
- Chiều ngược lại: Activity ra Fragment: ta sẽ sử dụng `setFragmentResult` lên `FragmentManager`.
```kt
 supportFragmentManager
        .setFragmentResult("request", Bundle().apply { "Bruh" to 9 })
```