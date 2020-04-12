#pragma once
#include <string>
#include <sstream>
#include "wheeled_vehicle.h"

using namespace std;
class Car : public Wheeled_vehicle
{
public:
/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Car();
    Car(
        string const * const brandname_in,
        string const * const model_in,
        string const * const color_in,
        int const movementSpeed_in,
        int const placeCount_in
        );
    Car(Car const &car);

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
