#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

// ����������� ����� Vehicle (�������� ������������)
class Vehicle {
protected:
    double speed;        // ��������
    double fuelConsumption; // ������ �������
    std::string manufacturer; // ������������ �������������
    int yearOfManufacture;   // ��� �������

public:
    // ����������� � ����������� ��� ����� �������
    Vehicle(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture);

    // ����������� ����������
    virtual ~Vehicle();

    // ����� ����������� ����� ��� ������ ������
    virtual void printData() const = 0;

    // ����� ����������� ����� ��� ����������� ����� ������
    virtual int calculateServiceLife() const = 0;
     //������� ��� ������� � ���������
    double getSpeed() const;
    double getFuelConsumption() const;
    const std::string& getManufacturer() const;
    int getYearOfManufacture() const;
};

// ����� Airplane (�������) - ����������� �� Vehicle
class Airplane : public Vehicle {
private:
    double flightAltitude; // ������ ������
    double maxFlightRange; // ������������ ��������� ������
    int numberOfSeats;     // ���������� ���������� ����
public:
    // �����������
    Airplane(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
             double flightAltitude, double maxFlightRange, int numberOfSeats);

     // ����������
    ~Airplane() override;

    // ���������� ������������ ������ ��� ������ ������
    void printData() const override;

    // ���������� ������������ ������ ��� ����������� ����� ������
    int calculateServiceLife() const override;

    //������� ��� ������� � ���������
    double getFlightAltitude() const;
    double getMaxFlightRange() const;
    int getNumberOfSeats() const;

};

// ����� Car (������) - ����������� �� Vehicle
class Car : public Vehicle {
private:
    double engineVolume;    // ����� ���������
public:
    // �����������
    Car(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
        double engineVolume);

     // ����������
    ~Car() override;
    // ���������� ������������ ������ ��� ������ ������
    void printData() const override;

    // ���������� ������������ ������ ��� ����������� ����� ������
    int calculateServiceLife() const override;
      //������� ��� ������� � ���������
     double getEngineVolume() const;

};

// ����� Ship (�������) - ����������� �� Vehicle
class Ship : public Vehicle {
private:
    int numberOfSeats;   // ���������� ���������� ����
    double displacement; // �������������

public:
    // �����������
    Ship(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
         int numberOfSeats, double displacement);

    // ����������
    ~Ship() override;
    // ���������� ������������ ������ ��� ������ ������
    void printData() const override;

    // ���������� ������������ ������ ��� ����������� ����� ������
    int calculateServiceLife() const override;

       //������� ��� ������� � ���������
      int getNumberOfSeats() const;
      double getDisplacement() const;
};

#endif
