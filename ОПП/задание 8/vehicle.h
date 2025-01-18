#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

// Абстрактный класс Vehicle (средство передвижения)
class Vehicle {
protected:
    double speed;        // Скорость
    double fuelConsumption; // Расход топлива
    std::string manufacturer; // Наименование производителя
    int yearOfManufacture;   // Год выпуска

public:
    // Конструктор с параметрами для общих свойств
    Vehicle(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture);

    // Виртуальный деструктор
    virtual ~Vehicle();

    // Чисто виртуальный метод для вывода данных
    virtual void printData() const = 0;

    // Чисто виртуальный метод для определения срока службы
    virtual int calculateServiceLife() const = 0;
     //Геттеры для доступа к свойствам
    double getSpeed() const;
    double getFuelConsumption() const;
    const std::string& getManufacturer() const;
    int getYearOfManufacture() const;
};

// Класс Airplane (самолет) - производный от Vehicle
class Airplane : public Vehicle {
private:
    double flightAltitude; // Высота полета
    double maxFlightRange; // Максимальная дальность полета
    int numberOfSeats;     // Количество посадочных мест
public:
    // Конструктор
    Airplane(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
             double flightAltitude, double maxFlightRange, int numberOfSeats);

     // Деструктор
    ~Airplane() override;

    // Реализация виртуального метода для вывода данных
    void printData() const override;

    // Реализация виртуального метода для определения срока службы
    int calculateServiceLife() const override;

    //Геттеры для доступа к свойствам
    double getFlightAltitude() const;
    double getMaxFlightRange() const;
    int getNumberOfSeats() const;

};

// Класс Car (машина) - производный от Vehicle
class Car : public Vehicle {
private:
    double engineVolume;    // Объем двигателя
public:
    // Конструктор
    Car(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
        double engineVolume);

     // Деструктор
    ~Car() override;
    // Реализация виртуального метода для вывода данных
    void printData() const override;

    // Реализация виртуального метода для определения срока службы
    int calculateServiceLife() const override;
      //Геттеры для доступа к свойствам
     double getEngineVolume() const;

};

// Класс Ship (корабль) - производный от Vehicle
class Ship : public Vehicle {
private:
    int numberOfSeats;   // Количество посадочных мест
    double displacement; // Водоизмещение

public:
    // Конструктор
    Ship(double speed, double fuelConsumption, const std::string& manufacturer, int yearOfManufacture,
         int numberOfSeats, double displacement);

    // Деструктор
    ~Ship() override;
    // Реализация виртуального метода для вывода данных
    void printData() const override;

    // Реализация виртуального метода для определения срока службы
    int calculateServiceLife() const override;

       //Геттеры для доступа к свойствам
      int getNumberOfSeats() const;
      double getDisplacement() const;
};

#endif
