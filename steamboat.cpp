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

    Steamboat::Steamboat(Steamboat const &otherSteamboat) : Vehicle( otherSteamboat )
    {
        type = STEAMBOAT;
        this -> tonnage = otherSteamboat.tonnage;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Steamboat::print() const
    {
       std::cout
           << "\t||\tModel: " << this->model
           << "\t||\tColor: " << this->color
           << "\t||\tSpeed: " << this->movementSpeed << "\n"
           << "\t||\tPlaces count: " << this->placeCount
           << "\t||\tTonnage: " << this->tonnage
           << "\t||"
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

    void Steamboat::setTonnage(int const tonnage_in)
    {
        this -> tonnage = tonnage_in;
    }

    int Steamboat::getTonnage()
    {
        return tonnage;
    }
/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool Steamboat::operator == (const Steamboat &steamboat_in)
    {
        return (
                ( this->model == steamboat_in.model )&&
                ( this->color == steamboat_in.color )&&
                ( this->movementSpeed == steamboat_in.movementSpeed )&&
                ( this->placeCount == steamboat_in.placeCount )&&
                ( this->tonnage == steamboat_in.tonnage )
                );
    }

    bool Steamboat::operator != ( const Steamboat &steamboat_in )
    {
        return (
                ( this->tonnage != steamboat_in.tonnage )||
                ( this->model != steamboat_in.model )||
                ( this->color != steamboat_in.color )||
                ( this->movementSpeed != steamboat_in.movementSpeed )||
                ( this->placeCount == steamboat_in.placeCount )
                );
    }

    bool Steamboat::operator > ( const Steamboat &steamboat_in )
    {
        if ( this->tonnage <= steamboat_in.tonnage )
            return false;
        if ( this -> model <= steamboat_in.model )
            return false;
        if ( this -> color <= steamboat_in.color )
            return false;
        if ( this -> movementSpeed <= steamboat_in.movementSpeed )
            return false;
        return ( this -> placeCount > steamboat_in.placeCount );
    }

    bool Steamboat::operator < ( const Steamboat &steamboat_in )
    {
        if ( this->tonnage >= steamboat_in.tonnage )
            return false;
        if ( this -> model >= steamboat_in.model )
            return false;
        if ( this -> color >= steamboat_in.color )
            return false;
        if ( this -> movementSpeed >= steamboat_in.movementSpeed )
            return false;
        return (this -> placeCount < steamboat_in.placeCount );
    }

    bool Steamboat::operator <= ( const Steamboat &steamboat_in )
    {
        if ( this->tonnage > steamboat_in.tonnage )
            return false;
        if ( this -> model > steamboat_in.model )
            return false;
        if ( this -> color > steamboat_in.color )
            return false;
        if ( this -> movementSpeed > steamboat_in.movementSpeed )
            return false;
        return ( this -> placeCount <= steamboat_in.placeCount );
    }

    bool Steamboat::operator >= (const Steamboat &steamboat_in)
    {
        if ( this->tonnage < steamboat_in.tonnage )
            return false;
        if ( this -> model < steamboat_in.model )
            return false;
        if ( this -> color < steamboat_in.color )
            return false;
        if ( this -> movementSpeed < steamboat_in.movementSpeed )
            return false;
        return ( this -> placeCount >= steamboat_in.placeCount );
    }

    Steamboat& Steamboat::operator = ( const Steamboat &steamboat_in )
    {
        this->model = steamboat_in.model;
        this->color = steamboat_in.color;
        this->movementSpeed = steamboat_in.movementSpeed;
        this->placeCount = steamboat_in.placeCount;
        this->tonnage = steamboat_in.tonnage;
        return *this;
    }

    std::ostream& operator << ( std::ostream &out, const Steamboat &steamboat_in )  ///вывод полной информации в 2 строки об автомобиле
    {
       out
           << "\t||\tModel: " << steamboat_in.model
           << "\t||\tColor: " << steamboat_in.color << "\n"
           << "\t||\tSpeed: " << steamboat_in.movementSpeed
           << "\t||\tPlaces count: " << steamboat_in.placeCount
           << "\t||\tFlight hours: " << steamboat_in.tonnage
           << "\t||"
        ;
        return out;
    }

    std::istream& operator >> ( std::istream &in, Steamboat &steamboat_in ) ///последовательный ввод полной информации о легковом автомобиле
    {
        in >> steamboat_in.model;
        in >> steamboat_in.color;
        in >> steamboat_in.movementSpeed;
        in >> steamboat_in.placeCount;
        in >> steamboat_in.tonnage;
        return in;
    }
