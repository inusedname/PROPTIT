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
    + Thông báo với điện thoại/broadcast
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