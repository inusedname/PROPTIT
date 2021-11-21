class myClass
{
public:
    int x;

public:
    void setX();
};

void myClass::setX()
{
    x = 3;
}

int main()
{
    myClass a;
    //1. Cài đặt một con trỏ:
    myClass *p;
    p = &a;
    //hoặc
    myClass *p = new myClass;

    //2. Truy cập vào member của đỐi tượng
    cout << a.x;
    cout << p->x;

    // truy cập tới thành phần của một đối tượng thông qua con trỏ:
    int myClass::*pMem;
    pMem = &myClass::x;
    cout << pMem;
}