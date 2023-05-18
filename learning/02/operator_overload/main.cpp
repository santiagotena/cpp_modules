#include <iostream>

class Integer {
private:
    int value;

public:
    Integer(int val) : value(val) {}

    Integer operator+(const Integer& other) const {
        return Integer(value + other.value);
    }

    bool operator==(const Integer& other) const {
        return value == other.value;
    }

    void display() const {
        std::cout << value << std::endl;
    }
};

int main() {
    Integer num1(5);
    Integer num2(3);

    Integer sum = num1 + num2;
    sum.display(); // Output: 8

    bool isEqual = (num1 == num2);
    std::cout << "Equality: " << (isEqual ? "true" : "false") << std::endl; // Output: Equality: false

    return 0;
}
