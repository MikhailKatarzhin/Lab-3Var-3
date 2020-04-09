#include <iostream>
#include "autobus.h"

using namespace std;

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Autobus::Autobus()
    {
        type = AUTOBUS;
        setBrandname("___");
        setModel("Model#0");
        setColor("UNKNOWN");
        setPlaceCount(defaultPlaceCount);
        setMovementSpeed(defaultMovementSpeed);
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Autobus::Autobus(string const * const brandname_in
               , string const * const model_in
               , string const * const color_in
               , int const movementSpeed_in
               , int const placeCount_in)
    {
        type = AUTOBUS;
        this -> brandname = *(brandname_in);
        this -> model = *(model_in);
        this -> color = *(color_in);
        this -> movementSpeed = movementSpeed_in;
        this -> placeCount = placeCount_in;
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Autobus::Autobus(Autobus const &otherAutobus)
    {
        type = AUTOBUS;
        this -> brandname = otherAutobus.brandname;
        this -> model = otherAutobus.model;
        this -> color = otherAutobus.color;
        this -> movementSpeed = otherAutobus.movementSpeed;
        this -> placeCount = otherAutobus.placeCount;
        ///cout << "\nConstruction copy... " << this;   ///лог о создании
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Autobus::showMenuActions()
{
    cout << "\n\t\t\t***Menu***" << endl;
    cout << "\t0)Menu up" << endl;
    cout << "\t1)Set model of autobus" << endl;
    cout << "\t2)Set speed of autobus" << endl;
    cout << "\t3)Set color of autobus" << endl;
    cout << "\t4)Create a duplicate of this autobus" << endl;
    cout << "\t5)Delete this autobus" << endl;
    cout << "\t6)Add some autobus" << endl;
    cout << "\t7)Upgrade autobus" << endl;
    cout << "\t8)Downgrade autobus" << endl;
    cout << "\t9)Battle between autobuses!!!" << endl;
}

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool Autobus::operator == (const Autobus &autobus_in)
    {
        return (
                    (this -> brandname == autobus_in.brandname)
                    &&(this -> model == autobus_in.model)
                    &&(this -> color == autobus_in.color)
                    &&(this -> movementSpeed == autobus_in.movementSpeed)
                    &&(this -> placeCount == autobus_in.placeCount)
                );
    }

    bool Autobus::operator != (const Autobus &autobus_in)
    {
        return (
                    (this -> brandname != autobus_in.brandname)
                    ||(this -> model != autobus_in.model)
                    ||(this -> color != autobus_in.color)
                    ||(this -> movementSpeed != autobus_in.movementSpeed)
                );
    }

    bool Autobus::operator > (const Autobus &autobus_in)
    {
        if (this->brandname <= autobus_in.brandname)
            return false;
        if (this -> model <= autobus_in.model)
            return false;
        if (this -> color <= autobus_in.color)
            return false;
        if (this -> movementSpeed <= autobus_in.movementSpeed)
            return false;
        return (this -> placeCount > autobus_in.placeCount);
    }

    bool Autobus::operator < (const Autobus &autobus_in)
    {
        if (this->brandname >= autobus_in.brandname)
            return false;
        if (this -> model >= autobus_in.model)
            return false;
        if (this -> color >= autobus_in.color)
            return false;
        if (this -> movementSpeed >= autobus_in.movementSpeed)
            return false;
        return (this -> placeCount < autobus_in.placeCount);
    }

    bool Autobus::operator <= (const Autobus &autobus_in)
    {
        if (this->brandname > autobus_in.brandname)
            return false;
        if (this -> model > autobus_in.model)
            return false;
        if (this -> color > autobus_in.color)
            return false;
        if (this -> movementSpeed > autobus_in.movementSpeed)
            return false;
        return (this -> placeCount <= autobus_in.placeCount);
    }

    bool Autobus::operator >= (const Autobus &autobus_in)
    {
        if (this->brandname < autobus_in.brandname)
            return false;
        if (this -> model < autobus_in.model)
            return false;
        if (this -> color < autobus_in.color)
            return false;
        if (this -> movementSpeed < autobus_in.movementSpeed)
            return false;
        return (this -> placeCount >= autobus_in.placeCount);
    }

    Autobus& Autobus::operator = (const Autobus &autobus_in)
    {
        this ->brandname = autobus_in.brandname;
        this -> model = autobus_in.model;
        this -> color = autobus_in.color;
        this -> movementSpeed = autobus_in.movementSpeed;
        this -> placeCount = autobus_in.placeCount;
        return *this;
    }

    ostream& operator << (ostream &out, const Autobus &autobus_in)  ///вывод полной информации в 2 строки об автомобиле
    {
       cout
           << "\t||\tBrandname: " << autobus_in.brandname
           << "\t||\tModel: " << autobus_in.model
           << "\t||\tColor: " << autobus_in.color << endl
           << "\t||\tSpeed: " << autobus_in.movementSpeed
           << "\t||\tPlaces count: " << autobus_in.placeCount
           << "\t||"
        ;
        return out;
    }

    istream& operator >> (istream &in, Autobus &autobus_in) ///последовательный ввод полной информации о легковом автомобиле
    {
        in >> autobus_in.brandname;
        in >> autobus_in.model;
        in >> autobus_in.color;
        in >> autobus_in.movementSpeed;
        in >> autobus_in.placeCount;
        return in;
    }
