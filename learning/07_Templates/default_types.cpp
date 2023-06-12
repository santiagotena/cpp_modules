#include <iostream>
#include <iomanip>

template<typename T = float>
class Vertex {
private:
    T const _x;
    T const _y;
    T const _z;

    Vertex();

public:
    Vertex(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z) {}

    T const &getX() const {return this->_x;}
    T const &getY() const {return this->_y;}
    T const &getZ() const {return this->_z;}
};

template<typename T>
std::ostream &operator<<(std::ostream &output, Vertex<T> const &input) {
    std::cout.precision(1);
//    output << setiosflags(std::ios::fixed);
    output << "Vertex( ";
    output << input.getX() << ", ";
    output << input.getY() << ", ";
    output << input.getZ();
    output << " )";
    return (output);
}

int main () {
    Vertex<int>     v1(12, 23, 34);
    Vertex<>        v2(12, 23, 34);

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    return (0);
}