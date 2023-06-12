#include <iostream>

class Sample {
private:
    int data;

public:
    // Default constructor
    Sample() : data(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // Parameterized constructor
    Sample(int value) : data(value) {
        std::cout << "Parameterized constructor called" << std::endl;
    }

    // Destructor
    ~Sample() {
        std::cout << "Destructor called" << std::endl;
    }

    // Copy constructor
    Sample(const Sample& other) : data(other.data) {
        std::cout << "Copy constructor called" << std::endl;
    }

    // Copy assignment operator
    Sample& operator=(const Sample& other) {
        if (this != &other) {
            data = other.data;
        }
        std::cout << "Copy assignment operator called" << std::endl;
        return *this;
    }

    // Equality comparison operator
    bool operator==(const Sample& other) const {
        return data == other.data;
    }

    // Getter
    int getData() const {
        return data;
    }
};

int main() {
    // Create objects using different constructors
    Sample obj1; // Default constructor
    Sample obj2(42); // Parameterized constructor

    // Copy constructor
    Sample obj3 = obj1;

    // Copy assignment operator
    Sample obj4;
    obj4 = obj2;

    // Equality comparison
    bool isEqual = (obj1 == obj2);
    std::cout << "Equality: " << (isEqual ? "true" : "false") << std::endl;

    // Access data using getter
    int value = obj1.getData();
    std::cout << "Value: " << value << std::endl;

    return 0;
}