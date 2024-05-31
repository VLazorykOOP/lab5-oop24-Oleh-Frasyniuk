#include <iostream>
#include <cstring>

class Tail {
private:
    int length;

public:
    //конструктор з параметром
    Tail(int len) : length(len) {}

    //метод доступу
    int getLength() const {
        return length;
    }
};

class Dog {
private:
    Tail tail;
    char* color;
    int age;

public:
    
    //конструктор з параметрами
    Dog(int tailLength, const char* dogColor, int dogAge) : tail(tailLength), age(dogAge) {
        //виділення пам'яті для кольору і копіювання рядка
        size_t length = strlen(dogColor) + 1;
        color = new char[length];
        strcpy_s(color, length, dogColor);
    }

    //деструктор
    ~Dog() {
        delete[] color; //звільнення для кольору
    }

    //функція для отримання кольору
    const char* getColor() const {
        return color;
    }

    //функція для отримання віку
    int getAge() const {
        return age;
    }
};

class NamedDog : public Dog {
private:
    char* name;

public:
    //конструктор з параметрами
    NamedDog(int tailLength, const char* dogColor, int dogAge, const char* dogName)
        : Dog(tailLength, dogColor, dogAge) {
        //виділення пам'яті для клички і копіювання рядка
        size_t length = strlen(dogName) + 1;
        name = new char[length];
        strcpy_s(name, length, dogName);
    }

    //деструктор
    ~NamedDog() {
        delete[] name; //звільнення для клички
    }

    //функція друку
    void print() const {
        std::cout << "Name: " << name << ", Color: " << getColor() << ", Age: " << getAge() << std::endl;
    }
};

int main() {
    //створення об'єкту класу NamedDog
    NamedDog myDog(20, "Brown", 5, "Buddy");

    // виклик функції друку
    myDog.print();

    return 0;
}
