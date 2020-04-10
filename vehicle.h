#pragma once
#include <iostream>
#include <sstream>
using namespace std;

/// ///////////////////////////////////////////////////////////////////////////////
/// Перечисление типов транспортных средств

enum VehicleType
{
    UNKNOWN,
    CAR,
    AUTOBUS,
    AEROPLANE,
    STEAMBOAT
};

class Vehicle
{
public:

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void    virtual print() const = 0;
    void    virtual showMenuActions() const = 0;
    static  int const defaultMovementSpeed = 0;
    static  unsigned int const defaultPlaceCount = 1;
    void    setModel(string const * const model_in);
    void    setModel(string const model_in);
    string& getModel();
    void    setColor(string const * const color_in);
    void    setColor(string const color_in);
    string& getColor();
    void    setMovementSpeed(int const movementSpeed);
    void    setMovementSpeed(short int const movementSpeed);
    void    setMovementSpeed(unsigned int const movementSpeed);
    void    setMovementSpeed(unsigned short int const movementSpeed);
    int     getMovementSpeed() const;
    void    setPlaceCount(int const placeCount);
    void    setPlaceCount(short int const placeCount);
    void    setPlaceCount(unsigned int const placeCount);
    void    setPlaceCount(unsigned short int const placeCount);
    unsigned    getPlaceCount() const;
    VehicleType getVehicleType()const;


/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженные операторы

    Vehicle&    operator ++();
    Vehicle&    operator ++(int);
    Vehicle&    operator --();
    Vehicle&    operator --(int);

protected:
    string      model;
    string      color;
    signed int  movementSpeed;
    unsigned    placeCount;
    VehicleType type;
};

/// ///////////////////////////////////////////////////////////////////////////////
/// Функции

void    changeMovementSpeed( Vehicle * const vehicle );
void    changePlaceCount( Vehicle * const vehicle );
void    changeModel( Vehicle * const vehicle );
void    changeColor( Vehicle * const vehicle );
