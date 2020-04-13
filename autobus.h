#pragma once
#include <string>
#include "wheeled_vehicle.h"

class Autobus : public Wheeled_vehicle
{
public:

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Autobus();
    Autobus(
            std::string const   &brandname,
            std::string const   &model,
            std::string const   &color,
            int const           movementSpeed,
            int const           placeCount
            );
    Autobus( Autobus const &autobus );

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void showMenuActions();

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженные операторы

/// ///////////////////////////////////////////////////////////////////////////////
/// Функции

protected:

private:

};
