# Buổi 5: Object và Callback

> Các nội dung cần nắm:
    - Các loại object.
    - Callback là gì? Tại sao phải dùng callback.
    - Nêu ưu nhược điểm của callback
    - Annonymous function
    - Lambda expression
    - Functor
    - Callback

## Các loại Object

Khi ta muốn sử dụng một object có một chút thay đổi so với class gốc, và chỉ sử dụng 1 lần (không cần thiết phải tạo ra hẳn 1 bản vẽ cho nó). Kotlin đã có 2 khái niệm cho nó __object expression__ (biểu thức object) và __object declaration__ (khai báo object)

## Object Expression

- Một object là một thứ bao gồm các thông tin nó chứa (thuộc tính) và các cách để giao tiếp với thông tin đó (phương thức)
- Từ khoá `object` cho phép ta tạo ra một object mà không cần phải thiết kế class cho nó
- Do object không được tạo ra bởi 1 bản vẽ, do đó nó không có tên. Ta có thể gọi đây là anonymous object.
Có nhiều cách khởi tạo một object mới:
### Object không có kế thừa
```kt
val helloWorld = object {
    val hello = "Hello"
    val world = "World"
    // object expressions extend Any, so `override` is required on `toString()`
    override fun toString() = "$hello $world"
}
//#
//==================== giống với ====================//
//#
class Example (val hello: String, val world: String) : Any() {
    override fun toString() = "$hello $world"
}
val helloWorld = Example("Hello", "World")
```

### Object được kế thừa
```kt
window.addMouseListener(object : MouseAdapter() {
                        ^^^^^^ 
                        object mới có cha là MouseAdapater()

    // Kế thừa các phương thức ảo của lớp cha                    
    override fun mouseClicked(e: MouseEvent) { /*...*/ }

    override fun mouseEntered(e: MouseEvent) { /*...*/ }
})
```

### Trả về của Object
- Tóm tắt lại: Object nằm bên trong class:
    + Nếu được khai báo cùng từ khoá `private` và không `inline` thì được phép truy cập vào các member của object đó
    + Các trường hợp khác thì không được phép.

## Object Declarion
- Chúng ta có thể tạo ra một instance object ở cấp độ cao nhất của chương trình (không cần khai báo fun, khai báo class). 
- Coi như là Singleton
```kt
object C {
    fun sayHello() = println("Hello")
}

fun main() {
    C.sayHello()
}
```
### Làm rõ hai loại object trong Kotlin
- Object Expression bản chất nó là một biểu thức - người ta cần trả về của nó. 
- Object Declaration thì không trả về thứ gì - nó tạo ra một instance object trong bộ nhớ.
- Do đó, biểu thức được khởi tạo và thực thi ngay khi ta khởi tạo object đó. Khai báo object thì là kiểu lazyinit, tức khi nào cần truy cập tới thì mới khởi tạo. 

### Companion Object
- Từ khoá `static` trong Kotlin được sử dụng bằng `companion object`: các object này có thể truy cập thẳng từ `TênClass.TênMember` mà không phải khởi tạo một object val... gì đó như bình thường.
- Một class chỉ có 1 com. object. Com object thì có thể private.
## Callback
- Các khái niệm: 
    + Hàm trong Kotlin có thể sử dụng như một biến/tham số.
    + Function Type: Là biến/tham số kiểu function
    + Higher order function: Function có input là một funtion, hoặc chính nó trả về một function.
    + Literal: Nó là một giá trị cố định được khai báo trong lúc code (giống const)
    ```kt
    val a = 5
            ^ 5 là literal
    val f = {a: Int -> a + 1}
            ^^^^^^^^^^^^^^^^^ 
            Đây cũng là literal
    ```

### Function Type
Có nhiều cách để khai báo function type, đây là một số cách tiêu biểu:
- Sử dụng lambda expression
```kt
val sum : (Int, Int) -> Int = { a, b -> a + b }
// hoặc
val sub = {a: Int, b: Int -> a - b}
```
- Sử dụng anonymous function
```kt
val sub = fun(a: Int, b: Int) = a - b
```
- Gán trực tiếp bằng một hàm có sẵn:
```kt
val intPlus: Int.(Int) -> Int = Int::plus
```
### Lambda Expression
Cấu trúc đầy đủ của 1 lambda expression:
```kt
val sum: (Int, Int) -> Int = { x: Int, y: Int -> x + y }
                                                ^ body from here
```
1. Lambda được bao quanh bởi cặp `{}`
2. Tên nhận dạng các tham số nằm trong cặp `{}`. Có thể đi kèm với một số type annotation.
3. Body nằm sau dấu `->` (trong cặp `{}`)
4. Nếu kiểu trả về không phải Unit, giá trị trả về mặc định sẽ là dòng cuối cùng của body

