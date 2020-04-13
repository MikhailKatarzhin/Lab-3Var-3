#include "Car.h"
#include <string>

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

///Пустой конструктор
Car::Car() : Wheeled_vehicle()
{
    type = CAR;
}
///Конструктор с параметрами
Car::Car(
         std::string const  &brandname,
         std::string const  &model,
         std::string const  &color,
         int const          movementSpeed,
         int const          placeCount
         ) : Wheeled_vehicle( brandname, model, color, movementSpeed, placeCount )
{
    type = CAR;
}
///Конструктор копирования
Car::Car( Car const &otherCar ) : Wheeled_vehicle( otherCar )
{
    type = CAR;
}

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

void Car::showMenuActions()
{
    std::cout << "\n\t\t\t***Menu***\n";
    std::cout << "\t0)Menu up\n";
    std::cout << "\t1)Set model of car\n";
    std::cout << "\t2)Set speed of car\n";
    std::cout << "\t3)Set color of car\n";
    std::cout << "\t4)Create a duplicate of this car\n";
    std::cout << "\t5)Delete this car\n";
    std::cout << "\t6)Add some cars\n";
    std::cout << "\t7)Upgrade car\n";
    std::cout << "\t8)Downgrade car\n";
    std::cout << "\t9)Battle between cars!!!\n";
}


/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

/// ///////////////////////////////////////////////////////////////////////////////
/// Функции

void showAllCars( short countOfCar, Car const * const cars )
{
    for ( short i = 0; i < countOfCar; i++ )
    {
        std::cout << "\n" << i+1 << ")";
        cars[i].print();
    }
}

short requestNumberOfCar( short const countOfCar )
{
    short i = -1;
    while( ( i < 0 )||( i > countOfCar ) )
    {
        std::cout << "\n\nEntry number of car( to " << countOfCar << " ) or close program( input 0 )\n";
        std::string buffer;
        std::cin >> buffer;
        std::istringstream bufferStream( buffer );
        bufferStream >> i;
    };
    return i;
}
