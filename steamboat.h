#pragma once
#include <string>
#include <iostream>
#include "vehicle.h"

using namespace std;
class Steamboat : public Vehicle
{
public:
/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Steamboat();
    Steamboat(
              string const &model,
              string const &color,
              int const movementSpeed,
              int const placeCount,
              int const tonnage
              );
    Steamboat(Steamboat const &Steamboat);

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void print() const;
    void showMenuActions() const;
    void setTonnage(int const tonnage_in);
    int getTonnage();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool operator == (const Steamboat &steamboat_in);
    bool operator != (const Steamboat &steamboat_in);
    bool operator > (const Steamboat &steamboat_in);
    bool operator < (const Steamboat &steamboat_in);
    bool operator <= (const Steamboat &steamboat_in);
    bool operator >= (const Steamboat &steamboat_in);
    Steamboat& operator = (const Steamboat &steamboat_in);
    friend ostream& operator << (ostream &out, const Steamboat &steamboat_in);
    friend istream& operator >> (istream &in, Steamboat &steamboat_in);

protected:
    int tonnage;

private:

};
