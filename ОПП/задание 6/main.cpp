#include "triangle.h"
#include <cmath> 
#include <iomanip> 

// Реализация методов базового класса Triangle
Triangle::Triangle() : sideA(1.0), sideB(1.0), sideC(1.0) {
    std::cout << "Вызван конструктор по умолчанию базового класса Triangle.\n";
}

Triangle::Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
      std::cout << "Вызван конструктор с параметрами базового класса Triangle.\n";
      if (!isValidTriangle()) {
            std::cerr << "Ошибка: Невозможно создать треугольник с такими сторонами." << std::endl;
             sideA = 1.0;
             sideB = 1.0;
             sideC = 1.0;
        }

}

Triangle::~Triangle() {
    std::cout << "Вызван деструктор базового класса Triangle.\n";
}


bool Triangle::isValidTriangle() const {
    return (sideA + sideB > sideC) &&
           (sideA + sideC > sideB) &&
           (sideB + sideC > sideA) &&
           (sideA > 0 && sideB > 0 && sideC > 0); // Проверка на положительность
}
double Triangle::calculatePerimeter() const {
    return sideA + sideB + sideC;
}

double Triangle::calculateArea() const {
     if (!isValidTriangle()){
           return 0.0;
        }
    double p = calculatePerimeter() / 2.0;
    return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

void Triangle::printTriangleInfo() const {
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

 double Triangle::getSideA() const { return sideA; }
 double Triangle::getSideB() const { return sideB; }
 double Triangle::getSideC() const { return sideC; }


// Реализация методов производного класса TriangleWithHeights
TriangleWithHeights::TriangleWithHeights() : Triangle() {
  std::cout << "Вызван конструктор по умолчанию производного класса TriangleWithHeights.\n";
}

TriangleWithHeights::TriangleWithHeights(double a, double b, double c) : Triangle(a,b,c) {
    std::cout << "Вызван конструктор с параметрами производного класса TriangleWithHeights.\n";
}

TriangleWithHeights::~TriangleWithHeights() {
     std::cout << "Вызван деструктор производного класса TriangleWithHeights.\n";
}

void TriangleWithHeights::calculateHeights(double& heightA, double& heightB, double& heightC) const {
       if (!isValidTriangle()){
        heightA = 0.0;
        heightB = 0.0;
        heightC = 0.0;
       return;
      }

    double area = calculateArea();
    heightA = 2 * area / getSideA();
    heightB = 2 * area / getSideB();
    heightC = 2 * area / getSideC();
}


void TriangleWithHeights::printTriangleInfo() const {
  Triangle::printTriangleInfo();
  if(!isValidTriangle()) {
      return;
   }
   double heightA, heightB, heightC;
  calculateHeights(heightA, heightB, heightC);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Высота к стороне A: " << heightA << std::endl;
    std::cout << "Высота к стороне B: " << heightB << std::endl;
    std::cout << "Высота к стороне C: " << heightC << std::endl;

}


int main() {
    // Создание объекта базового класса Triangle
    std::cout << "Создание объекта t1 базового класса Triangle:\n";
    Triangle t1;
     t1.printTriangleInfo();

    std::cout << "\nСоздание объекта t2 базового класса Triangle с параметрами:\n";
    Triangle t2(3.0, 4.0, 5.0);
     t2.printTriangleInfo();

    std::cout << "\nСоздание объекта t3 базового класса Triangle с некорректными сторонами:\n";
    Triangle t3(1.0, 2.0, 5.0);
     t3.printTriangleInfo();

    // Создание объекта производного класса TriangleWithHeights
      std::cout << "\nСоздание объекта t4 производного класса TriangleWithHeights:\n";
    TriangleWithHeights t4;
    t4.printTriangleInfo();
    std::cout << "\nСоздание объекта t5 производного класса TriangleWithHeights с параметрами:\n";
    TriangleWithHeights t5(5.0, 12.0, 13.0);
    t5.printTriangleInfo();
    std::cout << "\nСоздание объекта t6 производного класса TriangleWithHeights с некорректными сторонами:\n";
    TriangleWithHeights t6(1.0,2.0, 5.0);
    t6.printTriangleInfo();

    return 0;
}

