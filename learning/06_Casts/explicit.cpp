#include <iostream>

class A {};
class B {};

class C {
public:
             C(A const &_) { return;}
    explicit C(B const &_) { return;}
};

void    f(C const & _ ) {
    return;
}

int main() {
    f(A()); //Implicit conversion is okay
//    f(B()); //Implicit conversion is not okay, constructor is explicit

    return (0);
}
