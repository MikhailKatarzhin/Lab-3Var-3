#pragma once
#include "vehicle.h"

class Aeroplane : public Vehicle
{
public:
/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Aeroplane();
    Aeroplane(
              std::string const &model,
              std::string const &color,
              int const         movementSpeed,
              int const         placeCount,
              int const         flight_hours
              );
    Aeroplane( Aeroplane const &aeroplane );

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void    print() const;
    void    showMenuActions() const;
    void    setFlight_Hours( int const flight_hours_in );
    int     getFlight_Hours();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool operator ==    ( const Aeroplane &aeroplane );
    bool operator !=    ( const Aeroplane &aeroplane );
    bool operator >     ( const Aeroplane &aeroplane );
    bool operator <     ( const Aeroplane &aeroplane );
    bool operator <=    ( const Aeroplane &aeroplane );
    bool operator >=    ( const Aeroplane &aeroplane );
    Aeroplane& operator = ( const Aeroplane &aeroplane );
    friend std::ostream& operator << ( std::ostream &out, const Aeroplane &aeroplane );
    friend std::istream& operator >> ( std::istream &in, Aeroplane &aeroplane );

protected:
    int flight_hours;

private:
//    int getTonnage() const override;
};
