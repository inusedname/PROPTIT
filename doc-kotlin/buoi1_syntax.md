<!-- Created Date: 2022-05-30 -->

# Giới thiệu

Kotlin là ngôn ngữ:

- Cross platform: Một code dùng cho nhiều nền tảng
- Statically typed: Kiểu dữ liệu xác định (int các thứ)
- General purpose: Đa công dụng, ta có thể viết 1 chương trình console, hay viết backend, hay viết app mobile đều được.
- Type inference: Compiler implicit suy ra kiểu dữ liệu
- Interoperability: Hoạt động song song với Java, thậm chí còn vừa dùng source kotlin vừa dùng java trong cùng 1 project. Bộ code Kotlin sẽ được compile thành các java class, sau đó chạy trên máy ảo JVM. Bên cạnh Java, Kotlin còn có thể chuyển đổi sang JS (frontend web) hay native code (phát triển app IOS, hai nền tảng chia sẻ với nhau bộ phận xử lí nghiệp vụ).

# Syntax cơ bản

## Field

- Sử dụng từ khoá val và var.
- == và ===: cái đầu tiên là by value, cái thứ 2 là by address (tức cùng địa chị, cùng 1 object)
- Unit là void trong kotlin, có thể bỏ qua (trừ lambda phải ghi rõ)
- Any là cụ của tất cả các class, cái gì cũng là any
- Nothing là một hàm mà sẽ không có return, mà chỉ có throws. Biểu diễn cho vòng lặp vô hạn || lỗi
- Khi khởi tạo, phải cung cấp cho nó hoặc là một giá trị, hoặc là kiểu dữ liệu.
- So sánh val và const: const là hard-coded, tức là phải cung cấp giá trị thật cho biến ngay trong lúc code. Val thì ta có thể gán nó bằng giá trị của một biến khác, hoặc một fun() khác có giá trị trả về.
- Nói ngắn gọn, const thuộc về compile time, val thuộc về runtime.

## Null Safety

### Nullable (?) và Non-nullable(!!)

- Dữ liệu trong kotlin được chia làm 2 loại là nullable và not-nullable. Mặc định tất cả các object trong Kotlin là not-nullable. So sánh với Java ?

- Ép một string thành nullable, chúng ta tiến hành thêm dấu hỏi chấm vào sau String?
  
  ```kt
  var s2: String? = "GeeksforGeeks"
  s2 = null // ok
  print(s2) // Compiler báo lỗi
  ```

- Non-nullable (!!): 2 tác dụng:
  
  - Nhấn mạnh rằng biến này chắc chắn không null
  
  - Suppress Warning của compiler
  
### Null safe call

- `?.doSth()` : Null check + execute if not null else return null

- `?.let { }` : Null check + exec block

- Cả hai hàm trên đều cho phép trả về
```kt
val firstName: String? = null
firstName?.let { println(it.toUpperCase()) }
```
- `?:` (Elvis Operator) Null check + if else execute
- Ví dụ:
```kt
fun strlen1(str: String?) = str?.length
fun strlen2(str: String) = str.length
fun elvis(str: String?) = str?.length ?: -1

fun main() {
    val x = strlen1(null)
    println(x)  // Output: null

    try {
        val y = strlen2(null)
        println(y)
    } catch (exception: Exception) {
         print(exception)
    }
    val z = elvis(null)
    println(z)   // Output: -1
}
```

## Casting
- As
    - type casting
    - `(Int)score`
    - Có khả năng lỗi khi cast nhầm
    - Safe cast: Foo as? Type
      - Foo is Type -> foo as Type
      - Foo !is Type -> null
    - Safe cast: If cannot be casted, return null
- Is: 
    - type checking, if true then auto cast
    - `instanceof`
    - Hay gặp trong cấu trúc `switch case`
- Khi sử dụng một trong hai cách trên, Kotlin ngầm định tự động ép kiểu -> chỉ phải viết 1 lần
## Method
- `main()` hoặc fun main(args: Array<String>)
- Dạng đầy đủ:
```kt
fun sum (a: Int, b: Int): Int { 
    return a + b 
}
```
- Dạng rút gọn
```kt
fun sum (a: Int, b: Int) = a + b
```
- Dạng void
```kt
fun sum (a: Int, b: Int) : { 
    print (“Sum is ${a + b}”) 
}
```
- Dạng varargs
```kt
fun sum(vararg xs: Int): Int = xs.sum()
-> Array Object
```
  - Đọc thêm: Spread Operator

## Condition

- If else
- Switch case: when is...

## Iteration
- For :
```kt
for (x in intsArray) { }
for (x in 1..10) { }
for (x in 1..10 step 2) { }
for (x in 10 downTo 0 step 1 { }

// Lấy index của phần tử 
for (index in myArray.indices) { }
```
- While/do while
- Break, continue, return: 
  - Có thể thêm label @label để thực hiện ngắt trên loop đó

## Collections
-	Phân loại theo chức năng: List, Map, Set
-	Phân loại theo editable: Mutable và Immutable
-	Ví dụ: 
```kt
val numbers = mutableListOf(1, 2, 3, 4)
numbers.add(5)
numbers.removeAt(1)
numbers[0] = 0
numbers.shuffle()
println(numbers)
```

-	Set/map mặc định là LinkedHashSet. Nó sẽ lưu phần tử theo đúng thứ tự thêm vào ban đầu. HashSet thì ngược lại, thứ tự sẽ không được đảm bảo.
-	Methods
    - Collection.forEach{ it -> }
    - Collection.map { ánh xạ }: Manip dữ liệu của từng phần tử trên List gốc rồi trả về Collection manipulated. Map khác foreach ở chỗ foreach ko return gì, còn map return một collection

    - Collection.filter {condition of it}
    - Collection.sortWith(param1: , param2: ) –> {}
    - Collection.take(n: Int) : take n random elements
    - Collection.shuffle()s : xáo bài

## Java và Kotlin
-	Code kotlin có thể cùng chung project với code java và ngược lại… Có thể sự dụng 1 API java vào project Kotlin hay sử dụng Kotlin để test 1 project Java.
-	Chuyển đổi từ Java sang Kotlin:
    - Copy đoạn code Java vào Kotlin File. Intellij sẽ tự convert
- Chuyển từ Kotlin sang Java: Compile từ Kotlin sang byte code sau đó decompile về Java, tuy nhiên unreadable by human.
