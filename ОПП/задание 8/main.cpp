#include "vehicle.h"
#include <iostream>
#include <iomanip> 

// Реализация методов базового класса Vehicle
Vehicle::Vehicle(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture)
    : speed(speed), fuelConsumption(fuelConsumption), manufacturer(manufacturer), yearOfManufacture(yearOfManufacture) {}


Vehicle::~Vehicle() {
    std::cout << "Вызван деструктор Vehicle.\n";
}

double Vehicle::getSpeed() const { return speed; }
double Vehicle::getFuelConsumption() const { return fuelConsumption; }
const std::string& Vehicle::getManufacturer() const { return manufacturer; }
int Vehicle::getYearOfManufacture() const { return yearOfManufacture; }


// Реализация методов класса Airplane
Airplane::Airplane(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
                   double flightAltitude, double maxFlightRange, int numberOfSeats)
    : Vehicle(speed, fuelConsumption, manufacturer, yearOfManufacture),
      flightAltitude(flightAltitude), maxFlightRange(maxFlightRange), numberOfSeats(numberOfSeats) {
        std::cout << "Вызван конструктор Airplane.\n";
    }
Airplane::~Airplane() {
    std::cout << "Вызван деструктор Airplane.\n";
}
void Airplane::printData() const {
    std::cout << "Тип: Самолет\n";
    std::cout << "Скорость: " << speed << " км/ч\n";
    std::cout << "Расход топлива: " << fuelConsumption << " л/100км\n";
    std::cout << "Производитель: " << manufacturer << "\n";
    std::cout << "Год выпуска: " << yearOfManufacture << "\n";
    std::cout << "Высота полета: " << flightAltitude << " м\n";
    std::cout << "Макс. дальность полета: " << maxFlightRange << " км\n";
    std::cout << "Кол-во посадочных мест: " << numberOfSeats << "\n";
}
int Airplane::calculateServiceLife() const {
    // Пример расчета срока службы для самолета
    return 30 - (2024 - getYearOfManufacture());
}
double Airplane::getFlightAltitude() const { return flightAltitude; }
double Airplane::getMaxFlightRange() const { return maxFlightRange; }
int Airplane::getNumberOfSeats() const { return numberOfSeats; }



// Реализация методов класса Car
Car::Car(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
         double engineVolume)
    : Vehicle(speed, fuelConsumption, manufacturer, yearOfManufacture), engineVolume(engineVolume) {
        std::cout << "Вызван конструктор Car.\n";
    }
Car::~Car() {
    std::cout << "Вызван деструктор Car.\n";
}

void Car::printData() const {
    std::cout << "Тип: Машина\n";
    std::cout << "Скорость: " << speed << " км/ч\n";
    std::cout << "Расход топлива: " << fuelConsumption << " л/100км\n";
    std::cout << "Производитель: " << manufacturer << "\n";
    std::cout << "Год выпуска: " << yearOfManufacture << "\n";
    std::cout << "Объем двигателя: " << engineVolume << " л\n";
}

int Car::calculateServiceLife() const {
    // Пример расчета срока службы для машины
      return 15 - (2024 - getYearOfManufacture());
}

 double Car::getEngineVolume() const { return engineVolume; }


// Реализация методов класса Ship
Ship::Ship(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
         int numberOfSeats, double displacement)
    : Vehicle(speed, fuelConsumption, manufacturer, yearOfManufacture),
      numberOfSeats(numberOfSeats), displacement(displacement) {
        std::cout << "Вызван конструктор Ship.\n";
    }

Ship::~Ship() {
    std::cout << "Вызван деструктор Ship.\n";
}

void Ship::printData() const {
    std::cout << "Тип: Корабль\n";
    std::cout << "Скорость: " << speed << " узлов\n";
    std::cout << "Расход топлива: " << fuelConsumption << " л/час\n";
    std::cout << "Производитель: " << manufacturer << "\n";
    std::cout << "Год выпуска: " << yearOfManufacture << "\n";
    std::cout << "Кол-во посадочных мест: " << numberOfSeats << "\n";
    std::cout << "Водоизмещение: " << displacement << " тонн\n";
}

int Ship::calculateServiceLife() const {
    // Пример расчета срока службы для корабля
      return 40 - (2024 - getYearOfManufacture());
}
int Ship::getNumberOfSeats() const { return numberOfSeats; }
double Ship::getDisplacement() const { return displacement; }


int main() {
    setlocale(LC_ALL, "Russian");
    // Создание объектов разных классов
    std::cout << "Создание объектов:\n";
    Airplane airplane(800, 5000, "Boeing", 2018, 10000, 5000, 150);
    Car car(180, 10, "Toyota", 2020, 2.5);
    Ship ship(30, 500, "Royal Caribbean", 2010, 2000, 100000);

    // Вывод данных и срока службы
    std::cout << "\nИнформация о самолете:\n";
    airplane.printData();
    std::cout << "Срок службы: " << airplane.calculateServiceLife() << " лет\n";

     std::cout << "\nИнформация о машине:\n";
    car.printData();
    std::cout << "Срок службы: " << car.calculateServiceLife() << " лет\n";


    std::cout << "\nИнформация о корабле:\n";
    ship.printData();
     std::cout << "Срок службы: " << ship.calculateServiceLife() << " лет\n";

    return 0;
}
