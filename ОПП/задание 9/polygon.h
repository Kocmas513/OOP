#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <cmath> // Для математических функций

// Абстрактный класс RegularPolygon (правильный многоугольник)
class RegularPolygon {
protected:
    double sideLength;    // Длина стороны

public:
    // Конструктор с параметрами
    RegularPolygon(double sideLength);

    // Виртуальный деструктор
    virtual ~RegularPolygon();

    // Чисто виртуальный метод для вычисления периметра
    virtual double calculatePerimeter() const = 0;

    // Чисто виртуальный метод для вычисления площади
    virtual double calculateArea() const = 0;

    // Чисто виртуальный метод для вывода информации
    virtual void printInfo() const = 0;
    // Геттер для длины стороны
    double getSideLength() const;

};

// Класс Triangle (правильный треугольник) - производный от RegularPolygon
class Triangle : public RegularPolygon {
public:
    // Конструктор
    Triangle(double sideLength);

    // Деструктор
    ~Triangle() override;

    // Реализация виртуального метода для вычисления периметра
    double calculatePerimeter() const override;

    // Реализация виртуального метода для вычисления площади
    double calculateArea() const override;

     // Реализация виртуального метода для вывода информации
    void printInfo() const override;
};

// Класс Square (квадрат) - производный от RegularPolygon
class Square : public RegularPolygon {
public:
    // Конструктор
    Square(double sideLength);

    // Деструктор
     ~Square() override;

    // Реализация виртуального метода для вычисления периметра
    double calculatePerimeter() const override;

    // Реализация виртуального метода для вычисления площади
    double calculateArea() const override;

    // Реализация виртуального метода для вывода информации
    void printInfo() const override;
};

// Класс Pentagon (правильный пятиугольник) - производный от RegularPolygon
class Pentagon : public RegularPolygon {
public:
    // Конструктор
    Pentagon(double sideLength);

      // Деструктор
    ~Pentagon() override;
    // Реализация виртуального метода для вычисления периметра
    double calculatePerimeter() const override;

    // Реализация виртуального метода для вычисления площади
    double calculateArea() const override;

     // Реализация виртуального метода для вывода информации
    void printInfo() const override;
};

#endif