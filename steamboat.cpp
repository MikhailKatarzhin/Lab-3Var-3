#include "Steamboat.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// ������

    void Steamboat::showMenuActions() {}

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

    void Steamboat::setModel(string const * const model_in)
    {
        this -> model = *model_in;
    }
    void Steamboat::setModel(string const model_in)
    {
        this -> model = model_in;
    }

    void Steamboat::setColor(string const * const color_in)
    {
        this -> color = *color_in;
    }
    void Steamboat::setColor(string const color_in)
    {
        this -> color = color_in;
    }

    void Steamboat::setTonnage(int const tonnage_in)
    {
        this -> tonnage = tonnage_in;
    }

    string& Steamboat::getModel()
    {
        return model;
    }

    string& Steamboat::getColor()
    {
        return color;
    }

    int Steamboat::getTonnage()
    {
        return tonnage;
    }
/// ///////////////////////////////////////////////////////////////////////////////
/// ������������ ���������

    bool Steamboat::operator == (const Steamboat &steamboat_in)
    {
        return (
                    (this -> model == steamboat_in.model)
                    &&(this -> color == steamboat_in.color)
                    &&(this -> movementSpeed == steamboat_in.movementSpeed)
                    &&(this -> placeCount == steamboat_in.placeCount)
                    &&(this -> tonnage == steamboat_in.tonnage)
                );
    }

    bool Steamboat::operator != (const Steamboat &steamboat_in)
    {
        return (
                    (this -> tonnage != steamboat_in.tonnage)
                    ||(this -> model != steamboat_in.model)
                    ||(this -> color != steamboat_in.color)
                    ||(this -> movementSpeed != steamboat_in.movementSpeed)
                );
    }

    bool Steamboat::operator > (const Steamboat &steamboat_in)
    {
        if (this->tonnage <= steamboat_in.tonnage)
            return false;
        if (this -> model <= steamboat_in.model)
            return false;
        if (this -> color <= steamboat_in.color)
            return false;
        if (this -> movementSpeed <= steamboat_in.movementSpeed)
            return false;
        return (this -> placeCount > steamboat_in.placeCount);
    }

    bool Steamboat::operator < (const Steamboat &steamboat_in)
    {
        if (this->tonnage >= steamboat_in.tonnage)
            return false;
        if (this -> model >= steamboat_in.model)
            return false;
        if (this -> color >= steamboat_in.color)
            return false;
        if (this -> movementSpeed >= steamboat_in.movementSpeed)
            return false;
        return (this -> placeCount < steamboat_in.placeCount);
    }

    bool Steamboat::operator <= (const Steamboat &steamboat_in)
    {
        if (this->tonnage > steamboat_in.tonnage)
            return false;
        if (this -> model > steamboat_in.model)
            return false;
        if (this -> color > steamboat_in.color)
            return false;
        if (this -> movementSpeed > steamboat_in.movementSpeed)
            return false;
        return (this -> placeCount <= steamboat_in.placeCount);
    }

    bool Steamboat::operator >= (const Steamboat &steamboat_in)
    {
        if (this->tonnage < steamboat_in.tonnage)
            return false;
        if (this -> model < steamboat_in.model)
            return false;
        if (this -> color < steamboat_in.color)
            return false;
        if (this -> movementSpeed < steamboat_in.movementSpeed)
            return false;
        return (this -> placeCount >= steamboat_in.placeCount);
    }

    Steamboat& Steamboat::operator = (const Steamboat &steamboat_in)
    {
        this -> model = steamboat_in.model;
        this -> color = steamboat_in.color;
        this -> movementSpeed = steamboat_in.movementSpeed;
        this -> placeCount = steamboat_in.placeCount;
        this ->tonnage = steamboat_in.tonnage;
        return *this;
    }

    ostream& operator << (ostream &out, const Steamboat &steamboat_in)  ///����� ������ ���������� � 2 ������ �� ����������
    {
       cout
           << "\t||\tModel: " << steamboat_in.model
           << "\t||\tColor: " << steamboat_in.color << endl
           << "\t||\tSpeed: " << steamboat_in.movementSpeed
           << "\t||\tPlaces count: " << steamboat_in.placeCount
           << "\t||\tFlight hours: " << steamboat_in.tonnage
           << "\t||"
        ;
        return out;
    }

    istream& operator >> (istream &in, Steamboat &steamboat_in) ///���������������� ���� ������ ���������� � �������� ����������
    {
        in >> steamboat_in.model;
        in >> steamboat_in.color;
        in >> steamboat_in.movementSpeed;
        in >> steamboat_in.placeCount;
        in >> steamboat_in.tonnage;
        return in;
    }
