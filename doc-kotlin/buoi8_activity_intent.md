# Binding - Activity - Intents
> Nội dung cần nắm
    - Binding cơ bản (findViewById, View Binding).\
    - Activity, vòng đời Activity.\
    - Implicit intent vs explicit intent.\

## Activity
> Tham khảo
    ⭐ https://developer.android.com/reference/android/app/Activity\
    ⭐ https://developer.android.com/guide/components/activities/intro-activities
- Activity là một thành phần quan trọng trong App Android mà user tương tác trên nó, và là nơi để chúng ta đặt các UI component lên trên
- Thông thường trong các chương trình functional, hàm main() sẽ khởi động, tuy nhiên đối với Android app, hàm main() sẽ được thay bằng một Activity đánh dấu là __Activity BẮT ĐẦU__
- Activity thường sẽ chiếm diện tích toàn màn hình, tuy nhiên trong 1 số trường hợp thì không. Ví dụ như khi ta ấn nút Share, một popup sẽ trượt từ đáy màn hình lên.
- Như vậy, một app sẽ có nhiều activity và chúng có thể tồn tại song song nhau. 
- Các activity có thể tương tác với nhau: activity này kích hoạt activity kia, activity này truyền input sang activity kia.

## Vòng đời của Activity
- Vòng đời của 1 activity bao gồm nhiều giai đoạn. Chúng ta sử dụng một số callBack() để thực hiện dịch chuyển giữa các activities. 
![](/doc-kotlin/res/f6b25a71cec4e401.png)
### onCreate(): Exist
- Bắt buộc phải implement callback, coi như là ngòi nổ cho activity này. Nhiệm vụ của nó là:
    + Khởi tạo mọi component thuộc activity này: các view, các biến, khởi tạo list
    + Quan trọng nhất, setContentView(): Set cho cái activity này sử dụng layout nào.
    + Sau đó, chúng ta sẽ sử dụng `findViewById(int)` để tìm kiếm các View sử dụng trong layout và thao tác trên chúng (vd: set thuộc tính, set adapter, set Click Listener...)
### onStart(): Visible
- Trước khi onStart() bắt đầu thì trên màn hình user chưa render ra gì. Bước này chính là bước cuối cùng trước khi activity bắt đầu render. 
### onResume(): Interactive - Focusing
- Trước khi onResume() bắt đầu thì người dùng chưa thể tương tác với Activity. Bước này là để Activity trở nên interactive.
### onPause(): No longer Interactive
- Activity bị lose focus và bước vào trạng thái Paused. Ví dụ: Ấn nút share, một activity khác được kích hoạt, activity cũ tạm thời bị dừng.
- Không nên sử dụng onPause() để tiến hành save dữ liệu, tạo cuộc gọi, hoặc truy vấn DB. 
- Sau khi phase __Paused__ kết thúc, nó sẽ nhảy tới __Resumed__ hoặc __Stopped__

### onStop() - Invisible
- Activity sẽ rơi vào trạng thái Invisible khi nó không còn nằm trên màn hình. Có thể là do nó đã bị (1) destroyed, (2) một activity che hoàn toàn activity đang chạy. 

### onRestart() - Re-visible
- Khi một Stopped Activity chuẩn bị Start lại. 
- Sau onRestart() luôn là onStart()
### onDestroy() - Destroy
- Callback này được gọi khi activity kết thúc vòng đời.
- Đảm bảo các tài nguyên Activity sử dụng được giải phóng

## Intents
> Tham khảo: 
    https://developer.android.com/guide/components/intents-filters\
    https://developer.android.com/reference/android/content/Intent
- Intent là một messaging object (object truyền thông tin) sử dụng để request 1 action từ component.
![](/doc-kotlin/res/intent-filters_2x.jpg)
- Có 3 use case chính:
    + Bắt đầu 1 Activity: 
        * startActivity(Intent)
        * startActivityForResult(): Bắt đầu activity và nhận về kết quả từ activity đó
    + Bắt đầu 1 service
    + Thông báo với điện thoại  /broadcast
- Thành phần chính của Intent:
    1. action: Ta muốn thực hiện hành động gì, ta muốn làm gì ?
    2. data: Ta sẽ làm việc với dữ liệu này.
- Một số ví dụ:
    + __ACTION_VIEW content://contacts/people/1__ -- Show thông tin của person có id 1
    + __ACTION_DIAL content://contacts/people/1__ -- Mở chế độ quay số điện thoại với thông tin của person có id 1
    + __ACTION_DIAL tel:123__ -- Mở chế độ quay số điện thoại với số "123"
    + __ACTION_VIEW tel:123__ -- Mở chế độ quay số điện thoại với số "123". Trong trường hợp chung chung như thế này, VIEW sẽ lựa chọn một hành động nào đó mà được coi là hợp lí nhất: ACTION_DIAL
    + __ACTION_EDIT content://contacts/people/1__ -- Sửa thông tin của person có id 1
    + __ACTION_VIEW content://contacts/people/__ -- Hiển thị một list các liên lạc trong danh bạ
    
- Bên cạnh 2 thành phần chính, các thành phần phụ là:
    > category, type, component, extras

### Phân loại Intent
__Explicit__ (tường minh/rõ ràng) và __implicit__ (ngầm định)
- Explicit là intent được cung cấp chính xác tên component/class phụ trách xử lý Intent. 
    + Thông thường thì explicit sẽ không cần thông tin cụ thể hơn (ngoài tên class), do nó chỉ có nhiệm vụ bắt đầu một activity khi người dùng tương tác. 
