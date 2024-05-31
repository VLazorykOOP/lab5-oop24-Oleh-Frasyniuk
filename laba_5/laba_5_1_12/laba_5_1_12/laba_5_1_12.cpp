#include <iostream>

class Pair {
protected:
    int first;
    int second;

public:
    Pair(int f, int s) : first(f), second(s) {}

    //методи зміни полів
    void setFirst(int f) { first = f; }
    void setSecond(int s) { second = s; }

    //метод порівняння
    bool greaterThan(const Pair& other) const {
        return (first > other.first) || (first == other.first && second > other.second);
    }
};

class Fraction : public Pair {
public:
    Fraction(int wholePart, int fractionalPart) : Pair(wholePart, fractionalPart) {}

    //повний набір методів порівняння
    bool operator>(const Fraction& other) const {
        return greaterThan(other);
    }

    bool operator<(const Fraction& other) const {
        return other.greaterThan(*this);
    }

    bool operator==(const Fraction& other) const {
        return (first == other.first) && (second == other.second);
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator>=(const Fraction& other) const {
        return (*this > other) || (*this == other);
    }

    bool operator<=(const Fraction& other) const {
        return (*this < other) || (*this == other);
    }
};  

int main() {
    Fraction f1(3, 5);
    Fraction f2(2, 7);

    if (f1 > f2) {
        std::cout << "fraction1 is greater than fraction2" << std::endl;
    }
    else if (f1 < f2) {
        std::cout << "fraction1 is less than fraction2" << std::endl;
    }
    else {
        std::cout << "fraction1 is equal to fraction2" << std::endl;
    }

    return 0;
}
