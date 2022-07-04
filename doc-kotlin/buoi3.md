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
    + [Getter & Setter](#getter---setter)
    + [Lateinit](#lateinit)
  * [Visibility Modifiers (hay access modifier)](#visibility-modifiers--hay-access-modifier-)
## Class

Cấu trúc hướng đối tượng trong Kotlin được định nghĩa bằng từ khoá `class`

```kt
class Person { /*...*/ }
```

## Primary Constructor

Trong Kotlin, class có thể có 1 primary constructor và có thể có nhiều hơn một secondary constructor. Nhưng mà kiểu gì cũng phải có constructor.
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

Nhận xét:
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
Nếu class có primary constructor và có thêm các secondary constructor, chúng ta __bắt buộc__ phải delegate secondary cho primary. Để giải thích về vấn đề này ta có ví dụ:
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
