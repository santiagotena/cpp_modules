#include <iostream>

class Foo {
private:
    float   _v;

public:
    Foo (float const v): _v(v) {}

    float getV() {return this->_v;}

    operator float() {return this->_v;}
    operator int() {return static_cast<int>(this->_v);}
};

int main() {
    Foo     a(420.42f);
    float   b = a;
    int     c = a;

    std::cout << a.getV() << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return (0);
}