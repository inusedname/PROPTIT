class Student {
    val age = 5
    fun getAge() {
        print(age)
    }
}

fun main()
{
    val student = Student()
    print(student.getAge())
    print(student.age)
    student.age = 3
    print(student.age)
}