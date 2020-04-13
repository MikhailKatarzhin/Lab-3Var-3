#pragma once
#include <string>
#include "wheeled_vehicle.h"

class Autobus : public Wheeled_vehicle
{
public:

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Autobus();
    Autobus(
            std::string const   &brandname,
            std::string const   &model,
            std::string const   &color,
            int const           movementSpeed,
            int const           placeCount
            );
    Autobus( Autobus const &autobus );

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void showMenuActions();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженные операторы

    bool operator ==    ( Autobus const &autobus );
    bool operator !=    ( Autobus const &autobus );
    bool operator >     ( Autobus const &autobus );
    bool operator <     ( Autobus const &autobus );
    bool operator <=    ( Autobus const &autobus );
    bool operator >=    ( Autobus const &autobus );
    Autobus& operator = ( Autobus const &autobus );
    friend std::ostream& operator << ( std::ostream &out, Autobus const &autobus );
    friend std::istream& operator >> ( std::istream &in, Autobus &autobus );

protected:

private:

};
