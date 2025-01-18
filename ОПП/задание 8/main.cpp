#include "vehicle.h"
#include <iostream>
#include <iomanip> 

// ���������� ������� �������� ������ Vehicle
Vehicle::Vehicle(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture)
    : speed(speed), fuelConsumption(fuelConsumption), manufacturer(manufacturer), yearOfManufacture(yearOfManufacture) {}


Vehicle::~Vehicle() {
    std::cout << "������ ���������� Vehicle.\n";
}

double Vehicle::getSpeed() const { return speed; }
double Vehicle::getFuelConsumption() const { return fuelConsumption; }
const std::string& Vehicle::getManufacturer() const { return manufacturer; }
int Vehicle::getYearOfManufacture() const { return yearOfManufacture; }


// ���������� ������� ������ Airplane
Airplane::Airplane(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
                   double flightAltitude, double maxFlightRange, int numberOfSeats)
    : Vehicle(speed, fuelConsumption, manufacturer, yearOfManufacture),
      flightAltitude(flightAltitude), maxFlightRange(maxFlightRange), numberOfSeats(numberOfSeats) {
        std::cout << "������ ����������� Airplane.\n";
    }
Airplane::~Airplane() {
    std::cout << "������ ���������� Airplane.\n";
}
void Airplane::printData() const {
    std::cout << "���: �������\n";
    std::cout << "��������: " << speed << " ��/�\n";
    std::cout << "������ �������: " << fuelConsumption << " �/100��\n";
    std::cout << "�������������: " << manufacturer << "\n";
    std::cout << "��� �������: " << yearOfManufacture << "\n";
    std::cout << "������ ������: " << flightAltitude << " �\n";
    std::cout << "����. ��������� ������: " << maxFlightRange << " ��\n";
    std::cout << "���-�� ���������� ����: " << numberOfSeats << "\n";
}
int Airplane::calculateServiceLife() const {
    // ������ ������� ����� ������ ��� ��������
    return 30 - (2024 - getYearOfManufacture());
}
double Airplane::getFlightAltitude() const { return flightAltitude; }
double Airplane::getMaxFlightRange() const { return maxFlightRange; }
int Airplane::getNumberOfSeats() const { return numberOfSeats; }



// ���������� ������� ������ Car
Car::Car(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
         double engineVolume)
    : Vehicle(speed, fuelConsumption, manufacturer, yearOfManufacture), engineVolume(engineVolume) {
        std::cout << "������ ����������� Car.\n";
    }
Car::~Car() {
    std::cout << "������ ���������� Car.\n";
}

void Car::printData() const {
    std::cout << "���: ������\n";
    std::cout << "��������: " << speed << " ��/�\n";
    std::cout << "������ �������: " << fuelConsumption << " �/100��\n";
    std::cout << "�������������: " << manufacturer << "\n";
    std::cout << "��� �������: " << yearOfManufacture << "\n";
    std::cout << "����� ���������: " << engineVolume << " �\n";
}

int Car::calculateServiceLife() const {
    // ������ ������� ����� ������ ��� ������
      return 15 - (2024 - getYearOfManufacture());
}

 double Car::getEngineVolume() const { return engineVolume; }


// ���������� ������� ������ Ship
Ship::Ship(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
         int numberOfSeats, double displacement)
    : Vehicle(speed, fuelConsumption, manufacturer, yearOfManufacture),
      numberOfSeats(numberOfSeats), displacement(displacement) {
        std::cout << "������ ����������� Ship.\n";
    }

Ship::~Ship() {
    std::cout << "������ ���������� Ship.\n";
}

void Ship::printData() const {
    std::cout << "���: �������\n";
    std::cout << "��������: " << speed << " �����\n";
    std::cout << "������ �������: " << fuelConsumption << " �/���\n";
    std::cout << "�������������: " << manufacturer << "\n";
    std::cout << "��� �������: " << yearOfManufacture << "\n";
    std::cout << "���-�� ���������� ����: " << numberOfSeats << "\n";
    std::cout << "�������������: " << displacement << " ����\n";
}

int Ship::calculateServiceLife() const {
    // ������ ������� ����� ������ ��� �������
      return 40 - (2024 - getYearOfManufacture());
}
int Ship::getNumberOfSeats() const { return numberOfSeats; }
double Ship::getDisplacement() const { return displacement; }


int main() {
    setlocale(LC_ALL, "Russian");
    // �������� �������� ������ �������
    std::cout << "�������� ��������:\n";
    Airplane airplane(800, 5000, "Boeing", 2018, 10000, 5000, 150);
    Car car(180, 10, "Toyota", 2020, 2.5);
    Ship ship(30, 500, "Royal Caribbean", 2010, 2000, 100000);

    // ����� ������ � ����� ������
    std::cout << "\n���������� � ��������:\n";
    airplane.printData();
    std::cout << "���� ������: " << airplane.calculateServiceLife() << " ���\n";

     std::cout << "\n���������� � ������:\n";
    car.printData();
    std::cout << "���� ������: " << car.calculateServiceLife() << " ���\n";


    std::cout << "\n���������� � �������:\n";
    ship.printData();
     std::cout << "���� ������: " << ship.calculateServiceLife() << " ���\n";

    return 0;
}
