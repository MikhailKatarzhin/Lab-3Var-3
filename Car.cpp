//#include <iostream>
#include "Car.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

using namespace std;
    Car::Car()
    {
        setBrandname("___");
        setModel("Model#0");
        setColor("UNKNOWN");
        setPlaceCount(defaultPlaceCount);
        setMovementSpeed(defaultMovementSpeed);
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Car::Car(string const * const brandname_in
               , string const * const model_in
               , string const * const color_in
               , int const movementSpeed_in
               , int const placeCount_in)
    {
        this -> brandname = *(brandname_in);
        this -> model = *(model_in);
        this -> color = *(color_in);
        this -> movementSpeed = movementSpeed_in;
        this -> placeCount = placeCount_in;
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Car::Car(Car const &otherCar)
    {
        this -> brandname = otherCar.brandname;
        this -> model = otherCar.model;
        this -> color = otherCar.color;
        this -> movementSpeed = otherCar.movementSpeed;
        this -> placeCount = otherCar.placeCount;
        ///cout << "\nConstruction copy... " << this;   ///лог о создании
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Car::showMenuActions()
{
    cout << "\n\t\t\t***Menu***" << endl;
    cout << "\t0)Menu up" << endl;
    cout << "\t1)Set model of car" << endl;
    cout << "\t2)Set speed of car" << endl;
    cout << "\t3)Set color of car" << endl;
    cout << "\t4)Create a duplicate of this car" << endl;
    cout << "\t5)Delete this car" << endl;
    cout << "\t6)Add some cars" << endl;
    cout << "\t7)Upgrade car" << endl;
    cout << "\t8)Downgrade car" << endl;
    cout << "\t9)Battle between cars!!!" << endl;
}


/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы
