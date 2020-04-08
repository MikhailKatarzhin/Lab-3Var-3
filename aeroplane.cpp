#include "aeroplane.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// ������

    void Aeroplane::showMenuActions() {}

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

    void Aeroplane::setModel(string const * const model_in)
    {
        this -> model = *model_in;
    }
    void Aeroplane::setModel(string const model_in)
    {
        this -> model = model_in;
    }

    void Aeroplane::setColor(string const * const color_in)
    {
        this -> color = *color_in;
    }
    void Aeroplane::setColor(string const color_in)
    {
        this -> color = color_in;
    }

    void Aeroplane::setFlight_Hours(int const flight_hours_in)
    {
        this -> flight_hours = flight_hours_in;
    }

    string& Aeroplane::getModel()
    {
        return model;
    }

    string& Aeroplane::getColor()
    {
        return color;
    }

    int Aeroplane::getFlight_Hours()
    {
        return flight_hours;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// ������������ ���������

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

    ostream& operator << (ostream &out, const Aeroplane &aeroplane_in)  ///����� ������ ���������� � 2 ������ �� ����������
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

    istream& operator >> (istream &in, Aeroplane &aeroplane_in) ///���������������� ���� ������ ���������� � �������� ����������
    {
        in >> aeroplane_in.model;
        in >> aeroplane_in.color;
        in >> aeroplane_in.movementSpeed;
        in >> aeroplane_in.placeCount;
        in >> aeroplane_in.flight_hours;
        return in;
    }
