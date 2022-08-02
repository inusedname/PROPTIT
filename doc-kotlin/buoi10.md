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
## Bottom Navigation
### Định nghĩa
- Là thanh điều hướng giữa các tab khác nhau, nằm ở phía dưới màn hình: ví dụ như của Zalo, của Messenger
![](/doc-kotlin/res/bot_nav_animation.gif)

### Cách sử dụng
#### B1: Thêm dependency
```groovy
// build.gradle (app)
dependencies {
    // ...
    implementation 'com.google.android.material:material:<version>'
    // ...
}
```
#### B2: Thêm BotNavView vào layout
```xml
<!-- res/layout/activity_main.xml -->
<androidx.fragment.app.FragmentContainerView
        android:id="@+id/nav_host_fragment_container"
        android:name="androidx.navigation.fragment.NavHostFragment"
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:layout_weight="1"
        app:defaultNavHost="true"
        app:navGraph="@navigation/nav_graph" />
<com.google.android.material.bottomnavigation.BottomNavigationView
      android:id="@+id/bottom_navigation"
      android:layout_width="match_parent"
      android:layout_height="wrap_content"
      app:menu="@menu/bottom_navigation_menu" />
```
#### B3: Vẽ menu cho BotNavView
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
__CHÚ Ý: SỬ DỤNG BOTTOM_NAV ĐỂ ĐIỀU HƯỚNG NHIỀU FRAGMENT TRONG MỘT ACTIVITY, CẦN ĐỂ `android:id` CỦA MENU/ITEM TRÙNG VỚI `android:id` CỦA FRAGMENT BÊN TRONG NAV GRAPH__
#### B4.1: Sử dụng onItemSelected (trường hợp đơn giản, không cần kết nối với một NavController)
```kt
BottomNavigationView.setOnNavigationItemSelectedListener { item ->
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
#### B4.2: Kết nối với NavController (trường hợp tổng quát)
```kt
// MainActivity.kt
private fun setUpBottomNav() {

    /** 
    *   Trong MainActivity, có 2 thành phần là BottomNav và một cái container.
    *   Đầu tiên là lấy ra navController của container kia bằng cú pháp dưới:
    */
    navController =
        binding.navHostFragmentContainer.getFragment<NavHostFragment>().navController
    
    // Sau đó setupWithNavController(controller) trên BotNav
    binding.bottomNavigation.setupWithNavController(navController)

    // BONUS: Đây là hàm xử lý cho phép chúng ta ẩn đi thanh BotNav trong 1 số trường hợp cụ thể
    navController.addOnDestinationChangedListener { _, destination, _ ->
        if (destination.id == R.id.editUserFragment) {
            binding.bottomNavigation.visibility = View.GONE
        } else {
            binding.bottomNavigation.visibility = View.VISIBLE
        }
    }
}

// Ta có thể đặt title cho AppBar bằng label được cung cấp bên trong file Nav Graph thông qua cách sau
private fun setUpAppBar() {
    setupActionBarWithNavController(
        navController,
        // thêm một ý nhỏ là khi chuyển sang Item mới, sẽ xuất hiện một nút Back đầu thanh AppBar, để loại bỏ nó ta sẽ thêm vào một AppBarConfig:
        AppBarConfiguration(
            setOf(
                R.id.homeFragment,
                R.id.playFragment,
                R.id.settingFragment,
                R.id.editUserFragment
            )
        )
    )
}
```
#### BONUS: Chỉnh màu cho BotNav
[Link](https://material.io/components/bottom-navigation/android#theming-a-bottom-navigation-bar)

## TabLayout
### Định nghĩa
- Là một UI Component giúp chia một Layout ra làm nhiều Tab. Ví dụ như là Facebook có một số Tab như News Feed, Friends, Noti...
![](/doc-kotlin/res/TabLayout-in-Android.gif)
### Tại sao sử dụng TabLayout
- Cho phép ta thêm một Tab programmatically, tức là không cần phải fixed cứng là cái TabLayout này có bao nhiêu Tab Con bên trong
- Kết hợp với một `ViewPager2`: Một cái container cung cấp animation chuyển Tab rất smooth.

### Cách sử dụng, kết hợp với ViewPager2
#### Cố định số TabItem (Fixed)
- Bên trong TabLayout có thể bao gồm nhiều TabItem:
```xml
<!-- MainActivity.xml -->
 <com.google.android.material.tabs.TabLayout
         android:layout_height="wrap_content"
         android:layout_width="match_parent">

     <com.google.android.material.tabs.TabItem
             android:text="@string/tab_text"/>

     <com.google.android.material.tabs.TabItem
             android:icon="@drawable/ic_android"/>

 </com.google.android.material.tabs.TabLayout>
```
#### Không cố định (Non-fixed)
#### B1: Thêm TabLayout và ViewPager2 vào file layout
```xml
<!-- fragment_play.xml -->
<LinearLayout
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">

    <com.google.android.material.tabs.TabLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"/>

    <androidx.viewpager2.widget.ViewPager2
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:layout_weight="1" />

</LinearLayout>
```
#### B2: Viết Adapter quản lý TabLayout này
```kt
// PlayFragment.kt
class PlayFragmentAdapter(fragment: Fragment) : FragmentStateAdapter(fragment) {
        override fun getItemCount(): Int = 2

        override fun createFragment(position: Int): Fragment {
            return when (position) {
                0 -> FavoriteFragment()
                1 -> ...
                2 -> ...
                else -> MyMusicFragment()
            }
        }
    }
```
#### B3: Liên kết Adapter với ViewPager, liên kết TabLayout với ViewPager
```kt
// PlayFragment.kt
override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        linkViewPagerWithTabLayout()
    }

    private fun linkViewPagerWithTabLayout() {
        binding.viewPager.adapter = PlayFragmentAdapter(this)

        // Sử dụng TabLayoutMediator để kết nối 2 thằng với nhau
        TabLayoutMediator(binding.tabLayout, binding.viewPager) { tab, position ->
            when (position) {
                0 -> tab.text = "Favourite"
                else -> tab.text = "My Music"
            }
        }.attach()
    }
}
```
### Chú ý:
- Số lượng TabItem chỉ nên từ 3 - 5 tab
## ViewPager2
### Định nghĩa:
- Là một ViewGroup giúp chúng ta kéo qua kéo lại giữa các page. Nó sử dụng một RecycleView.Adapter để xử lý tab hiện lên màn hình.
![](/doc-kotlin/res/030d43f6-ed6c-4f49-a2f4-abd86f015da1.gif)
### Tại sao sử dụng ViewPager2
Điểm mạnh của nó so với phiên bản 1:
- Hỗ trợ bố cục right to left (RTL)
- Hỗ trợ bố trí theo chiều dọc (cuộn theo chiều dọc)
- Sự kiện PageChangeListener tốt hơn
- Đổi từ `PageAdapter` sang `RecyclerView.Adapter`
- Đổi từ `FragmentStateFragmentAdapter` sang `FragmentStateAdapter`
- Đổi từ `registerOnPageChangeCallback` sang `addPageChangeListener`
### Cách sử dụng cùng với TabLayout:
Xem [Cách sử dụng TabLayout kết hợp với ViewPager2](#cách-sử-dụng-kết-hợp-với-viewpager2)