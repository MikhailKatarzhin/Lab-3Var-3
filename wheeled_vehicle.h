#pragma once
#include "vehicle.h"
#include <string>
#include <iostream>

class Wheeled_vehicle: public Vehicle
{
public:

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Wheeled_vehicle();
    Wheeled_vehicle(
                    std::string const &brandname,
                    std::string const &model,
                    std::string const &color,
                    int const movementSpeed,
                    int const placeCount
                    );
    Wheeled_vehicle(Wheeled_vehicle const &wheeled_vehicle);

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void setBrandnameDefault();

    void print() const;
    void showMenuActions() const;

    void setBrandname( std::string const &brandname );
    void setBrandname( std::string const brandname );
    std::string& getBrandname();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool operator ==    ( const Wheeled_vehicle &wheeled_vehicle_in );
    bool operator !=    ( const Wheeled_vehicle &wheeled_vehicle_in );
    bool operator >     ( const Wheeled_vehicle &wheeled_vehicle_in );
    bool operator <     ( const Wheeled_vehicle &wheeled_vehicle_in );
    bool operator <=    ( const Wheeled_vehicle &wheeled_vehicle_in );
    bool operator >=    ( const Wheeled_vehicle &wheeled_vehicle_in );
    Wheeled_vehicle& operator = ( const Wheeled_vehicle &wheeled_vehicle_in );
    friend std::ostream& operator << ( std::ostream &out, const Wheeled_vehicle &wheeled_vehicle_in );
    friend std::istream& operator >> ( std::istream &in, Wheeled_vehicle &wheeled_vehicle_in );

protected:
    std::string brandname;

private:
};
