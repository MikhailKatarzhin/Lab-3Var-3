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
    Steamboat(string const * const model_in, string const * const color_in, int const movementSpeed_in, int const placeCount_in, int const tonnage);
    Steamboat(Steamboat const &Steamboat);

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void print() const;
    void showMenuActions() const;
    void setModel(string const * const model_in);
    void setModel(string const model_in);
    void setColor(string const * const color_in);
    void setColor(string const color_in);
    void setTonnage(int const tonnage_in);
    string& getModel();
    string& getColor();
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
    string model;
    string color;
    int tonnage;

private:

};
