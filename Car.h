#pragma once
#include "wheeled_vehicle.h"

class Car : public Wheeled_vehicle
{
public:
/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Car();
    Car(
        std::string const   &brandname,
        std::string const   &model,
        std::string const   &color,
        int const           movementSpeed,
        int const           placeCount
        );
    Car( Car const &car );

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void showMenuActions();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

protected:

private:

};

void    showAllCars( short countOfCar, Car const * const cars );
short   requestNumberOfCar( short const countOfCar );
