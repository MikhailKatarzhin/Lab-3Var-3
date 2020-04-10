#include "aeroplane.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Aeroplane::Aeroplane()
    {
        type = AEROPLANE;
        setModel("Model#0");
        setColor("UNKNOWN");
        setPlaceCount(defaultPlaceCount);
        setMovementSpeed(defaultMovementSpeed);
        setFlight_Hours(0);
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Aeroplane::Aeroplane(
                string const * const model_in,
                string const * const color_in,
                int const movementSpeed_in,
                int const placeCount_in,
                int const flight_hours)
    {
        type = AEROPLANE;
        this -> model = *(model_in);
        this -> color = *(color_in);
        this -> movementSpeed = movementSpeed_in;
        this -> placeCount = placeCount_in;
        this -> flight_hours = flight_hours;
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Aeroplane::Aeroplane(Aeroplane const &otherAeroplane)
    {
        type = AEROPLANE;
        this -> model = otherAeroplane.model;
        this -> color = otherAeroplane.color;
        this -> movementSpeed = otherAeroplane.movementSpeed;
        this -> placeCount = otherAeroplane.placeCount;
        this -> flight_hours = otherAeroplane.flight_hours;
        ///cout << "\nConstruction copy... " << this;   ///лог о создании
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Aeroplane::print() const
    {
       std::cout
           << "\t||\tModel: " << this->model
           << "\t||\tColor: " << this->color
           << "\t||\tSpeed: " << this->movementSpeed << "\n"
           << "\t||\tPlaces count: " << this->placeCount
           << "\t||\tFlight hours: " << this->flight_hours
           << "\t||"
        ;
    }

    void Aeroplane::showMenuActions() const
{
    cout << "\n\t\t\t***Menu***" << endl;
    cout << "\t0)Menu up" << endl;
    cout << "\t1)Set model of aeroplane" << endl;
    cout << "\t2)Set speed of aeroplane" << endl;
    cout << "\t3)Set color of aeroplane" << endl;
    cout << "\t4)Create a duplicate of this aeroplane" << endl;
    cout << "\t5)Delete this aeroplane" << endl;
    cout << "\t6)Add some aeroplanes" << endl;
    cout << "\t7)Upgrade aeroplane" << endl;
    cout << "\t8)Downgrade aeroplane" << endl;
    cout << "\t9)Battle between aeroplanes!!!" << endl;
}

    void Aeroplane::setFlight_Hours(int const flight_hours_in)
    {
        this -> flight_hours = flight_hours_in;
    }

    int Aeroplane::getFlight_Hours()
    {
        return flight_hours;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool Aeroplane::operator == (const Aeroplane &aeroplane_in)
    {
        return (
                    (this -> model == aeroplane_in.model)
                    &&(this -> color == aeroplane_in.color)
                    &&(this -> movementSpeed == aeroplane_in.movementSpeed)
                    &&(this -> placeCount == aeroplane_in.placeCount)
                    &&(this -> flight_hours == aeroplane_in.flight_hours)
                );
    }

    bool Aeroplane::operator != (const Aeroplane &aeroplane_in)
    {
        return (
                    (this -> flight_hours != aeroplane_in.flight_hours)
                    ||(this -> model != aeroplane_in.model)
                    ||(this -> color != aeroplane_in.color)
                    ||(this -> movementSpeed != aeroplane_in.movementSpeed)
                );
    }

    bool Aeroplane::operator > (const Aeroplane &aeroplane_in)
    {
        if (this->flight_hours <= aeroplane_in.flight_hours)
            return false;
        if (this -> model <= aeroplane_in.model)
            return false;
        if (this -> color <= aeroplane_in.color)
            return false;
        if (this -> movementSpeed <= aeroplane_in.movementSpeed)
            return false;
        return (this -> placeCount > aeroplane_in.placeCount);
    }

    bool Aeroplane::operator < (const Aeroplane &aeroplane_in)
    {
        if (this->flight_hours >= aeroplane_in.flight_hours)
            return false;
        if (this -> model >= aeroplane_in.model)
            return false;
        if (this -> color >= aeroplane_in.color)
            return false;
        if (this -> movementSpeed >= aeroplane_in.movementSpeed)
            return false;
        return (this -> placeCount < aeroplane_in.placeCount);
    }

    bool Aeroplane::operator <= (const Aeroplane &aeroplane_in)
    {
        if (this->flight_hours > aeroplane_in.flight_hours)
            return false;
        if (this -> model > aeroplane_in.model)
            return false;
        if (this -> color > aeroplane_in.color)
            return false;
        if (this -> movementSpeed > aeroplane_in.movementSpeed)
            return false;
        return (this -> placeCount <= aeroplane_in.placeCount);
    }

    bool Aeroplane::operator >= (const Aeroplane &aeroplane_in)
    {
        if (this->flight_hours < aeroplane_in.flight_hours)
            return false;
        if (this -> model < aeroplane_in.model)
            return false;
        if (this -> color < aeroplane_in.color)
            return false;
        if (this -> movementSpeed < aeroplane_in.movementSpeed)
            return false;
        return (this -> placeCount >= aeroplane_in.placeCount);
    }

    Aeroplane& Aeroplane::operator = (const Aeroplane &aeroplane_in)
    {
        this -> model = aeroplane_in.model;
        this -> color = aeroplane_in.color;
        this -> movementSpeed = aeroplane_in.movementSpeed;
        this -> placeCount = aeroplane_in.placeCount;
        this ->flight_hours = aeroplane_in.flight_hours;
        return *this;
    }

    ostream& operator << (ostream &out, const Aeroplane &aeroplane_in)  ///вывод полной информации в 2 строки об автомобиле
    {
       cout
           << "\t||\tModel: " << aeroplane_in.model
           << "\t||\tColor: " << aeroplane_in.color << endl
           << "\t||\tSpeed: " << aeroplane_in.movementSpeed
           << "\t||\tPlaces count: " << aeroplane_in.placeCount
           << "\t||\tFlight hours: " << aeroplane_in.flight_hours
           << "\t||"
        ;
        return out;
    }

    istream& operator >> (istream &in, Aeroplane &aeroplane_in) ///последовательный ввод полной информации о легковом автомобиле
    {
        in >> aeroplane_in.model;
        in >> aeroplane_in.color;
        in >> aeroplane_in.movementSpeed;
        in >> aeroplane_in.placeCount;
        in >> aeroplane_in.flight_hours;
        return in;
    }
