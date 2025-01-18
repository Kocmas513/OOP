#include "polygon.h"
#include <iostream>
#include <cmath> 

// ���������� ������� �������� ������ RegularPolygon
RegularPolygon::RegularPolygon(double sideLength) : sideLength(sideLength) {
     if (sideLength <= 0){
         std::cerr << "������: ����� ������� ������ ���� �������������" << std::endl;
         this->sideLength = 1.0;
      }
}
RegularPolygon::~RegularPolygon() {
    std::cout << "������ ���������� RegularPolygon.\n";
}

double RegularPolygon::getSideLength() const { return sideLength; }


// ���������� ������� ������ Triangle (���������� �����������)
Triangle::Triangle(double sideLength) : RegularPolygon(sideLength){
    std::cout << "������ ����������� Triangle.\n";
}
Triangle::~Triangle() {
    std::cout << "������ ���������� Triangle.\n";
}

double Triangle::calculatePerimeter() const {
    return 3 * getSideLength();
}

double Triangle::calculateArea() const {
    double side = getSideLength();
     return (std::sqrt(3) / 4) * side * side;
}
void Triangle::printInfo() const{
     std::cout << "���: ���������� �����������\n";
      std::cout << "����� �������: " << getSideLength() << "\n";
     std::cout << "��������: " << calculatePerimeter() << "\n";
     std::cout << "�������: " << calculateArea() << "\n";
}


// ���������� ������� ������ Square (�������)
Square::Square(double sideLength) : RegularPolygon(sideLength) {
      std::cout << "������ ����������� Square.\n";
}
Square::~Square() {
    std::cout << "������ ���������� Square.\n";
}

double Square::calculatePerimeter() const {
    return 4 * getSideLength();
}

double Square::calculateArea() const {
    double side = getSideLength();
    return side * side;
}
void Square::printInfo() const {
    std::cout << "���: �������\n";
    std::cout << "����� �������: " << getSideLength() << "\n";
    std::cout << "��������: " << calculatePerimeter() << "\n";
     std::cout << "�������: " << calculateArea() << "\n";
}

// ���������� ������� ������ Pentagon (���������� ������������)
Pentagon::Pentagon(double sideLength) : RegularPolygon(sideLength) {
     std::cout << "������ ����������� Pentagon.\n";
}
Pentagon::~Pentagon() {
    std::cout << "������ ���������� Pentagon.\n";
}

double Pentagon::calculatePerimeter() const {
    return 5 * getSideLength();
}

double Pentagon::calculateArea() const {
    double side = getSideLength();
    return 0.25 * std::sqrt(5 * (5 + 2 * std::sqrt(5))) * side * side;
}
void Pentagon::printInfo() const{
     std::cout << "���: ���������� ������������\n";
     std::cout << "����� �������: " << getSideLength() << "\n";
     std::cout << "��������: " << calculatePerimeter() << "\n";
     std::cout << "�������: " << calculateArea() << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    // �������� �������� ������ �������
    std::cout << "�������� ��������:\n";
    Triangle triangle(5.0);
    Square square(4.0);
    Pentagon pentagon(6.0);

    // ����� ���������� � ������ �������
    std::cout << "\n���������� � ������������:\n";
    triangle.printInfo();


    std::cout << "\n���������� � ��������:\n";
    square.printInfo();

    std::cout << "\n���������� � �������������:\n";
   pentagon.printInfo();


    return 0;
}
