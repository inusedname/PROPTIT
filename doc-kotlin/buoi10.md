# Navigation
> Nội dung cần nắm:
    - Navigation (Navigation graph, buttom navigation, ...)\
    - TabLayout, ViewPager2

## Navigation component
- Android Navigation component là thư viện các component cho phép chúng ta đơn giản hoá quá trình điều hướng giữa các fragment
- Thành phần chính:
    + `Nav Graph`: Là một đồ thị bao gồm các địa điểm (navigation destination) và con đường giữa các cặp đỉnh (navigation action)
    + `NavHost`: Là một container trống: chứa một destination và action trong Nav Graph 
    + `NavController`: Là người quản lý việc điều hướng bên trong 1 `NavHost`.
- Khi người dùng tương tác với UI, `NavController` sẽ nhận lệnh (và một số thông tin kèm theo) và thực hiện điều hướng sang một __Nav Destination__ khác.
- Tác dụng của Navigation Component:
    1. Xử lý các fragment transaction
    2. Đảm bảo nút Up và Back hoạt động đúng như ý muốn người dùng
    3. Hệ thống hoá các transition/animation
    4. Deep linking
    5. Bao gồm một số UI component đặc biệt: `NavDrawer` hoặc `BottomNav`
    6. SafeArgs: Type safety khi chuyển dữ liệu qua lại
    7. Hỗ trợ ViewModel: Một design pattern rất mạnh, đóng vai trò quản lý các xử lý logic bên trong Activity.

### Getting Started

1. Thêm dependency: 
Scope: `build.gradle (App)`
```groovy
dependencies {
  def nav_version = "2.5.1"

  // Java language implementation
  implementation "androidx.navigation:navigation-fragment:$nav_version"
  implementation "androidx.navigation:navigation-ui:$nav_version"

  // Kotlin
  implementation "androidx.navigation:navigation-fragment-ktx:$nav_version"
  implementation "androidx.navigation:navigation-ui-ktx:$nav_version"
```

2. Thêm vào NavGraph
- Tại thư mục `res`, Chọn `New` / `Android Resource File`
- Điền tên: nav_graph
- Trong `Resource Type`, chọn `Navigation`
- Giao diện của NavGraph
![](/doc-kotlin/res/nav-editor-2x.png)
    (1): Các Navigation Destination, trong đó có 1 các được đánh dấu là START
    (2): GraphEditor: Minh hoạ các destination và quan hệ giữa chúng (Action)
    (3): Attributes: Hiển thị các thuộc tính của Destination/Action

3. Thêm NavHost vào Layout của Activity
```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <androidx.appcompat.widget.Toolbar
        .../>

    <androidx.fragment.app.FragmentContainerView
        android:id="@+id/nav_host_fragment"
            android:name="androidx.navigation.fragment.NavHostFragment"
        android:layout_width="0dp"
        android:layout_height="0dp"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintBottom_toBottomOf="parent"

            app:defaultNavHost="true"
            app:navGraph="@navigation/nav_graph" />

    <com.google.android.material.bottomnavigation.BottomNavigationView
        .../>

</androidx.constraintlayout.widget.ConstraintLayout>
```
- Chúng ta vẫn sử dụng một FragmentContainerView như mọi khi làm việc với Fragment, tuy nhiên cần chú ý về 3 thuộc tính mới:
    + `android:name`: Tên class sử dụng cho NavHost này, trong trường hợp này, ta sử dụng class `androidx.navigation.fragment.NavHostFragment`
    + `app:navGraph`: Liên kết NavHost này cho Nav Graph nào, ở đây là: `navigation/nav_graph`
    + `app:defaultNavHost="true"`: thuộc tính này can thiệp vào nút Back trên điện thoại, không cho nó hoạt động như bình thường nữa. Tức là bình thường ấn back thì nó sẽ không quay về fragment trước, mà nó quay về Activity trước. 

4. Thêm fragment vào NavGraph:
```xml
<?xml version="1.0" encoding="utf-8"?>
<navigation xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    xmlns:android="http://schemas.android.com/apk/res/android"
    app:startDestination="@id/blankFragment">
    <fragment
        android:id="@+id/blankFragment"
        android:name="com.example.cashdog.cashdog.BlankFragment"
        android:label="@string/label_blank"
        tools:layout="@layout/fragment_blank" />
</navigation>
```
- Chú ý một số thuộc tính:
    + `name`: tên class của Fragment
    + `label`: label cho fragment này, khi kết hợp với 1 bottomNav chẳng hạn thì nó sẽ dùng luôn cái label này

5. Thêm action giữa hai fragment
- Cách 1 là dùng kéo thả giữa 2 fragment: Click chọn 1 Destination có trên màn hình, nó sẽ hiện ra một cái chấm tròn ở phía mạn phải, cầm kéo nó về cái destination bạn mong muốn:
![](/doc-kotlin/res/navigation-actioncircle_2x.png)
- Cách 2 là sửa trực tiếp trên XML:
```xml
<fragment
        android:id="@+id/blankFragment"
        android:name="com.example.cashdog.cashdog.BlankFragment"
        android:label="@string/label_blank"
        tools:layout="@layout/fragment_blank" >
        <action
            android:id="@+id/action_blankFragment_to_blankFragment2"
            app:destination="@id/blankFragment2" />
    </fragment>
```
- Thuộc tính id: Tên của action này
- Thuộc tính destination: Đích đến của action này, đương nhiên điểm khởi hành sẽ là fragment chứa action đó.

