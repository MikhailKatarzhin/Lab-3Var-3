#pragma once
#include <string>
#include "wheeled_vehicle.h"

using namespace std;
class Autobus : public Wheeled_vehicle
{
public:

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Autobus();
    Autobus(
            string const &brandname,
            string const &model,
            string const &color,
            int const movementSpeed,
            int const placeCount
            );
    Autobus( Autobus const &autobus );

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void showMenuActions();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженные операторы

    bool operator == ( Autobus const &autobus );
    bool operator != ( Autobus const &autobus );
    bool operator > ( Autobus const &autobus );
    bool operator < ( Autobus const &autobus );
    bool operator <= ( Autobus const &autobus );
    bool operator >= ( Autobus const &autobus );
    Autobus& operator = ( Autobus const &autobus );
    friend ostream& operator << (ostream &out, Autobus const &autobus);
    friend istream& operator >> (istream &in, Autobus &autobus);

protected:

private:

};
