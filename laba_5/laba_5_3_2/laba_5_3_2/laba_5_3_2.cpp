#include <iostream>
#include <string>

class Education {
protected:
    std::string degree; // поле для зберігання ступеня

public:
    // конструктор за замовчуванням
    Education() : degree("None") {}

    // конструктор з параметрами
    Education(const std::string& d) : degree(d) {}

    // конструктор копіювання
    Education(const Education& other) : degree(other.degree) {}

    // оператор присвоювання
    Education& operator=(const Education& other) {
        if (this != &other) {
            degree = other.degree;
        }
        return *this;
    }

    // виведення у потік
    friend std::ostream& operator<<(std::ostream& os, const Education& edu) {
        os << edu.degree;
        return os;
    }

    // введення з потоку
    friend std::istream& operator>>(std::istream& is, Education& edu) {
        std::cout << "Enter degree: ";
        std::getline(is, edu.degree);
        return is;
    }
};

class HigherEducation : public Education {
private:
    std::string specialization; // додаткове поле для зберігання спеціалізації

public:
    // конструктор за замовчуванням
    HigherEducation() : specialization("None") {}

    // конструктор з параметрами
    HigherEducation(const std::string& d, const std::string& s) : Education(d), specialization(s) {}

    // конструктор копіювання
    HigherEducation(const HigherEducation& other) : Education(other), specialization(other.specialization) {}

    // оператор присвоювання
    HigherEducation& operator=(const HigherEducation& other) {
        if (this != &other) {
            Education::operator=(other);
            specialization = other.specialization;
        }
        return *this;
    }

    // виведення у потік
    friend std::ostream& operator<<(std::ostream& os, const HigherEducation& hedu) {
        os << static_cast<const Education&>(hedu) << ", " << hedu.specialization;
        return os;
    }

    // введення з потоку
    friend std::istream& operator>>(std::istream& is, HigherEducation& hedu) {
        std::cout << "Enter degree: ";
        std::getline(is, hedu.degree);
        std::cout << "Enter specialization: ";
        std::getline(is, hedu.specialization);
        return is;
    }
};

int main() {
    Education edu1;
    std::cout << "Enter information for education 1:" << std::endl;
    std::cin >> edu1;
    std::cout << "Education 1: " << edu1 << std::endl;

    HigherEducation hedu1;
    std::cout << "Enter information for higher education 1:" << std::endl;
    std::cin >> hedu1;
    std::cout << "Higher education 1: " << hedu1 << std::endl;

    return 0;
}
