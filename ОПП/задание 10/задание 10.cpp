#include <iostream>
#include <cmath>

// Абстрактный класс Фигура
class Figure {
public:
    virtual ~Figure() {} // Виртуальный деструктор

    // Чисто виртуальные функции для вычисления площади и периметра/длину окружности
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0; // Метод для отображения информации о фигуре
};

// Класс Круг
class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius; // Площадь круга
    }

    double perimeter() const override {
        return 2 * M_PI * radius; // Длина окружности
    }

    void display() const override {
        std::cout << "Круг: радиус = " << radius << ", Площадь круга = " << area() 
                  << ", Длина окружности = " << perimeter() << std::endl;
    }
};

// Класс Треугольник
class Triangle : public Figure {
private:
    double a, b, c; // Стороны треугольника

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double area() const override {
        double s = perimeter() / 2; // Полупериметр
        return sqrt(s * (s - a) * (s - b) * (s - c)); // Площадь по формуле Герона
    }

    double perimeter() const override {
        return a + b + c; // Периметр треугольника
    }

    void display() const override {
        std::cout << "Триугольник: стороны = " << a << ", " << b << ", " << c 
                  << ", Площадь = " << area() << ", Пириметр = " << perimeter() << std::endl;
    }
};

// Класс Прямоугольник
class Rectangle : public Figure {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height; // Площадь прямоугольника
    }

    double perimeter() const override {
        return 2 * (width + height); // Периметр прямоугольника
    }

    void display() const override {
        std::cout << "Прямоугольник: ширина = " << width << ", высота = " << height 
                  << ", Площадь = " << area() << ", Пириметр = " << perimeter() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Figure* figures[3];

    figures[0] = new Circle(5.0);
    figures[1] = new Triangle(3.0, 4.0, 5.0);
    figures[2] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 3; ++i) {
        figures[i]->display();
        delete figures[i]; // Освобождаем память
    }

    return 0;
}
