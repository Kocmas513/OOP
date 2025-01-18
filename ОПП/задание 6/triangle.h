#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

// ����������� �������� ������ Triangle
class Triangle {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    // ����������� �� ���������
    Triangle();

    // ����������� � �����������
    Triangle(double a, double b, double c);

    // ����������� ���������� (����� ��������� �������� ������������)
    virtual ~Triangle();

    // ����� �������� ���������� ������������
    bool isValidTriangle() const;
    // ����� ��� ������� ���������
    double calculatePerimeter() const;

    // ����� ��� ������� ������� (�� ������� ������)
    double calculateArea() const;

    // ����� ��� ������ ���������� � ������������
    virtual void printTriangleInfo() const;

    //������� ��� ������� � ��������
     double getSideA() const;
     double getSideB() const;
     double getSideC() const;

};

// ����������� ������������ ������ TriangleWithHeights
class TriangleWithHeights : public Triangle {
private:
public:
    // ����������� �� ���������
    TriangleWithHeights();

     // ����������� � �����������
    TriangleWithHeights(double a, double b, double c);
    // ����������
    ~TriangleWithHeights() override;
    // ����� ��� ������� ����� ������������
    void calculateHeights(double& heightA, double& heightB, double& heightC) const;

    // ���������������� ����� ��� ������ ����������, ���������� ������
    void printTriangleInfo() const override;


};

#endif
