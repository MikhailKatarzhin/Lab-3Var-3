#include <iostream>
#include "autobus.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Autobus::Autobus() : Wheeled_vehicle()
    {
        type = AUTOBUS;
    }

    Autobus::Autobus(
                     std::string const &brandname,
                     std::string const &model,
                     std::string const &color,
                     int const movementSpeed,
                     int const placeCount
                     ) : Wheeled_vehicle( brandname, model, color, movementSpeed, placeCount )
    {
        type = AUTOBUS;
    }

    Autobus::Autobus(Autobus const &otherAutobus) : Wheeled_vehicle( otherAutobus )
    {
        type = AUTOBUS;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Autobus::showMenuActions()
{
    std::cout << "\n\t\t\t***Menu***\n";
    std::cout << "\t0)Menu up\n";
    std::cout << "\t1)Set model of autobus\n";
    std::cout << "\t2)Set speed of autobus\n";
    std::cout << "\t3)Set color of autobus\n";
    std::cout << "\t4)Create a duplicate of this autobus\n";
    std::cout << "\t5)Delete this autobus\n";
    std::cout << "\t6)Add some autobus\n";
    std::cout << "\t7)Upgrade autobus\n";
    std::cout << "\t8)Downgrade autobus\n" ;
    std::cout << "\t9)Battle between autobuses!!!\n";
}

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool Autobus::operator == ( const Autobus &autobus )
    {
        return (
                ( this -> brandname == autobus.brandname )&&
                ( this -> model == autobus.model )&&
                ( this -> color == autobus.color )&&
                ( this -> movementSpeed == autobus.movementSpeed )&&
                ( this -> placeCount == autobus.placeCount )
                );
    }

    bool Autobus::operator != ( const Autobus &autobus )
    {
        return (
                ( this -> brandname != autobus.brandname )||
                ( this -> model != autobus.model )||
                ( this -> color != autobus.color )||
                ( this -> movementSpeed != autobus.movementSpeed )
                );
    }

    bool Autobus::operator > ( const Autobus &autobus )
    {
        if ( this->brandname <= autobus.brandname )
            return false;
        if ( this->model <= autobus.model )
            return false;
        if ( this->color <= autobus.color )
            return false;
        if ( this->movementSpeed <= autobus.movementSpeed )
            return false;
        return ( this->placeCount > autobus.placeCount );
    }

    bool Autobus::operator < ( const Autobus &autobus )
    {
        if ( this->brandname >= autobus.brandname)
            return false;
        if ( this->model >= autobus.model )
            return false;
        if ( this->color >= autobus.color )
            return false;
        if ( this->movementSpeed >= autobus.movementSpeed )
            return false;
        return ( this->placeCount < autobus.placeCount );
    }

    bool Autobus::operator <= ( const Autobus &autobus )
    {
        if ( this->brandname > autobus.brandname )
            return false;
        if ( this->model > autobus.model )
            return false;
        if ( this->color > autobus.color )
            return false;
        if ( this->movementSpeed > autobus.movementSpeed )
            return false;
        return ( this->placeCount <= autobus.placeCount );
    }

    bool Autobus::operator >= ( const Autobus &autobus )
    {
        if ( this->brandname < autobus.brandname )
            return false;
        if ( this->model < autobus.model )
            return false;
        if ( this->color < autobus.color )
            return false;
        if ( this->movementSpeed < autobus.movementSpeed )
            return false;
        return ( this->placeCount >= autobus.placeCount );
    }

    Autobus& Autobus::operator = ( const Autobus &autobus )
    {
        this->brandname     = autobus.brandname;
        this->model         = autobus.model;
        this->color         = autobus.color;
        this->movementSpeed = autobus.movementSpeed;
        this->placeCount    = autobus.placeCount;
        return *this;
    }

    std::ostream& operator << (std::ostream &out, const Autobus &autobus)  ///вывод полной информации в 2 строки об автомобиле
    {
       out <<
            "\t||\tBrandname: "     << autobus.brandname <<
            "\t||\tModel: "         << autobus.model <<
            "\t||\tColor: "         << autobus.color << endl <<
            "\t||\tSpeed: "         << autobus.movementSpeed <<
            "\t||\tPlaces count: "  << autobus.placeCount <<
            "\t||"
        ;
        return out;
    }

    std::istream& operator >> (std::istream &in, Autobus &autobus) ///последовательный ввод полной информации о легковом автомобиле
    {
        in >> autobus.brandname;
        in >> autobus.model;
        in >> autobus.color;
        in >> autobus.movementSpeed;
        in >> autobus.placeCount;
        return in;
    }
