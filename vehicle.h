#pragma once
#include <iostream>
#include <sstream>

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
/// Конструкторы

    Vehicle();
    Vehicle(
            std::string const   &model,
            std::string const   &color,
            int const           movementSpeed,
            int const           placeCount
            );
    Vehicle( Vehicle const &Vehicle );

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void    setModelDefault();
    void    setColorDefault();
    void    setPlaceCountDefault();
    void    setMovementSpeedDefault();

    void    virtual print() const = 0;
    void    virtual showMenuActions() const = 0;


    void        setModel( std::string const &model_in );
    std::string getModel() const;

    void        setColor( std::string const &color_in );
    std::string getColor() const;

    void    setMovementSpeed( int const movementSpeed );
    void    setMovementSpeed( short int const movementSpeed );
    void    setMovementSpeed( unsigned int const movementSpeed );
    void    setMovementSpeed( unsigned short int const movementSpeed );
    void    setMovementSpeed( std::string const &movementSpeed );
    int     getMovementSpeed() const;

    void    setPlaceCount( int const placeCount );
    void    setPlaceCount( short int const placeCount );
    void    setPlaceCount( unsigned int const placeCount );
    void    setPlaceCount( unsigned short int const placeCount );
    void    setPlaceCount( std::string const &movementSpeed );
    unsigned    getPlaceCount() const;

    VehicleType getVehicleType()const;


/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженные операторы

    Vehicle&    operator ++();
    Vehicle&    operator ++(int);
    Vehicle&    operator --();
    Vehicle&    operator --(int);

protected:
    std::string model;
    std::string color;
    signed int  movementSpeed;
    unsigned    placeCount;
    VehicleType type;
};

/// ///////////////////////////////////////////////////////////////////////////////
/// Функции

void    changeMovementSpeed( Vehicle &vehicle );
void    changePlaceCount( Vehicle &vehicle );
void    changeModel( Vehicle &vehicle );
void    changeColor( Vehicle &vehicle );
