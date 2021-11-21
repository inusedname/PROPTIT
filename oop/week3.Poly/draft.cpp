#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class A
{
public:
    void Foo() {}
};
class B : public A
{
};
class C : public A
{
};
class D : public B, public C
{
};

int main()
{
    return 0;
}