## [Điều hướng bằng Navigation Component](https://developer.android.com/guide/navigation/navigation-navigate)
- Trước hết thì chúng ta phải get instance NavController bằng 1 trong 3 cách sau:
```kt
Fragment.findNavController()
View.findNavController()
Activity.findNavController(viewId: Int)
```
- SafeArgs: tạm thời bỏ qua, sẽ nhắc đến sau.
- DeepLinkRequest sử dụng Navigation: cũng tạm thời bỏ qua
### Navigate bằng ID
```kt
viewTransactionsButton.setOnClickListener { view ->
   view.findNavController().navigate(R.id.viewTransactionsAction)
}
```
[Bonus](https://developer.android.com/guide/navigation/navigation-navigate#navoptions): Khi khai báo một `<action>` trong NavGraph, một `NavAction` sẽ được sinh ra và nó bao gồm các thuộc tính:
- Destination: Đích đến của action
- Default Args: là 1 bundle chứa các các argument default (nếu được cung cấp)
- `NavOptions`: là một thành phần chứa các cái cài đặt mà chúng ta muốn áp dụng cho `NavAction` này, ví dụ như: 
`enterAnim`, `exitAnim`: Animation khi chúng ta chúng ta bắt đầu Action và khi kết thúc Action (tương ứng với khi bắt đầu chuyển frag và tới gần khi kết thúc chuyển frag), `popUpToId`...
### Navigation và Backstack
- Việc chuyển qua chuyển lại giữa các destination, đương nhiên sẽ được quản lý bởi Android thông qua 1 backstack. 
- Destination đầu tiên được khởi tạo trong `NavHost` sẽ được tự động đặt vào trong stack khi mở app. Các destination sau, cứ mỗi cái được thêm thì sẽ được cho vào đỉnh stack. 
- Ấn `Back` (nút vật lý/ảo của Android) hay `Up` (nút back của riêng app, nằm ở top-left) sẽ gọi `NavController.navigateUp()` và `NavController.popBackStack()` sẽ pop cái đỉnh của stack ra.
- `NavController.popBackStack()` trả về Boolean cho biết việc pop đỉnh có đc thực hiện thành công hay không. Đôi lúc nó sẽ là false, ví dụ như khi chúng ta ấn Back tại Start Destination. Ta sẽ cần phải sử dụng finish khi này:
```kt
if (!navController.popBackStack()) {
    // Call finish() on your Activity
    finish()
}
```
- popUpTo và popUpToInclusive: 
    + Khi cần pop nhiều hơn là 1 destination thì sao ? Ví dụ sau khi người dùng login thành công, chúng ta cần phải pop toàn bộ các destination liên quan tới việc login, không cho phép người dùng back về nữa.
    + Sử dụng: `app:popUpTo` để set destination mà ta cần giữ lại, và xoá đi hết tất cả các destination từ nó trở đi. 
    + Nếu muốn xoá triệt để cả cái destination được sd ở `popUpTo`, gán thuộc tính: `app:popUpToInclusive="true"`
    + Ví dụ:
    ![](/doc-kotlin/res/navigation-getting-started-pop.png)
    + Flow: A -> B -> C -> A
    + Tại C chúng ta implement Action như sau: 
    ```xml
    <action
        android:id="@+id/action_c_to_a"
        app:destination="@id/a"
        app:popUpTo="@+id/a"
        app:popUpToInclusive="true"/>
    ```
    + Với popUpTo chúng ta đã tiến hành xoá B và C, đồng thời còn xoá luôn cả A
    + Nếu ở đây chúng ta không `popUpToInclusive="true"`, sẽ tồn tại tới 2 instance A trong BackStack.
### Bottom Navigation
- Là cái thanh điều hướng giữa các tab khác nhau: ví dụ như của Zalo, của Messenger
- Bước 1: Thêm dependency (do đang sử dụng MaterialComponent)
```groovy
// build.gradle (app)
dependencies {
    // ...
    implementation 'com.google.android.material:material:<version>'
    // ...
}
```
- Bước 2: Thêm BotNavView vào Activity layout
```xml
<!-- res/layout/activity_main.xml -->
<com.google.android.material.bottomnavigation.BottomNavigationView
      android:id="@+id/bottom_navigation"
      android:layout_width="match_parent"
      android:layout_height="wrap_content"
      app:menu="@menu/bottom_navigation_menu" />
```
- Bước 3: Vẽ menu cho BotNavView:
```xml
<!-- res/menu/bottom_navigation_menu.xml -->
<menu xmlns:android="http://schemas.android.com/apk/res/android">
  <item
      android:id="@+id/page_1"
      android:enabled="true"
      android:icon="@drawable/icon_1"
      android:title="@string/text_label_1"/>
  <item
      android:id="@+id/page_2"
      android:enabled="true"
      android:icon="@drawable/icon_2"
      android:title="@string/text_label_2"/>
</menu>
```
- Bước 4: Viết logic cho BotNavView:
```kt
BottomNavigationView.OnNavigationItemSelectedListener { item ->
    when(item.itemId) {
        R.id.item1 -> {
            // Respond to navigation item 1 click
            true
        }
        R.id.item2 -> {
            // Respond to navigation item 2 click
            true
        }
        else -> false
    }
}
```
Ngoài ra khi reselect: có `setOnNavigationItemReselectedListener`
- Bước 4+: Chỉnh màu cho BotNav
```xml
<style name="Widget.App.BottomNavigationView" parent="Widget.MaterialComponents.BottomNavigationView.Colored">
    <item name="materialThemeOverlay">@style/ThemeOverlay.App.BottomNavigationView</item>
</style>

<style name="ThemeOverlay.App.BottomNavigationView" parent="">
    <item name="colorPrimary">@color/shrine_pink_100</item>
    <item name="colorOnPrimary">@color/shrine_pink_900</item>
</style>
```
```xml
<com.google.android.material.bottomnavigation.BottomNavigationView
    ...
    style="@style/Widget.App.BottomNavigationView"
/>
```
## TabLayout

## ViewPager