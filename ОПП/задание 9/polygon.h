#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <cmath> // ��� �������������� �������

// ����������� ����� RegularPolygon (���������� �������������)
class RegularPolygon {
protected:
    double sideLength;    // ����� �������

public:
    // ����������� � �����������
    RegularPolygon(double sideLength);

    // ����������� ����������
    virtual ~RegularPolygon();

    // ����� ����������� ����� ��� ���������� ���������
    virtual double calculatePerimeter() const = 0;

    // ����� ����������� ����� ��� ���������� �������
    virtual double calculateArea() const = 0;

    // ����� ����������� ����� ��� ������ ����������
    virtual void printInfo() const = 0;
    // ������ ��� ����� �������
    double getSideLength() const;

};

// ����� Triangle (���������� �����������) - ����������� �� RegularPolygon
class Triangle : public RegularPolygon {
public:
    // �����������
    Triangle(double sideLength);

    // ����������
    ~Triangle() override;

    // ���������� ������������ ������ ��� ���������� ���������
    double calculatePerimeter() const override;

    // ���������� ������������ ������ ��� ���������� �������
    double calculateArea() const override;

     // ���������� ������������ ������ ��� ������ ����������
    void printInfo() const override;
};

// ����� Square (�������) - ����������� �� RegularPolygon
class Square : public RegularPolygon {
public:
    // �����������
    Square(double sideLength);

    // ����������
     ~Square() override;

    // ���������� ������������ ������ ��� ���������� ���������
    double calculatePerimeter() const override;

    // ���������� ������������ ������ ��� ���������� �������
    double calculateArea() const override;

    // ���������� ������������ ������ ��� ������ ����������
    void printInfo() const override;
};

// ����� Pentagon (���������� ������������) - ����������� �� RegularPolygon
class Pentagon : public RegularPolygon {
public:
    // �����������
    Pentagon(double sideLength);

      // ����������
    ~Pentagon() override;
    // ���������� ������������ ������ ��� ���������� ���������
    double calculatePerimeter() const override;

    // ���������� ������������ ������ ��� ���������� �������
    double calculateArea() const override;

     // ���������� ������������ ������ ��� ������ ����������
    void printInfo() const override;
};

#endif