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
    Aeroplane(string const * const model_in, string const * const color_in, int const movementSpeed_in, int const placeCount_in, int const flight_hours);
    Aeroplane(Aeroplane const &aeroplane);

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void print() const;
    void showMenuActions();
    void setModel(string const * const model_in);
    void setModel(string const model_in);
    void setColor(string const * const color_in);
    void setColor(string const color_in);
    void setFlight_Hours(int const flight_hours_in);
    string& getModel();
    string& getColor();
    int getFlight_Hours();

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
    string model;
    string color;
    int flight_hours;

private:

};
