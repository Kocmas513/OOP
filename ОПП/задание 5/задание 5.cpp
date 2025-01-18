#include <iostream>
#include <cmath> // Для математических функций, таких как sqrt

// Определение класса Triangle
class Triangle {
private:
    double sideA; // Длина стороны A
    double sideB; // Длина стороны B
    double sideC; // Длина стороны C

public:
    // Конструктор по умолчанию (без параметров)
    Triangle() : sideA(1.0), sideB(1.0), sideC(1.0) {
        std::cout << "Вызван конструктор по умолчанию.\n";
    }

    // Конструктор с параметрами (длины сторон)
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
        std::cout << "Вызван конструктор с параметрами.\n";
        if (!isValidTriangle()) {
            std::cerr << "Ошибка: Невозможно создать треугольник с такими сторонами." << std::endl;
             sideA = 1.0;
             sideB = 1.0;
             sideC = 1.0;
        }
    }

    // Деструктор
    ~Triangle() {
        std::cout << "Вызван деструктор.\n";
    }


    // Метод для проверки валидности треугольника
    bool isValidTriangle() const {
        return (sideA + sideB > sideC) &&
               (sideA + sideC > sideB) &&
               (sideB + sideC > sideA) &&
               (sideA > 0 && sideB > 0 && sideC > 0); // Проверка на положительность
    }
    // Метод для расчета периметра треугольника
    double calculatePerimeter() const {
        return sideA + sideB + sideC;
    }

    // Метод для расчета площади треугольника (по формуле Герона)
    double calculateArea() const {
        if (!isValidTriangle()){
           return 0.0;
        }

        double p = calculatePerimeter() / 2.0; // Полупериметр
        return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC)); // Площадь по формуле Герона
    }

    // Метод для вывода информации о треугольнике
    void printTriangleInfo() const {
      if (!isValidTriangle()){
          std::cout << "Треугольник с некорректными сторонами." << std::endl;
         return;
        }
        std::cout << "Длина стороны A: " << sideA << std::endl;
        std::cout << "Длина стороны B: " << sideB << std::endl;
        std::cout << "Длина стороны C: " << sideC << std::endl;
        std::cout << "Периметр: " << calculatePerimeter() << std::endl;
        std::cout << "Площадь: " << calculateArea() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание объекта класса Triangle с использованием конструктора по умолчанию
    std::cout << "Создание объекта t1 с конструктором по умолчанию:\n";
    Triangle t1;
    t1.printTriangleInfo();

    // Создание объекта класса Triangle с использованием конструктора с параметрами
    std::cout << "\nСоздание объекта t2 с конструктором с параметрами:\n";
    Triangle t2(3.0, 4.0, 5.0);
     t2.printTriangleInfo();

    // Создание объекта класса Triangle с некорректными сторонами:
    std::cout << "\nСоздание объекта t3 с некорректными сторонами:\n";
    Triangle t3(1.0, 2.0, 5.0);
    t3.printTriangleInfo();

    return 0;
}