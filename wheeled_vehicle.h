#pragma once
#include "vehicle.h"
#include <string>
#include <iostream>

class Wheeled_vehicle: public Vehicle
{
public:

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    static string const defaultBrandname;
    void print() const;
    void showMenuActions() const;
    void setBrandname (string const * const brandname);
    void setBrandname (string const brandname);
    void setModel(string const * const model_in);
    void setModel(string const model_in);
    void setColor(string const * const color_in);
    void setColor(string const color_in);
    string& getModel();
    string& getBrandname ();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool operator == (const Wheeled_vehicle &wheeled_vehicle_in);
    bool operator != (const Wheeled_vehicle &wheeled_vehicle_in);
    bool operator > (const Wheeled_vehicle &wheeled_vehicle_in);
    bool operator < (const Wheeled_vehicle &wheeled_vehicle_in);
    bool operator <= (const Wheeled_vehicle &wheeled_vehicle_in);
    bool operator >= (const Wheeled_vehicle &wheeled_vehicle_in);
    Wheeled_vehicle& operator = (const Wheeled_vehicle &wheeled_vehicle_in);
    friend ostream& operator << (ostream &out, const Wheeled_vehicle &wheeled_vehicle_in);
    friend istream& operator >> (istream &in, Wheeled_vehicle &wheeled_vehicle_in);

protected:
    string brandname;
    string model;
    string color;

private:
    string& getColor();
};
