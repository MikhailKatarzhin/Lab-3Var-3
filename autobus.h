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
    Autobus(string const * const brandname_in, string const * const model_in, string const * const color_in, int const movementSpeed_in, int const placeCount_in);
    Autobus(Autobus const &autobus);

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы


/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженные операторы

    Autobus& operator ++();
    Autobus operator ++(int);
    Autobus& operator --();
    Autobus operator --(int);
    bool operator == (const Autobus &autobus_in);
    bool operator != (const Autobus &autobus_in);
    bool operator > (const Autobus &autobus_in);
    bool operator < (const Autobus &autobus_in);
    bool operator <= (const Autobus &autobus_in);
    bool operator >= (const Autobus &autobus_in);
    Autobus& operator = (const Autobus &autobus_in);
    friend ostream& operator << (ostream &out, const Autobus &autobus_in);
    friend istream& operator >> (istream &in, Autobus &autobus_in);

protected:

private:

};
