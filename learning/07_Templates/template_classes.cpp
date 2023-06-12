#include <iostream>

template<typename T>
class List {
private:
    T           _content;
    List<T>     *_next;

public:
    List<T>(T const &content) {}
//    List<T>(T const &list) {}
    List<T>() {}
};

int main() {
    List<int>           a(42);
    List<float>         b(3.14f);
//    List<List<int>>     c(a);

    return (0);
}