- Nếu tham số cuối cùng của hàm là một function type, chúng ta có thể tách riêng argument đó để ra bên ngoài 
```kt
// bình thường là:
val hi = doSth(1, {a, b -> a + b} )
// nên là:
val hi = doSth(1) { a, b -> a + b }
```
- Nếu mà lambda chỉ có duy nhất 1 tham số, thì mặc định tên của nó sẽ là it
- Nếu như một cái argument của lambda không cần sử dụng tới: thay nó bằng dấu `_`
```kt
map.forEach { (_, value) -> println("$value!") }
```

### Anonymous Function
- Giống hệt funtion thường, mỗi tội không có tên:
```kt
fun(x: Int, y: Int): Int = x + y
```

### Funtion Literal sử dụng Receiver
```kt
val sum: Int.(Int) -> Int = { // this: Int, it: Int
    plus(it)
}
println(5.sum(3))
```
- Nhận xét:
    + Tham số của function type có điểm khác: Không phải là `(Int, Int)` mà là `Int.(Int)`
    + Int1 là receiver, tức là thứ sẽ sử dụng funtion này (nhớ lại extension function)
    + Int2 là argument, tức là tham số như bình thường
    + this là gì ? this là bản thế, cái thứ đang thực thi hàm này, ở đây ta nghĩ ngay this chính là Int1 (receiver)
    + it là gì ? it là tham số truyền vào (do ở đây có mỗi một tham số nên được phép dùng it)

- Thử thay `it` bằng `this` ở trong body:
```kt
plus(this)
```
-> giờ nó không in ra 8 nữa mà in ra 10.

### Giờ mới đến Callback 🤔
Callback là:
- Sử dụng một `funtion type` là một tham số (gọi là hàm worker). Cũng có nghĩa đứa callback (từ giờ gọi là hàm chủ) là higher order function.
- Ở trong body của hàm chủ, hàm chủ sẽ gọi tới hàm worker (ở đây hàm chủ còn chẳng biết hàm worker làm gì, chỉ biết tên nó là name, các tham số truyền vào của nó là gì gì đó và giá trị trả về của nó là gì gì đó)
- Hàm chủ đang thực thi thì sẽ tạm dừng rồi nhảy tới hàm worker, đợi nó làm việc xong, trả về một kết quả rồi hàm chủ lại tiếp tục làm việc tiếp (với kết quả đã nhận được).

```kt
fun manipInt(
    x: Int,
    f: (Int) -> Int
): Int {
    return f(x)
}

fun main() {
    val addOne = { x: Int -> x + 1 }
    val square = { x: Int -> x * x }

    val num = 5
    println("Increase 1 of $num: " + manipInt(num, addOne))
    println("Square of $num: " + manipInt(num, square))

    // OUTPUT
    // Increase 1 of 5: 6
    // Square of 5: 25
}
```
- Lợi ích của callback:
    + Tái sử dụng code, hạn chế lỗi: Có thể tái sử dụng lại code chỉ cần thay đổi lại hàm worker.
    + Tăng cường tính bao đóng của OOP cho hàm worker

- Điểm trừ của callback:
    + Chương trình chính phải dừng lại đợi chương trình con. Nếu hàm callback mất thời gian sẽ ảnh hưởng tới hiệu suất chương trình
    + Trở nên rất loạn khi sử dụng đa luồng bất đồng bộ.
    + Khó debug, khó kiểm soát lỗi

### Đọc thêm: Callback trong Java
- Java không có kiểu function là một object, và một số ngôn ngữ khác cũng thế. Vậy thì làm thế nào để callback, hay làm thế nào để nhét một function vào argument ?
- Các khái niệm:
    + Funtor: kết hợp của function và object (cái mà Kotlin có, Java không có)
    + Functional Interface: là một interface (để ghi đè), đương nhiên rồi, và nhiệm vụ của nó là khéo léo biến một function thành object
```java
interface ManipInt {
    int manip(int x);
}
public class Main {
    static int map(int x, ManipInt f) {
        return f.manip(x);
    }
    public static void main(String[] args) {
        ManipInt addOne = x -> x + 1;
        ManipInt square = x -> x * x;
        int num = 5;
        System.out.printf("Increase 1 of %d is %d\n", num, map(num, addOne));
        System.out.printf("Square of %d is %d\n", num, map(num, square));
    }
}
```
Ngôn ngữ nào cũng làm được thế này hết.
