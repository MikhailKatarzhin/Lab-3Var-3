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

    void print() const;
    void showMenuActions() const;
    void setTonnage( int const tonnage_in );
    int getTonnage();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool operator == ( const Steamboat &steamboat_in );
    bool operator != ( const Steamboat &steamboat_in );
    bool operator > ( const Steamboat &steamboat_in );
    bool operator < ( const Steamboat &steamboat_in );
    bool operator <= ( const Steamboat &steamboat_in );
    bool operator >= ( const Steamboat &steamboat_in );
    Steamboat& operator = ( const Steamboat &steamboat_in );
    friend std::ostream& operator << ( std::ostream &out, const Steamboat &steamboat_in );
    friend std::istream& operator >> ( std::istream &in, Steamboat &steamboat_in );

protected:
    int tonnage;

private:

};
