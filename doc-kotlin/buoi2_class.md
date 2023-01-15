<!-- Created Date: 2022-06-07 -->
# Class Thường
```kt
class Person {
    properties;
    methods;
}
```
 

## Constructor
```kt
class Person(name: String) {
    private val name = name;
}
```
Từ từ đã...
```kt
class Person(private val name: String) {
    // quá khéttt
}
```
## Secondary Constructor
```kt
class Person(val name: String, val age: Int?) {
    constructor(name: String) : this(name, null) {

    }
}
```
## Init block
- Khối khởi tạo
```kt
class Constructors {
    init {
        println("Init block")
    }
​
    constructor(i: Int) {
        println("Constructor $i")
    }
}
=================================
Init block
Constructor 1
```
-	Thông qua một vài trường hợp test nhận thầy rằng:
    - `Độ ưu tiên`: Primary > Init blocks > Secondary
    - `2+ init block cùng tồn tại`: Thứ tự thực thi sẽ là từ trên xuống của định nghĩa class. 
    - `Secondary và init`: Các Khối init sẽ được thực thi trước, rồi mới đến secondary.
- [CODING CONVENTIONS]: Trailing comma
    - Nên tạo thói quen thêm dấu phẩy vào phần tử / tham số cuối cùng của cặp ngoặc tròn

# Các class khác
## Data Class: 
- Class chỉ để lưu data
- Tính chất:
    - Phải có primary constructor.
    - Các tham số trong constructor phải đi kèm với val hoặc var.
    - Không được phép là abstract, inner, open hay sealed
    - Được tự động cấp cho các method sau, có thể override trong body:
        - Equals() / hashCode()
        - toString ()
        - copy () : copy phần tử gốc, có thể thay đổi 1 số property: 
        - componentN funtions: rã một số thuộc tính của data class ra thành các biến đơn (giống python)

## Nested, inner class:
- Giống nhau: Lớp này nằm trong body lớp kia.
- Khác nhau: Nested ko được truy cập vào prop của cha, inner thì được
- Lớp được đánh dấu là inner thì nó sẽ lưu một tham chiếu tới lớp cha của nó, nên nó có khả năng truy cập vào các phần tử thuộc lớp cha. 
- So sánh inner và sealed: tất cả các subclass đều phải kế thừa từ thằng bố, còn inner thì không
## Object
- Muốn tạo ra một object, chỉ sử dụng 1 lần, không muốn tạo hẳn một biến (anonymous), ví dụ như một listener
-	Cách sử dụng: object : class_gốc() { } 
## Enum class: 
- Kiểu dữ liệu do người dùng tự định nghĩa.
- Các giá trị possible của enum giới hạn và constant
- Enum cũng có thể chứa các thuộc tính val và tất cả các giá trị constant phải trùng khớp với danh sách thuộc tính đã được quy định.
- Enum có thể implement interfaces, nhưng không thể kế thừa class.
- ENUM.values() : List<ENUM>
- ENUM.valueOf(value: String) : EnumClass
## Sealed class:
-	Chung concept với enum, giao thoa với abstract class/interface
-	Điểm mạnh so với abstract class:
    - Ko cho phép khởi tạo class bên ngoài package
    - Biết trước được những subclass có thể xảy ra
    - Dễ đọc, dễ maintain
-	Giới hạn trường hợp: Tất cả class con kế thừa từ sealed class phải được quy định trong phạm vị sealed class, nếu ra ngoài phạm vi sẽ không được phép kế thừa.
-	Điểm đặc biệt so với enum: Mọi enum đều phải dùng chung một kiểu constructor cố định. Tuy nhiên, các class kt từ sealed class được phép sử dụng constructor của riêng nó (do bản chất là kế thừa)
-	Sealed class là một abstract class + private constructor.
-	Các subclass implement sealed class phải nằm chung package/module. Tốt nhất là nằm hết trong body thằng sealed
- Ví dụ
```kt
fun main() {
    lateinit var requestResult: RequestResult
    when (requestResult) {
        is RequestResult.Success -> {
            requestResult.response
        }
        is RequestResult.Failed -> {
            requestResult.error
        }
        is RequestResult.Waiting -> {
            requestResult.result
        }
    }
}

sealed class RequestResult(val result: Any) {
    data class Success(val response: Any) : RequestResult(response)
    data class Failed(val error: Any) : RequestResult(error)
    object Waiting : RequestResult("Waiting")
}
```
So sánh sealed và enum:
|                              | Sealed                                  | Enum                                     |
| ---------------------------- | --------------------------------------- | ---------------------------------------- |
| Child là ?                   | Class                                   | Constant Object                          |
| Constructor riêng của child? | Có                                      | Không                                    |
| Sử dụng khi nào ?            | Mỗi child có bản chất dữ liệu khác nhau | Dữ liệu về cơ bản là tương đương (state) |
| OOP ?                        | Có                                      | Không                                    |