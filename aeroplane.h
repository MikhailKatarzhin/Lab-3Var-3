#pragma once
#include <string>
#include <iostream>
#include "vehicle.h"

using namespace std;
class Aeroplane : public Vehicle
{
public:
/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Aeroplane();
    Aeroplane(
              string const &model,
              string const &color,
              int const movementSpeed,
              int const placeCount,
              int const flight_hours
              );
    Aeroplane(Aeroplane const &aeroplane);

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void    print() const;
    void    showMenuActions() const;
    void    setFlight_Hours(int const flight_hours_in);
    int     getFlight_Hours();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool operator == (const Aeroplane &aeroplane_in);
    bool operator != (const Aeroplane &aeroplane_in);
    bool operator > (const Aeroplane &aeroplane_in);
    bool operator < (const Aeroplane &aeroplane_in);
    bool operator <= (const Aeroplane &aeroplane_in);
    bool operator >= (const Aeroplane &aeroplane_in);
    Aeroplane& operator = (const Aeroplane &aeroplane_in);
    friend ostream& operator << (ostream &out, const Aeroplane &aeroplane_in);
    friend istream& operator >> (istream &in, Aeroplane &aeroplane_in);

protected:
    int flight_hours;

private:

};
