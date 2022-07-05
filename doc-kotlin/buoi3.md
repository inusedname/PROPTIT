# Buổi 3: Class, Interface, Abstract Class

> Các nội dung cần nắm:\
    - Class (access modifier, property, method,...)\
    - Interface\
    - Abstract class\
    - Phân biệt Interface và Abstract class

> Table of Contents:
- [Buổi 3: Class, Interface, Abstract Class](#bu-i-3--class--interface--abstract-class)
  * [Class](#class)
  * [Primary Constructor](#primary-constructor)
  * [Init block](#init-block)
  * [Secondary Constructor:](#secondary-constructor-)
  * [Thuộc tính](#thu-c-t-nh)
    + [Khai báo một thuộc tính trong class có hai cách:](#khai-b-o-m-t-thu-c-t-nh-trong-class-c--hai-c-ch-)
    + [Method](#method)
    + [Getter & Setter](#getter---setter)
    + [Lateinit](#lateinit)
  * [Visibility Modifiers (hay access modifier)](#visibility-modifiers--hay-access-modifier-)
  * [Abstract Class](#abstract-class)
  * [Interfaces](#interfaces)
  * [So sánh Interface và Abstract Class](#so-s-nh-interface-v--abstract-class)
## Class

Cấu trúc hướng đối tượng trong Kotlin được định nghĩa bằng từ khoá `class`

```kt
class Person { /*...*/ }
```

## Primary Constructor

Trong Kotlin, class có thể có 1 primary constructor và có thể có nhiều hơn một secondary constructor. Nếu không thấy có constructor nào, Kotlin sẽ ngầm định tạo ra một constructor không tham số.
```kt
class Person constructor(firstName: String) { /*...*/ }
// hay ngắn gọn hơn là:
class Person(firstName: String) { /*...*/ }
```

Trường hợp Constructor đặc biệt:

```kt
class Person private constructor(firstName: String) { /*...*/ }
```

## Init block

Khối khởi tạo. Khối này được thực thi trên tất cả các constructor trong class.

Thứ tự ưu tiên: __Primary > Init block (nếu có) > Secondary (nếu có)__

```kt
class InitOrderDemo(name: String) {
    val firstProperty = "First property: $name".also(::println)
    
    init {
        println("First initializer block that prints $name")
    }
    
    val secondProperty = "Second property: ${name.length}".also(::println)
    
    init {
        println("Second initializer block that prints ${name.length}")
    }
}

<========================================>
First property: hello
First initializer block that prints hello
Second property: 5
Second initializer block that prints 5
```

Nhận xét (không liên quan tới ví dụ trên)
- 1 secondary và 1 init block cùng tồn tại: Khối init sẽ được thực thi trước, rồi mới đến secondary.
- 2+ init block cùng tồn tại: Thứ tự thực thi sẽ là từ trên xuống của định nghĩa class.
- 2+ secondary và 1 init: Init luôn chạy rồi sẽ đến constructor thực thi. 

## Secondary Constructor:
Đơn giản thui, đó là một `constructor` nằm trong body của class

```kt
class Person(val pets: MutableList<Pet> = mutableListOf())

class Pet {
    constructor(owner: Person) {
        owner.pets.add(this) // adds this pet to the list of its owner's pets
    }
}
```
Nếu class đã có primary constructor và có thêm các secondary constructor, chúng ta __bắt buộc__ phải delegate secondary cho primary. Để giải thích về vấn đề này ta có ví dụ:
```kt
class Rectangle(val width: Int, val height: Int) {

    constructor(size: Int) : this(size, size) // <- delegate

    val area = width * height

    init {
        println("New rectangle, $width x $height")
    }

}

val square = Rectangle(5)

- Ở đây chúng ta sử dụng secondary.
- Nhận thấy rằng primary có nhiệm vụ khai báo các properties của class, đó là 2 properties mới: width và height
- Nhiệm vụ của delegate: Delegate đảm bảo mọi thuộc tính có trong primary được gán giá trị.
```

## Thuộc tính

### Khai báo một thuộc tính trong class có hai cách:

```kt
class Student (val name: String) { // <= Cách 1
    val dob: String // <= Cách 2
}
```

- Với cách 1, primary constructor vừa đóng vai trò là định nghĩa thuộc tính, vừa đóng vai trò là setter thuộc tính.
- So sánh với các ngôn ngữ khác mà em được biết (C++, Java) thì đây là ngôn ngữ đầu tiên cho phép làm điều này (ngắn code hơn)
- Nếu không muốn tạo property `name` thì chỉ cần bỏ từ khoá `val` trong primary constructor
- Cách 2 thì đã có trong các ngôn ngữ khác

[X] Mặc định property là: `public`\
[X] Mặc định class là: `public final`\
[X] Do là `final` nên sẽ không thể kế thừa như trong Java được. Khi đó sẽ cần dùng đến từ khoá `open`, sẽ được giải thích trong phần kế thừa.

### Method
- Không khác gì các ngôn ngữ khác, cấu trúc là `special keyword` + `fun` + `tên method` + `(tham số 1..n)` + { body }
- Ví dụ:
```kt
open private fun sayHello() {
    println("Hello World")
} 
```
- Gọi tới method/property dùng dấu chấm: `object.tên_method`
### Getter & Setter

Trong các ngôn ngữ khác (C++, Java): Getter, setter là một **method** của class. Còn trong Kotlin, thuộc tính/biến có thể là return của một hàm khác <- Code ngắn gọn hơn.

```kt
class Rectangle (val width: Int, val height: Int) {
    val area: Int
        get() = this.width * this.height
}

println(Rectangle(3,4).area)
// In ra 12
// Ngôn ngữ khác là phải tạo một fun getArea() rồi gọi tới fun này
```

Một ví dụ khác
```kt
class Hmmmm {
    private var _readOnly = 3
    val readOnly                // Đây chính là getter
        get() = _readOnly
    
    // Thay đổi _readOnly gì tuỳ thích 
}

// Ở bên ngoài class thì không được phép modify _readOnly nữa, chỉ đọc
```
### Lazy
- Một thuộc tính:
    + Tốn tài nguyên - thời gian
    + Chưa cần sử dụng ngay sau khi tạo object\
    -> tức là có thể khởi tạo sau
- Cú pháp:
```kt
val name: (Any) by lazy { // khối lệnh lambda
     // giá trị
     // ví dụ như: 
     3
     "Hello"
     Rectangle(3,4)
}
```
- Lần đầu tiên gọi tới lazy, chương trình sẽ thực thi khối lệnh lambda trên và gán return của nó cho val.
- Lần thứ hai trả về val như biến thông thường.
### Lateinit 
- Một thuộc tính được tạo ra thì bắt buộc phải có giá trị cho nó trong constructor hoặc init... Nếu không thì
```kt
class Rectangle () {
    val i_dont_want_to_use_this : String
    init {
        println("I'm okay :)")
    }
}
fun main() {
	val rect = Rectangle()
}
// Property must be initialized or be abstract
```
- Vậy chưa muốn khởi tạo cho biến đó thì làm thế nào ? `lateinit var`
```kt
class Rectangle () {
    lateinit var i_dont_want_to_use_this : String
    init {
        println("I'm okay :)")
    }
}
fun main() {
	val rect = Rectangle()
// I'm okay :)
```
## Visibility Modifiers (hay access modifier)

Có 4 visibility modifiers trong Kotlin:
1. public
2. protected
3. private
4. internal

Phân loại: 
1. Những cái không phải là class member (properties và methods)\
    Example:
    ```kt
    // file name: example.kt
    package foo

    private fun foo() { ... } // visible inside example.kt

    public var bar: Int = 5 // property is visible everywhere
        private set         // setter is visible only in example.kt

    internal val baz = 6    // visible inside the same module
    protected val bruh = 3  // not avaiable - CE
    ```
2. Những cái là class member\
    Example:
    ```kt
    open class Outer {
        private val a = 1
        protected open val b = 2
        internal open val c = 3
        val d = 4  // public by default

        protected class Nested {
            public val e: Int = 5
        }
    }

    class Subclass : Outer() {
        // a is not visible
        // b, c and d are visible
        // Nested and e are visible

        override val b = 5   // 'b' is protected
        override val c = 7   // 'c' is internal
    }

    class Unrelated(o: Outer) {
        // o.a, o.b are not visible
        // o.c and o.d are visible (same module)
        // Outer.Nested is not visible, and Nested::e is not visible either
    }
    ```

## Abstract Class
- Định nghĩa: Lớp trừu tượng. Lớp sinh ra là để được kế thừa.
- Bên trong body của class này vẫn chứa các properties/methods như class bình thường, nhưng nó có thêm một số members khác, hơi _bất thường_.

```kt
abstract class Polygon {
    fun sayHello() = println("Hello")
    abstract fun draw()  // Bất thường (không có body)
}

class Rectangle : Polygon() {
    override fun draw() {
        // draw the rectangle
    }
}
```

- Các member _bất thường_, được đánh dấu với `abstract` thì các class kế thừa abstract class này __bắt buộc__ phải `override` lại member này.
- Lớp abstract sinh ra là để bị kế thừa. Member abstract sinh ra, là để bị ghi đè.

- Ngoài ra thì ta cũng có thể ghi đè một member khi class chứa nó không phải abstract, bằng từ khoá `open`:
```kt
open class Polygon {
    open fun draw() {
        // some default polygon drawing method
    }
}

abstract class WildShape : Polygon() {
    // Classes that inherit WildShape need to provide their own
    // draw method instead of using the default on Polygon
    abstract override fun draw()
}
```

## Interfaces
- Có thể hiểu rằng: 
    + Class là một bản vẽ, và kiến trúc sư có thể tạo ra nhiều ngôi nhà từ 1 bản vẽ, mỗi ngôi nhà có một số điểm khác nhau nho nhỏ. 
    + Interface là những options khách A, khách B muốn lựa chọn. Option này có thể là: có vườn thượng, có bể bơi, có thang máy...
- Định nghĩa: _Bất thường_ giống abstract class, nhưng các members đều phải là abstract.

```kt
interface MyInterface {
    val prop: Int // abstract

    val propertyWithImplementation: String
        get() = "foo"

    fun foo() {
        print(prop)
    }
}

class Child : MyInterface {
    override val prop: Int = 29
}
```
- Ở ví dụ trên ta thấy `fun foo()` có body, điều này đáng lẽ là trái với quy tắc của interface. Tuy nhiên đây là không phải là một method bình thường, nó là `default method`. Điểm khác biệt là loại method đặc biệt này không bắt buộc phải bị override.
## So sánh Interface và Abstract Class
|  | Abstract Class | Interface |
|---|---|---|
| Non-abstract Members | Có cho phép | Không cho phép |
| Đa kế thừa | Không cho phép Đa kế thừa | Cho phép đa kế thừa nhiều interfaces |
| Kế thừa từ đứa còn lại | Abstract extends được interface | Interface không extends được abstract |
| Ý nghĩa | Là một template class cho một loạt các class có chức năng tương tự nhau. 'Is-A' | Là một tính năng có thể xuất hiện ở một số các class. 'Can-do' |