#include <iostream>
#include <cmath>

// ����������� ����� ������
class Figure {
public:
    virtual ~Figure() {} // ����������� ����������

    // ����� ����������� ������� ��� ���������� ������� � ���������/����� ����������
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0; // ����� ��� ����������� ���������� � ������
};

// ����� ����
class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius; // ������� �����
    }

    double perimeter() const override {
        return 2 * M_PI * radius; // ����� ����������
    }

    void display() const override {
        std::cout << "����: ������ = " << radius << ", ������� ����� = " << area() 
                  << ", ����� ���������� = " << perimeter() << std::endl;
    }
};

// ����� �����������
class Triangle : public Figure {
private:
    double a, b, c; // ������� ������������

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double area() const override {
        double s = perimeter() / 2; // ������������
        return sqrt(s * (s - a) * (s - b) * (s - c)); // ������� �� ������� ������
    }

    double perimeter() const override {
        return a + b + c; // �������� ������������
    }

    void display() const override {
        std::cout << "�����������: ������� = " << a << ", " << b << ", " << c 
                  << ", ������� = " << area() << ", �������� = " << perimeter() << std::endl;
    }
};

// ����� �������������
class Rectangle : public Figure {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height; // ������� ��������������
    }

    double perimeter() const override {
        return 2 * (width + height); // �������� ��������������
    }

    void display() const override {
        std::cout << "�������������: ������ = " << width << ", ������ = " << height 
                  << ", ������� = " << area() << ", �������� = " << perimeter() << std::endl;
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
        delete figures[i]; // ����������� ������
    }

    return 0;
}
