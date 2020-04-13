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

/// ///////////////////////////////////////////////////////////////////////////////
/// Функции
