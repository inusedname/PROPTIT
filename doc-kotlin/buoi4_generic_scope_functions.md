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
## Scope Functions
### Phần này là để làm rõ this và it, giờ hãy đi tới [scope function](#scope-function)
### Extensions trong Kotlin:
Có một class gốc (class này ta không được phép chỉnh sửa vào core (ví dụ như Int, List...) Có một cách để ta tự thêm một function riêng cho class này

```kt
fun MutableList<Int>.swap(index1: Int, index2: Int) {
    val tmp = this[index1] // 'this' corresponds to the list
    this[index1] = this[index2]
    this[index2] = tmp
}
```
- Bắt đầu bằng tên của class đã đóng, theo sau là dot và tên của function bạn muốn quy định.

- Extension có thể áp dụng cho cả function và property
```kt
val <T> List<T>.lastIndex: Int
    get() = size - 1
```
- Có thể truy cập vào các public member và internal member (nếu cùng module). Vẫn đảm bảo tính OOP.
### Receiver
Nhìn vào ví dụ trên: chính cái class đã đóng gọi là Receiver: đứa mà handle dữ liệu, nhận và xử lý dữ liệu
- Nói tóm lại: Một class nào đó là receiver khi: 1. ta gọi trực tiếp function nằm bên trong định nghĩa class. 2. Ta sử dụng extensions fun gọi từ bên ngoài.
- Cả hai cách trên đều yêu cầu chúng ta viết function riêng. Làm thế nào để biến class thành receiver mà không cần viết function: `with`
- Ví dụ:
```kt
with(aliceGreeter) {
    println("Hello again, $name!")
}
```
Tóm tắt:
- Khi gọi `someObject.someFunction()`, `someObject` là một __receiver__ tiếp nhận lời gọi function.
- Trong `someFunction`, `someObject` đã được xác định là receiver sử dụng cho `someFunction`, và có thể tham chiếu đến bằng `this`
- Khi một receiver đã được xác định, ta có thể bỏ qua `this` và truy cập tới members của nó: __implicit receiver__
- `with` function sử dụng __lambda with receiver__ để khiến receivers có mặt tại bất cứ đâu (bên trong lambda) chứ không chỉ giới hạn tại member function và extension function.
- Why are we still here? Just to suffer?
### Scope Function
- Định nghĩa: Là function cho phép ta thực thi một đoạn code trên phạm vi một object. Đoạn code được gọi là lambda expression.
```kt
Person("Alice", 20, "Amsterdam").let {
    println(it)
    it.moveTo("London")
    it.incrementAge()
    println(it)
}
```
Các scope funtion được phân loại dựa trên:
+ Trả về
+ Context của object

### Context Object: this hay it ?

```kt
val adam = Person("Adam").apply { 
    age = 20                       // same as this.age = 20
    city = "London"
}
println(adam)
```
```kt
fun getRandomInt(): Int {
    return Random.nextInt(100).also {
        writeToLog("getRandomInt() generated value $it")
        // writeRandom(it)
    }
}
// giống với
// fun writeRandom(it: Int) {
//     writeToLog("getRandomInt() generated value $it")
// }

val i = getRandomInt()
println(i)
```
- Dùng this khi: Cần thao tác với members của object: Gọi tới method, gán giá trị cho property.
- Dùng it khi: Sử dụng chính object đó như một đầu vào.
### Return Value:
Có hai kiểu trả về:
1. Không trả về: Object đã bị thay đổi
2. Trả về là kết quả lambda: lambda return gì thì trả về là cái đấy. Object vẫn bị thay đổi.
### Phân loại
#### Đọc [Extensions Function](#extensions-trong-kotlin)
| Function | Object reference | Return value | Is extension function |
|---|---|---|---|
| let | it | Lambda result | Yes |
| run | this | Lambda result | Yes |
| run | - | Lambda result | No: called without the context object |
| with | this | Lambda result | No: takes the context object as an argument. |
| apply | this | Context object | Yes |
| also | it | Context object | Yes |

- Dùng let và apply là nhiều
Áp dụng:
- Áp dụng lambda lên object!!: `let`
- Sử dụng giá trị của biểu thức là đầu vào của lambda: `let`
- Thay đổi context object: `apply`
- Thay đổi context object và có đầu ra: `run`
- Running statements where an expression is required: non-extension `run`
- Additional effects: `also`
- Sử dụng nhiều function lên object.: `with`
## Tại sao sử dụng scope funtion:
- Khi cần thực thi một số các lệnh với phạm vi là 1 object
- Tối ưu hoá code: Thay vì viết một loạt các tên biến ra thì sử dụng this hoặc it.
## Tham khảo tại:
https://romig.dev/blog/c-oop-primer-generics/\
https://viblo.asia/p/su-dung-bounded-wildcard-hieu-qua-trong-java-6J3ZgkaRZmB\
https://www.youtube.com/watch?v=l6zkaJFjUbM\
https://stackoverflow.com/questions/45875491/what-is-a-receiver-in-kotlin/45875492#45875492\

### Mới:
Type: Tên của class.
Instance là cái nằm trên bộ nhớ, object là cái nằm trên code
Cận trên của type projection:
Class x<T: Person> : T chỉ được tối đa là Person