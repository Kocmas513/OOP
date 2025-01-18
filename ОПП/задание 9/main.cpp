#include "polygon.h"
#include <iostream>
#include <cmath> 

// Реализация методов базового класса RegularPolygon
RegularPolygon::RegularPolygon(double sideLength) : sideLength(sideLength) {
     if (sideLength <= 0){
         std::cerr << "Ошибка: Длина стороны должна быть положительной" << std::endl;
         this->sideLength = 1.0;
      }
}
RegularPolygon::~RegularPolygon() {
    std::cout << "Вызван деструктор RegularPolygon.\n";
}

double RegularPolygon::getSideLength() const { return sideLength; }


// Реализация методов класса Triangle (правильный треугольник)
Triangle::Triangle(double sideLength) : RegularPolygon(sideLength){
    std::cout << "Вызван конструктор Triangle.\n";
}
Triangle::~Triangle() {
    std::cout << "Вызван деструктор Triangle.\n";
}

double Triangle::calculatePerimeter() const {
    return 3 * getSideLength();
}

double Triangle::calculateArea() const {
    double side = getSideLength();
     return (std::sqrt(3) / 4) * side * side;
}
void Triangle::printInfo() const{
     std::cout << "Тип: Правильный Треугольник\n";
      std::cout << "Длина стороны: " << getSideLength() << "\n";
     std::cout << "Периметр: " << calculatePerimeter() << "\n";
     std::cout << "Площадь: " << calculateArea() << "\n";
}


// Реализация методов класса Square (квадрат)
Square::Square(double sideLength) : RegularPolygon(sideLength) {
      std::cout << "Вызван конструктор Square.\n";
}
Square::~Square() {
    std::cout << "Вызван деструктор Square.\n";
}

double Square::calculatePerimeter() const {
    return 4 * getSideLength();
}

double Square::calculateArea() const {
    double side = getSideLength();
    return side * side;
}
void Square::printInfo() const {
    std::cout << "Тип: Квадрат\n";
    std::cout << "Длина стороны: " << getSideLength() << "\n";
    std::cout << "Периметр: " << calculatePerimeter() << "\n";
     std::cout << "Площадь: " << calculateArea() << "\n";
}

// Реализация методов класса Pentagon (правильный пятиугольник)
Pentagon::Pentagon(double sideLength) : RegularPolygon(sideLength) {
     std::cout << "Вызван конструктор Pentagon.\n";
}
Pentagon::~Pentagon() {
    std::cout << "Вызван деструктор Pentagon.\n";
}

double Pentagon::calculatePerimeter() const {
    return 5 * getSideLength();
}

double Pentagon::calculateArea() const {
    double side = getSideLength();
    return 0.25 * std::sqrt(5 * (5 + 2 * std::sqrt(5))) * side * side;
}
void Pentagon::printInfo() const{
     std::cout << "Тип: Правильный Пятиугольник\n";
     std::cout << "Длина стороны: " << getSideLength() << "\n";
     std::cout << "Периметр: " << calculatePerimeter() << "\n";
     std::cout << "Площадь: " << calculateArea() << "\n";
}

int main() {
    // Создание объектов разных классов
    std::cout << "Создание объектов:\n";
    Triangle triangle(5.0);
    Square square(4.0);
    Pentagon pentagon(6.0);

    // Вывод информации о каждом объекте
    std::cout << "\nИнформация о треугольнике:\n";
    triangle.printInfo();


    std::cout << "\nИнформация о квадрате:\n";
    square.printInfo();

    std::cout << "\nИнформация о пятиугольнике:\n";
   pentagon.printInfo();


    return 0;
}
