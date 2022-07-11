# Buổi 4: Generic and Scope Funtion

> Các nội dung cần nắm:
    - Generic là gì? Dùng khi nào? Tại sao phải dùng generic?
    - Scope function là gì? Có mấy loại scope function? Phân biệt các loại scope function.
    - Tại sao cần dùng scope function.

## Generic

Generic theo từ điển là:
> "Thứ chung chung đều có ở mọi thành phần của một tập thể"

- Generic trong lập trình, hay cụ thể là trong Kotlin là tạo ra một công thức và sử dụng nó cho nhiều kiểu dữ liệu (hướng đối tượng và nguyên thuỷ)
- Tại thời điểm viết generic, chúng ta không biết 
class hay kiểu dữ liệu của tham số (hàm) là gì. Chỉ tới khi nó được implemented (gọi || khởi tạo) ta mới biết.

### Generic trong Kotlin

Thêm đằng sau tên class một `<T1, T2, ...>`: Type Parameters
```kt
class Box<T>(t: T) {
    var value = t
}
```
Khởi tạo đối tượng:
```kt
val box: Box<Int> = Box<Int>(1)
// ngắn hơn là:
val box = Box(1) // 1 là Int, trình biên dịch sẽ tự suy ra được đó là Box<Int>
```
`<Int>` : Type Argument
### Wildcard trong Java:
- Trong Java generic, `List<A>` và `List<B>` không liên quan tới nhau (đã bị tham số hoá). Nhưng trong thực tế `List<String>` có thể là con của `List<Object>`.
- Cụ thể  khi ta muốn `addAll(List<String>)` trên List\<Object>, Java sẽ không cho phép điều đó.
- Giải pháp cho việc này là sử dụng wildcard: "Tôi muốn `những subtype của <T> thay vì <T>`"
```java
Stack<Number> numberStack = new Stack<Number>();
Iterable<Integer> integers = ... ;
// Integer là con của Number
numberStack.pushAll(integers);

pushAll(Iterable<? extends E> src) {
       for (E e : src)
           push(e);
}
```
- Ngược lại, "tôi muốn `những supertype của <T> thay vì <T>`"
```java
Stack<Number> numberStack = new Stack<Number>();
Collection<Object> objects = ... ;
// Object có thể là Int, Float, String, Class nào đó...
numberStack.popAll(objects);

popAll(Collection<? super E> dst) {
       while (!isEmpty())
           dst.add(pop());
}
```
- Quy tắc PECS: Producer-Extends, Consumer-Super
- Cái nào mà là đứa to nhất, sinh ra nhiều cái thì nhớ dùng extend wildcard lên nó. Ngược lại, đứa nào là đứa sinh sau, đứa cụ thể thì để super wildcard lên nó

### Producer Consumer Design Pattern
- Trong thực tế: Producer là nhà sản xuất, còn consummer là người tiêu dùng.
- Ghi nhớ là producer có thể là bất cứ ai (chứ không phải là người to nhất)
- Trong lập trình: lấy ví dụ như request tới server: Client (My browser) là Producer - Sản xuất ra cái request đấy, Server là Consumer - xử lý cái request đấy

### It's Kotlin time !
- Từ khoá `out`: `<T>` được tạo ra bởi một thành phần của class (produced/returned). 
- Từ khoá `in`: `<T>` được sử dụng bởi một thành phần của class (consumed/used).
- Đối với out thì không thể tham gia vào bất cứ một fun nào của class đó (không thể bị consumed).
- Đối với in thì không thể là trả về của một thành phần nào (không thể được produced)
Ví dụ:
```kt
interface Source<out T> {
    fun nextT(): T
}

interface Source<in T> {
    fun doSth(t: T) : Int // T ở đây có mỗi việc là tham số
}
```
- Type projections:
```kt
fun copy(from: Array<Any>, to: Array<Any>) {
    assert(from.size == to.size)
    for (i in from.indices)
        to[i] = from[i]
}
val ints: Array<Int> = arrayOf(1, 2, 3)
val any = Array<Any>(3) { "" }
copy(ints, any)
//   ^ Lỗi: type is Array<Int> but Array<Any> was expected
```
Ta nghĩ đến `from: Array<? extend Any>` như Java. Nhưng ở đây chúng tôi không làm thế: `from: Array<out Any>`
- Star-projection:
Chưa biết gì về các argument, nhưng vẫn muốn triển khai một cách an toàn.
Khó quá em chịu ạ
### Generic Function:
Ví dụ luôn:
```kt
fun <T> singletonList(item: T): List<T> {
    // ...
}

fun <T> T.basicToString(): String { // extension function
    // ...
}
```
Type param để ở sau `fun`, trước `tên fun()`

### Tại sao cần dùng Generic
Theo như [java](https://docs.oracle.com/javase/tutorial/java/generics/why.html#:~:text=Code%20that%20uses%20generics%20has,can%20be%20difficult%20to%20find.):
1. Tái sử dụng code với các input khác nhau.
2. Hạn chế phát sinh lỗi liên quan đến kiểu dữ liệu
3. Không cần cast.
4. Sử dụng khi thiết kế thuật toán (áp dụng cho 98% kiểu dữ liệu)
## Tham khảo tại:
https://romig.dev/blog/c-oop-primer-generics/
https://viblo.asia/p/su-dung-bounded-wildcard-hieu-qua-trong-java-6J3ZgkaRZmB
https://www.youtube.com/watch?v=l6zkaJFjUbM