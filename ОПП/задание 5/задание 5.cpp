#include <iostream>
#include <cmath> // ��� �������������� �������, ����� ��� sqrt

// ����������� ������ Triangle
class Triangle {
private:
    double sideA; // ����� ������� A
    double sideB; // ����� ������� B
    double sideC; // ����� ������� C

public:
    // ����������� �� ��������� (��� ����������)
    Triangle() : sideA(1.0), sideB(1.0), sideC(1.0) {
        std::cout << "������ ����������� �� ���������.\n";
    }

    // ����������� � ����������� (����� ������)
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
        std::cout << "������ ����������� � �����������.\n";
        if (!isValidTriangle()) {
            std::cerr << "������: ���������� ������� ����������� � ������ ���������." << std::endl;
             sideA = 1.0;
             sideB = 1.0;
             sideC = 1.0;
        }
    }

    // ����������
    ~Triangle() {
        std::cout << "������ ����������.\n";
    }


    // ����� ��� �������� ���������� ������������
    bool isValidTriangle() const {
        return (sideA + sideB > sideC) &&
               (sideA + sideC > sideB) &&
               (sideB + sideC > sideA) &&
               (sideA > 0 && sideB > 0 && sideC > 0); // �������� �� ���������������
    }
    // ����� ��� ������� ��������� ������������
    double calculatePerimeter() const {
        return sideA + sideB + sideC;
    }

    // ����� ��� ������� ������� ������������ (�� ������� ������)
    double calculateArea() const {
        if (!isValidTriangle()){
           return 0.0;
        }

        double p = calculatePerimeter() / 2.0; // ������������
        return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC)); // ������� �� ������� ������
    }

    // ����� ��� ������ ���������� � ������������
    void printTriangleInfo() const {
      if (!isValidTriangle()){
          std::cout << "����������� � ������������� ���������." << std::endl;
         return;
        }
        std::cout << "����� ������� A: " << sideA << std::endl;
        std::cout << "����� ������� B: " << sideB << std::endl;
        std::cout << "����� ������� C: " << sideC << std::endl;
        std::cout << "��������: " << calculatePerimeter() << std::endl;
        std::cout << "�������: " << calculateArea() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // �������� ������� ������ Triangle � �������������� ������������ �� ���������
    std::cout << "�������� ������� t1 � ������������� �� ���������:\n";
    Triangle t1;
    t1.printTriangleInfo();

    // �������� ������� ������ Triangle � �������������� ������������ � �����������
    std::cout << "\n�������� ������� t2 � ������������� � �����������:\n";
    Triangle t2(3.0, 4.0, 5.0);
     t2.printTriangleInfo();

    // �������� ������� ������ Triangle � ������������� ���������:
    std::cout << "\n�������� ������� t3 � ������������� ���������:\n";
    Triangle t3(1.0, 2.0, 5.0);
    t3.printTriangleInfo();

    return 0;
}