#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>


// Прототип функции для вычисления длины стороны треугольника
double calculateSideLength(double x1, double y1, double x2, double y2);

// Прототип функции для вычисления периметра треугольника
double calculateTrianglePerimeter(double x1, double y1, double x2, double y2, double x3, double y3);

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<double> perimeters;
    for (int i = 1; i <= 3; i++) {
        double x1, y1, x2, y2, x3, y3;
        std::cout << "Введите Координаты треугольника " << i << " (x1 y1 x2 y2 x3 y3): ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double perimeter = calculateTrianglePerimeter(x1, y1, x2, y2, x3, y3);
        perimeters.push_back(perimeter);
    }

    // Calculate average perimeter
    double totalPerimeter = 0.0;
    for (double p : perimeters) {
        totalPerimeter += p;
    }
    double averagePerimeter = totalPerimeter / perimeters.size();


    std::cout << std::fixed << std::setprecision(2) << "среднее арифметическое периметров: " << averagePerimeter << std::endl;


    return 0;
}

// Определение функции для вычисления длины стороны треугольника
double calculateSideLength(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}


// Определение функции для вычисления периметра треугольника
double calculateTrianglePerimeter(double x1, double y1, double x2, double y2, double x3, double y3) {
    double side1 = calculateSideLength(x1, y1, x2, y2);
    double side2 = calculateSideLength(x2, y2, x3, y3);
    double side3 = calculateSideLength(x3, y3, x1, y1);
    return side1 + side2 + side3;
}


