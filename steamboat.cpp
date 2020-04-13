#include "Steamboat.h"
#include <string>
#include <iostream>

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Steamboat::Steamboat() : Vehicle()
    {
        type = STEAMBOAT;
        setTonnage( 0 );
    }

    Steamboat::Steamboat(
                std::string const   &model,
                std::string const   &color,
                int const           movementSpeed,
                int const           placeCount,
                int const           tonnage
                ) : Vehicle( model, color, movementSpeed, placeCount )
    {
        type = STEAMBOAT;
        setTonnage( tonnage );
    }

    Steamboat::Steamboat( Steamboat const &otherSteamboat ) : Vehicle( otherSteamboat )
    {
        type = STEAMBOAT;
        this->tonnage = otherSteamboat.tonnage;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Steamboat::print() const
    {
        Vehicle::print();
        std::cout <<
                "Tonnage:\t"   << this->tonnage << "\t|| "
        ;
    }

    void Steamboat::showMenuActions() const
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

    void Steamboat::setTonnage( int const tonnage_in )
    {
        this->tonnage = tonnage_in;
    }

    int Steamboat::getTonnage()
    {
        return tonnage;
    }
/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool Steamboat::operator == ( const Steamboat &steamboat )
    {
        return (
                ( this->model           == steamboat.model )         &&
                ( this->color           == steamboat.color )         &&
                ( this->movementSpeed   == steamboat.movementSpeed ) &&
                ( this->placeCount      == steamboat.placeCount )    &&
                ( this->tonnage         == steamboat.tonnage )
                );
    }

    bool Steamboat::operator != ( const Steamboat &steamboat )
    {
        return (
                ( this->tonnage         != steamboat.tonnage )       ||
                ( this->model           != steamboat.model )         ||
                ( this->color           != steamboat.color )         ||
                ( this->movementSpeed   != steamboat.movementSpeed ) ||
                ( this->placeCount      == steamboat.placeCount )
                );
    }

    bool Steamboat::operator > ( const Steamboat &steamboat )
    {
        if( this->tonnage       <= steamboat.tonnage )
            return false;
        if( this->model         <= steamboat.model )
            return false;
        if( this->color         <= steamboat.color )
            return false;
        if( this->movementSpeed <= steamboat.movementSpeed )
            return false;
        return ( this->placeCount > steamboat.placeCount );
    }

    bool Steamboat::operator < ( const Steamboat &steamboat )
    {
        if( this->tonnage       >=  steamboat.tonnage )
            return false;
        if( this->model         >=  steamboat.model )
            return false;
        if( this->color         >=  steamboat.color )
            return false;
        if( this->movementSpeed >=  steamboat.movementSpeed )
            return false;
        return (this->placeCount <  steamboat.placeCount );
    }

    bool Steamboat::operator <= ( const Steamboat &steamboat )
    {
        if( this->tonnage       > steamboat.tonnage )
            return false;
        if( this->model         > steamboat.model )
            return false;
        if( this->color         > steamboat.color )
            return false;
        if( this->movementSpeed > steamboat.movementSpeed )
            return false;
        return ( this->placeCount <= steamboat.placeCount );
    }

    bool Steamboat::operator >= (const Steamboat &steamboat)
    {
        if( this->tonnage       < steamboat.tonnage )
            return false;
        if( this->model         < steamboat.model )
            return false;
        if( this->color         < steamboat.color )
            return false;
        if( this->movementSpeed < steamboat.movementSpeed )
            return false;
        return ( this->placeCount >= steamboat.placeCount );
    }

    Steamboat& Steamboat::operator = ( const Steamboat &steamboat )
    {
        this->model         = steamboat.model;
        this->color         = steamboat.color;
        this->movementSpeed = steamboat.movementSpeed;
        this->placeCount    = steamboat.placeCount;
        this->tonnage       = steamboat.tonnage;
        return *this;
    }

    std::ostream& operator << ( std::ostream &out, const Steamboat &steamboat )  ///вывод полной информации в 2 строки об автомобиле
    {
       out <<
            "\t||\tModel: "           << steamboat.model <<
            "\t||\tColor: "           << steamboat.color << "\n" <<
            "\t||\tSpeed: "           << steamboat.movementSpeed <<
            "\t||\tPlaces count: "    << steamboat.placeCount <<
            "\t||\tFlight hours: "    << steamboat.tonnage <<
            "\t||"
        ;
        return out;
    }

    std::istream& operator >> ( std::istream &in, Steamboat &steamboat ) ///последовательный ввод полной информации о легковом автомобиле
    {
        in >> steamboat.model;
        in >> steamboat.color;
        in >> steamboat.movementSpeed;
        in >> steamboat.placeCount;
        in >> steamboat.tonnage;
        return in;
    }
