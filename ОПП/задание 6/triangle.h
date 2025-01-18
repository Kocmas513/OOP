#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

// Определение базового класса Triangle
class Triangle {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    // Конструктор по умолчанию
    Triangle();

    // Конструктор с параметрами
    Triangle(double a, double b, double c);

    // Виртуальный деструктор (чтобы правильно работало наследование)
    virtual ~Triangle();

    // Метод проверки валидности треугольника
    bool isValidTriangle() const;
    // Метод для расчета периметра
    double calculatePerimeter() const;

    // Метод для расчета площади (по формуле Герона)
    double calculateArea() const;

    // Метод для вывода информации о треугольнике
    virtual void printTriangleInfo() const;

    //Геттеры для доступа к сторонам
     double getSideA() const;
     double getSideB() const;
     double getSideC() const;

};

// Определение производного класса TriangleWithHeights
class TriangleWithHeights : public Triangle {
private:
public:
    // Конструктор по умолчанию
    TriangleWithHeights();

     // Конструктор с параметрами
    TriangleWithHeights(double a, double b, double c);
    // Деструктор
    ~TriangleWithHeights() override;
    // Метод для расчета высот треугольника
    void calculateHeights(double& heightA, double& heightB, double& heightC) const;

    // Переопределенный метод для вывода информации, включающий высоты
    void printTriangleInfo() const override;


};

#endif
