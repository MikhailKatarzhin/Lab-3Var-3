#pragma once
#include "vehicle.h"

class Steamboat : public Vehicle
{
public:
/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Steamboat();
    Steamboat(
              std::string const &model,
              std::string const &color,
              int const         movementSpeed,
              int const         placeCount,
              int const         tonnage
              );
    Steamboat( Steamboat const &Steamboat );

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void    print() const;
    void    showMenuActions() const;
    void    setTonnage( int const tonnage_in );
    int     getTonnage();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool operator ==    ( const Steamboat &steamboat );
    bool operator !=    ( const Steamboat &steamboat );
    bool operator >     ( const Steamboat &steamboat );
    bool operator <     ( const Steamboat &steamboat );
    bool operator <=    ( const Steamboat &steamboat );
    bool operator >=    ( const Steamboat &steamboat );
    Steamboat& operator = ( const Steamboat &steamboat );
    friend std::ostream& operator << ( std::ostream &out, const Steamboat &steamboat );
    friend std::istream& operator >> ( std::istream &in, Steamboat &steamboat );

protected:
    int tonnage;

private:

};
