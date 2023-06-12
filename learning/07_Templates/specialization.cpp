#include <iostream>

template<typename T, typename U>
class Pair {
private:
    T const &_lhs;
    U const &_rhs;

    Pair<T, U>();

public:
    Pair<T, U>(T const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
        std::cout << "Generic template" << std::endl;
        return;
    }

    ~Pair<T, U>() {}
        T const &fst() const {return this->_lhs;}
        U const &snd() const {return this->_rhs;}
};

/////////

template<typename U>
class Pair<int, U> {
private:
    int         _lhs;
    U const     &_rhs;

    Pair<int, U>();

public:
    Pair<int, U>(int lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
        std::cout << "Int partial specialization" << std::endl;
        return;
    }

    ~Pair<int, U>() {}

    int         fst() const {return this->_lhs;}
    U const     &snd() const {return this->_rhs;}

};

///////////

template<>
class Pair<bool, bool> {
private:
    int _n;
    Pair<bool, bool>();

public:
    Pair<bool, bool>(bool lhs, bool rhs) {
        std::cout << "Bool/bool specialization" << std::endl;
        this->_n = 0;
        this->_n |= static_cast<int>(lhs) << 0;
        this->_n |= static_cast<int>(rhs) << 1;
        return;
    }

    ~Pair<bool, bool>() {}

    bool        fst() const {return (this->_n &0x01);}
    bool        snd() const {return (this->_n &0x02);}
};

///////////

template<typename T, typename U>
std::ostream &operator<<(std::ostream &output, Pair<T, U> const &input) {
    output << "Pair( " << input.fst() << ", " << input.snd() << " )";
    return output;
}

std::ostream &operator<<(std::ostream &output, Pair<bool, bool> const &input) {
    output << std::boolalpha << "Pair( " << input.fst() << ", " << input.snd() << " )";
    return output;
}

////////////

int main() {
    Pair<int, int>              p1(4, 2);
    Pair<std::string, float>    p2(std::string("Pi"), 3.14f);
    Pair<float, bool>           p3(4.2f, true);
    Pair<bool, bool>            p4(true, false);

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;

    return (0);
}