- Implicit là intent không chỉ đích danh một component hay class nào. Thay vì đó, nó sẽ chứa một số cờ phụ và hệ thống sẽ tự lựa ra đâu là component nên được sử dụng.
- Ví dụ cho implicit: Click vào 1 email điện thoại sẽ hiện ra một menu gồm các app Email: Gmail, Outlook...
- Explicit thì để giao tiếp trong app, implicit thì để giao tiếp giữa app này với app kia.

## Binding
### Binding cơ bản: findViewById()
(1) Trong XML - file layout: Các View, trong hầu hết mọi trường hợp, đều chứa attribute `android:id`. Attr này để chúng ta có thể sử dụng View trong file code Kotlin hoặc Java. 
(2) Trong file source Java hoặc Kotlin, sau khi setContentView(layout) trong Activity, ta có thể bắt đầu sử dụng hàm `findViewById()` để tìm và lưu lại instance đó để tiện sử dụng
- Ví dụ:
```XML
    <TextView>
        ...
        android:id='@+id/tênView 
    </TextView>
```
```kt
override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)

    val tv = findViewById(R.id.tênView)

}

```
### R.id.tênView là cái gì ?
__Q__: Tại sao chúng ta lại có một cái `R.id.tênView` ở đây, mặc dù chẳng có một class nào tên là `R` trong `src`, mà class `R` đấy Ctrl Click vào cũng chỉ đưa ta ngược trở lại file XML ?\

__A__: Trong project, có một file tên là R.java. File này ẩn ở đâu đó (em chưa tìm ra), và nó được hệ thống build của Android tự động tạo ra. Bên trong đó là toàn bộ các tham chiếu tới View/String/Layout tồn tại bên trong thư mục res.
https://stackoverflow.com/questions/49830651/what-does-r-id-myview-refer-to

Ví dụ của file R.java:
```java
public final class R {  
    public static final class attr {  
    }  
    public static final class drawable {  
        public static final int ic_launcher=0x7f020000;  
    }  
    public static final class id {  
        public static final int menu_settings=0x7f070000;  
    }  
    public static final class layout {  
        public static final int activity_main=0x7f030000;  
    }  
    public static final class menu {  
        public static final int activity_main=0x7f060000;  
    }  
    public static final class string {  
        public static final int app_name=0x7f040000;  
        public static final int hello_world=0x7f040001;  
        public static final int menu_settings=0x7f040002;  
    }  
    public static final class style {  

        public static final int AppBaseTheme=0x7f050000;  
        public static final int AppTheme=0x7f050001;  
    }  
}
```
## ViewBinding
- Đây là thành phần đầu tiên của Android Jetpack được giới thiệu - Một thư viện tiện ích do Google phát triển: (1) hạn chế code dư thừa, dài dòng, lặp lại, (2) tăng cường tính ổn định trên nhiều thiết bị, nhiều Android version.
- Ví dụ như sau
```kt
{
    val textview = findViewById(R.id.tênView)
    textview.setText("Hello World")

    // Ngắn hơn nữa thì:
    findViewById(R.id.tênView).setText("Hello World")

    // Vẫn hơi dài nhỉ, giá như:
    R.id.tênView.setText("Hello World)"
}
```
Tận dụng cái file `R.java` như đã giới thiệu ở trên, tại sao chúng ta không, khởi tạo hết các object TextView, LinearLayout ngay từ đầu nhỉ, xong rồi mỗi lần muốn dùng chỉ việc gọi tới cái object đó thôi :v 

viewBinding ra đời.

### Bước 1: Enable View Binding
Tại `build.gradle (Module)`:
```xml
android {
    ...
    buildFeatures {
        viewBinding true
    }
}
```

### Bước 2: XML
```xml
<LinearLayout ... >
    <TextView android:id="@+id/name" />
    <ImageView android:cropToPadding="true" />
    <Button android:id="@+id/button"
        android:background="@drawable/rounded_button" />
</LinearLayout>
```
Ở đây có cái `TextView` và `Button` thì có attr id, còn `ImageView` thì không. Một file có tên là `tênXmlBinding` được tự động tạo ra, và bên trong nó là object `TextView` có tên là name và `Button` có tên là button
![](/doc-kotlin/res/viewBinding.png)
> Hình minh hoạ, không giống với ví dụ.

### Bước 3: Sử dụng viewBinding
- Thêm một số dòng sau vào Activity:
```kt
class MainActivity : AppCompatActivity() {
    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
    }
}
```
Xong rồi, giờ nếu mà muốn dùng một cái View nào thì cứ `binding.tênView` là xong:
![](/doc-kotlin/res/Screenshot%202022-07-26%20004816.png)
### Điểm lợi
- Tiện, nhanh
- findView phải tìm kiếm trong cây view nên sẽ tốn thời gian, trong khi đó thì binding sẽ là tham chiếu trực tiếp tới file Binding của Activity.
- Null safety: Do binding lưu trực tiếp tham chiếu tới view đó, nên không lo là view đó bị null. 
- Type safety: XML bảo nó thuộc class/type nào thì vào binding nó sẽ y hệt, nên không lo bị sai class.
### Điểm hại:
- Tất cả các view đều được gen
Nhiều file hơn -> App nặng hơn -> Build lâu hơn.
Tuy nhiên đấy là với project rất lớn (1k layout+) chứ app bình thường thì không ăn thua mấy.
### Coding convention
- Nên đặt tên View `@+id/tv_tên_view` để lúc dùng View Binding thì Object sinh ra sẽ có tên là `TextView tênView`