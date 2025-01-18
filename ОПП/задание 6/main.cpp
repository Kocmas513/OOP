#include "triangle.h"
#include <cmath>
#include <iomanip>

// ���������� ������� �������� ������ Triangle
Triangle::Triangle() : sideA(1.0), sideB(1.0), sideC(1.0) {
    std::cout << "������ ����������� �� ��������� �������� ������ Triangle.\n";
}

Triangle::Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
      std::cout << "������ ����������� � ����������� �������� ������ Triangle.\n";
      if (!isValidTriangle()) {
            std::cerr << "������: ���������� ������� ����������� � ������ ���������." << std::endl;
             sideA = 1.0;
             sideB = 1.0;
             sideC = 1.0;
        }

}

Triangle::~Triangle() {
    std::cout << "������ ���������� �������� ������ Triangle.\n";
}


bool Triangle::isValidTriangle() const {
    return (sideA + sideB > sideC) &&
           (sideA + sideC > sideB) &&
           (sideB + sideC > sideA) &&
           (sideA > 0 && sideB > 0 && sideC > 0); // �������� �� ���������������
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
          std::cout << "����������� � ������������� ���������." << std::endl;
         return;
        }
    std::cout << "����� ������� A: " << sideA << std::endl;
    std::cout << "����� ������� B: " << sideB << std::endl;
    std::cout << "����� ������� C: " << sideC << std::endl;
    std::cout << "��������: " << calculatePerimeter() << std::endl;
    std::cout << "�������: " << calculateArea() << std::endl;
}

 double Triangle::getSideA() const { return sideA; }
 double Triangle::getSideB() const { return sideB; }
 double Triangle::getSideC() const { return sideC; }


// ���������� ������� ������������ ������ TriangleWithHeights
TriangleWithHeights::TriangleWithHeights() : Triangle() {
  std::cout << "������ ����������� �� ��������� ������������ ������ TriangleWithHeights.\n";
}

TriangleWithHeights::TriangleWithHeights(double a, double b, double c) : Triangle(a,b,c) {
    std::cout << "������ ����������� � ����������� ������������ ������ TriangleWithHeights.\n";
}

TriangleWithHeights::~TriangleWithHeights() {
     std::cout << "������ ���������� ������������ ������ TriangleWithHeights.\n";
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
    std::cout << "������ � ������� A: " << heightA << std::endl;
    std::cout << "������ � ������� B: " << heightB << std::endl;
    std::cout << "������ � ������� C: " << heightC << std::endl;

}


int main() {
    setlocale(LC_ALL, "Russian");
    // �������� ������� �������� ������ Triangle
    std::cout << "�������� ������� t1 �������� ������ Triangle:\n";
    Triangle t1;
     t1.printTriangleInfo();

    std::cout << "\n�������� ������� t2 �������� ������ Triangle � �����������:\n";
    Triangle t2(3.0, 4.0, 5.0);
     t2.printTriangleInfo();

    std::cout << "\n�������� ������� t3 �������� ������ Triangle � ������������� ���������:\n";
    Triangle t3(1.0, 2.0, 5.0);
     t3.printTriangleInfo();

    // �������� ������� ������������ ������ TriangleWithHeights
      std::cout << "\n�������� ������� t4 ������������ ������ TriangleWithHeights:\n";
    TriangleWithHeights t4;
    t4.printTriangleInfo();
    std::cout << "\n�������� ������� t5 ������������ ������ TriangleWithHeights � �����������:\n";
    TriangleWithHeights t5(5.0, 12.0, 13.0);
    t5.printTriangleInfo();
    std::cout << "\n�������� ������� t6 ������������ ������ TriangleWithHeights � ������������� ���������:\n";
    TriangleWithHeights t6(1.0,2.0, 5.0);
    t6.printTriangleInfo();

    return 0;
}
