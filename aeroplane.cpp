#include "aeroplane.h"
#include <string>
#include <iostream>

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Aeroplane::Aeroplane() : Vehicle()
    {
        type = AEROPLANE;
        setFlight_Hours( 0 );
    }

    Aeroplane::Aeroplane(
                         std::string const  &model,
                         std::string const  &color,
                         int const          movementSpeed,
                         int const          placeCount,
                         int const          flight_hours
                         ) : Vehicle( model, color, movementSpeed, placeCount )
    {
        type = AEROPLANE;
        setFlight_Hours( flight_hours );
    }

    Aeroplane::Aeroplane( Aeroplane const &aeroplane ) :
        Vehicle( aeroplane )
    {
        type = AEROPLANE;
        setFlight_Hours( aeroplane.flight_hours );
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Aeroplane::print() const
    {
        Vehicle::print();
        std::cout <<
                "Flight hours:\t"   << this->flight_hours << "\t|| "
        ;
    }

    void Aeroplane::showMenuActions() const
{
    std::cout << "\n\t\t\t***Menu***\n";
    std::cout << "\t0)Menu up\n";
    std::cout << "\t1)Set model of aeroplane\n";
    std::cout << "\t2)Set speed of aeroplane\n";
    std::cout << "\t3)Set color of aeroplane\n";
    std::cout << "\t4)Create a duplicate of this aeroplane\n";
    std::cout << "\t5)Delete this aeroplane\n";
    std::cout << "\t6)Add some aeroplanes\n";
    std::cout << "\t7)Upgrade aeroplane\n";
    std::cout << "\t8)Downgrade aeroplane\n";
    std::cout << "\t9)Battle between aeroplanes!!!\n";
}

    void Aeroplane::setFlight_Hours( int const flight_hours )
    {
        this->flight_hours = flight_hours;
    }

    int Aeroplane::getFlight_Hours()
    {
        return flight_hours;
    }

//    int Aeroplane::getTonnage() const
//    {
//        return 0;
//    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool Aeroplane::operator == (const Aeroplane &aeroplane)
    {
        return (
                (this -> model == aeroplane.model)                  &&
                (this -> color == aeroplane.color)                  &&
                (this -> movementSpeed == aeroplane.movementSpeed)  &&
                (this -> placeCount == aeroplane.placeCount)        &&
                (this -> flight_hours == aeroplane.flight_hours)
                );
    }

    bool Aeroplane::operator != (const Aeroplane &aeroplane)
    {
        return (
                (this -> flight_hours != aeroplane.flight_hours)    ||
                (this -> model != aeroplane.model)                  ||
                (this -> color != aeroplane.color)                  ||
                (this -> movementSpeed != aeroplane.movementSpeed)
                );
    }

    bool Aeroplane::operator > ( const Aeroplane &aeroplane )
    {
        if( this->flight_hours  <= aeroplane.flight_hours )
            return false;
        if( this->model         <= aeroplane.model )
            return false;
        if( this->color         <= aeroplane.color )
            return false;
        if( this->movementSpeed <= aeroplane.movementSpeed )
            return false;
        return ( this->placeCount > aeroplane.placeCount );
    }

    bool Aeroplane::operator < ( const Aeroplane &aeroplane )
    {
        if( this->flight_hours  >= aeroplane.flight_hours )
            return false;
        if( this->model         >= aeroplane.model )
            return false;
        if( this->color         >= aeroplane.color )
            return false;
        if( this->movementSpeed >= aeroplane.movementSpeed )
            return false;
        return ( this->placeCount < aeroplane.placeCount );
    }

    bool Aeroplane::operator <= ( const Aeroplane &aeroplane )
    {
        if( this->flight_hours  > aeroplane.flight_hours )
            return false;
        if( this->model         > aeroplane.model )
            return false;
        if( this->color         > aeroplane.color )
            return false;
        if( this->movementSpeed > aeroplane.movementSpeed )
            return false;
        return ( this->placeCount <= aeroplane.placeCount );
    }

    bool Aeroplane::operator >= ( const Aeroplane &aeroplane )
    {
        if( this->flight_hours  < aeroplane.flight_hours )
            return false;
        if( this->model         < aeroplane.model )
            return false;
        if( this->color         < aeroplane.color )
            return false;
        if( this->movementSpeed < aeroplane.movementSpeed )
            return false;
        return ( this->placeCount >= aeroplane.placeCount );
    }

    Aeroplane& Aeroplane::operator = ( const Aeroplane &aeroplane )
    {
        this->model         = aeroplane.model;
        this->color         = aeroplane.color;
        this->movementSpeed = aeroplane.movementSpeed;
        this->placeCount    = aeroplane.placeCount;
        this->flight_hours  = aeroplane.flight_hours;
        return *this;
    }

    std::ostream& operator << ( std::ostream &out, const Aeroplane &aeroplane )
    {
       out <<
            "\t||\tModel: "           << aeroplane.model            <<
            "\t||\tColor: "           << aeroplane.color << "\n"    <<
            "\t||\tSpeed: "           << aeroplane.movementSpeed    <<
            "\t||\tPlaces count: "    << aeroplane.placeCount       <<
            "\t||\tFlight hours: "    << aeroplane.flight_hours     <<
            "\t||"
        ;
        return out;
    }

    std::istream& operator >> ( std::istream &in, Aeroplane &aeroplane )
    {
        in >> aeroplane.model;
        in >> aeroplane.color;
        in >> aeroplane.movementSpeed;
        in >> aeroplane.placeCount;
        in >> aeroplane.flight_hours;
        return in;
    }
