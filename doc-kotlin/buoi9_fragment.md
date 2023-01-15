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
![](/doc-kotlin/res/0EVReuq.png)
- onAttach() gọi khi Fragment liên kết với Activity.
- onCreate() gọi khi khởi tạo Fragment này.
- onCreateView() gọi khi Fragment đó bắt đầu thực hiện inflate.
- onViewCreated() gọi sau onCreateView() và root của nó phải thoả mãn non-null. Đây là lúc chúng ta thiết lập các thao tác với View: findViewById(), thêm listener...
- onActivityCreated() gọi khi Activity chứa fragment này hoàn thành việc onCreate()
- onStart() gọi khi fragment đã sẵn sàng để hiển thị trên màn hình
- onResume() - gọi để bắt đầu cho phép Fragment Interactive (thực tế thì đây là giai đoạn Android cung cấp tài nguyên nặng cho Fragment: ví dụ như định vị, sensors)
- onPause() - gọi để thu hồi các tài nguyên nặng. Các thay dổi đối với Fragment lúc này đã được submit
- onDestroyView() gọi khi View của fragment bị huỷ, nhưng fragment vẫn nằm trong FragManager.
- onDestroy() gọi khi Fragment không còn được sử dụng nữa
- onDetach() gọi khi Fragment không còn liên kết với Activity.
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
* https://developer.android.com/guide/fragments/communicate#fragment-result
* https://guides.codepath.com/android/creating-and-using-fragments#communicating-with-fragments:~:text=return%20null.-,Communicating%20with%20Fragments,-Fragments%20should%20generally
- Đầu tiên, các Fragment khuyến khích chỉ nên giao tiếp với Activity chứa nó. Tức ở đây, activity đóng vai trò chung chuyển, điều phối các fragment, điều phối dữ liệu ra, vào.
- Có 3 cách để giao tiếp giữa 1 frag và 1 activity:
1. Bundle: Activity khởi tạo fragment + argument đi kèm với nó\

- Cài đặt:
```kt
companion object {

    @JvmStatic
    fun newInstance(isMyBoolean: Boolean) = MyFragment().apply {
        arguments = Bundle().apply {
            putBoolean("REPLACE WITH A STRING CONSTANT", isMyBoolean)
        }
    }
}
```
- Khởi tạo Fragment:
```kt
val fragment = MyFragment.newInstance(false)
... // transaction stuff happening here
```

- Lấy ra argument:
```kt
private var isMyBoolean = false

override fun onAttach(context: Context?) {
    super.onAttach(context)
    arguments?.getBoolean("REPLACE WITH A STRING CONSTANT")?.let {
        isMyBoolean = it
    }
}
```
2. Methods: Activity có thể gọi một method của nó bên trong fragment
- Gọi Activity trên Fragment:
```kt
((YourActivityClassName)getActivity()).yourPublicMethod();
```
- Gọi Fragment trên Activity:
```kt
FragmentManager fm = getSupportFragmentManager();

//if you added fragment via layout xml
YourFragmentClass fragment = (YourFragmentClass)fm.findFragmentById(R.id.your_fragment_id);
fragment.yourPublicMethod();
```
3. Listener: Activity và Fragment thêm vào các Listener event thông qua Interface
```java
public class MyListFragment extends Fragment {
  // ...
  // Define the listener of the interface type
  // listener will the activity instance containing fragment
  private OnItemSelectedListener listener;
  
  // Define the events that the fragment will use to communicate
  public interface OnItemSelectedListener {
    // This can be any number of events to be sent to the activity
    public void onRssItemSelected(String link);
  }
  
  // Store the listener (activity) that will have events fired once the fragment is attached
  @Override
  public void onAttach(Context context) {
      super.onAttach(context);
      if (context instanceof OnItemSelectedListener) {
        listener = (OnItemSelectedListener) context;
      } else {
        throw new ClassCastException(context.toString()
            + " must implement MyListFragment.OnItemSelectedListener");
      }
  }
 
  // Now we can fire the event when the user selects something in the fragment
  public void onSomeClick(View v) {
     listener.onRssItemSelected("some link");
  }
}
```

```java
import androidx.appcompat.app.AppCompatActivity;

// Activity implements the fragment listener to handle events
public class RssfeedActivity extends AppCompatActivity implements MyListFragment.OnItemSelectedListener {
    // Can be any fragment, `DetailFragment` is just an example
    DetailFragment fragment;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_rssfeed);
        // Get access to the detail view fragment by id
        fragment = (DetailFragment) getSupportFragmentManager()
            .findFragmentById(R.id.detailFragment);
  }
  
  // Now we can define the action to take in the activity when the fragment event fires
  // This is implementing the `OnItemSelectedListener` interface methods
  @Override
  public void onRssItemSelected(String link) {
      if (fragment != null && fragment.isInLayout()) {
          fragment.setText(link);
      }
  }
}
```
- Ngoài ra, chúng ta còn 2 cách mới: Sử dụng FragmentManager hoặc ViewModel
### Fragment Manager
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
- Khi cần chuyển từ Activity sang Fragment và ngược lại, lần này chúng ta sẽ áp dụng `setFragmentResultListener` lên trên `FragmentManager` nằm ở Activity.
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