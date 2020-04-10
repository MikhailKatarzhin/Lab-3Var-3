#include "wheeled_vehicle.h"

string const defaultBrandname = "---";

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Wheeled_vehicle::showMenuActions() const{}

    void Wheeled_vehicle::print() const
    {
       std::cout
           << "\t||\tBrandname: " << this->brandname
           << "\t||\tModel: " << this->model
           << "\t||\tColor: " << this->color << "\n"
           << "\t||\tSpeed: " << this->movementSpeed
           << "\t||\tPlaces count: " << this->placeCount
           << "\t||"
        ;
    }

    void Wheeled_vehicle::setBrandname (string const * const brandname)
    {
        this->brandname = *brandname;
    }
    void Wheeled_vehicle::setBrandname (string const brandname)
    {
        this->brandname = brandname;
    }

    string& Wheeled_vehicle::getBrandname ()
    {
        return brandname;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool Wheeled_vehicle::operator == (const Wheeled_vehicle &wheeled_vehicle_in)
    {
        return (
                    (this -> brandname == wheeled_vehicle_in.brandname)
                    &&(this -> model == wheeled_vehicle_in.model)
                    &&(this -> color == wheeled_vehicle_in.color)
                    &&(this -> movementSpeed == wheeled_vehicle_in.movementSpeed)
                    &&(this -> placeCount == wheeled_vehicle_in.placeCount)
                );
    }

    bool Wheeled_vehicle::operator != (const Wheeled_vehicle &wheeled_vehicle_in)
    {
        return (
                    (this -> brandname != wheeled_vehicle_in.brandname)
                    ||(this -> model != wheeled_vehicle_in.model)
                    ||(this -> color != wheeled_vehicle_in.color)
                    ||(this -> movementSpeed != wheeled_vehicle_in.movementSpeed)
                );
    }

    bool Wheeled_vehicle::operator > (const Wheeled_vehicle &wheeled_vehicle_in)
    {
        if (this->brandname <= wheeled_vehicle_in.brandname)
            return false;
        if (this -> model <= wheeled_vehicle_in.model)
            return false;
        if (this -> color <= wheeled_vehicle_in.color)
            return false;
        if (this -> movementSpeed <= wheeled_vehicle_in.movementSpeed)
            return false;
        return (this -> placeCount > wheeled_vehicle_in.placeCount);
    }

    bool Wheeled_vehicle::operator < (const Wheeled_vehicle &wheeled_vehicle_in)
    {
        if (this->brandname >= wheeled_vehicle_in.brandname)
            return false;
        if (this -> model >= wheeled_vehicle_in.model)
            return false;
        if (this -> color >= wheeled_vehicle_in.color)
            return false;
        if (this -> movementSpeed >= wheeled_vehicle_in.movementSpeed)
            return false;
        return (this -> placeCount < wheeled_vehicle_in.placeCount);
    }

    bool Wheeled_vehicle::operator <= (const Wheeled_vehicle &wheeled_vehicle_in)
    {
        if (this->brandname > wheeled_vehicle_in.brandname)
            return false;
        if (this -> model > wheeled_vehicle_in.model)
            return false;
        if (this -> color > wheeled_vehicle_in.color)
            return false;
        if (this -> movementSpeed > wheeled_vehicle_in.movementSpeed)
            return false;
        return (this -> placeCount <= wheeled_vehicle_in.placeCount);
    }

    bool Wheeled_vehicle::operator >= (const Wheeled_vehicle &wheeled_vehicle_in)
    {
        if (this->brandname < wheeled_vehicle_in.brandname)
            return false;
        if (this -> model < wheeled_vehicle_in.model)
            return false;
        if (this -> color < wheeled_vehicle_in.color)
            return false;
        if (this -> movementSpeed < wheeled_vehicle_in.movementSpeed)
            return false;
        return (this -> placeCount >= wheeled_vehicle_in.placeCount);
    }

    Wheeled_vehicle& Wheeled_vehicle::operator = (const Wheeled_vehicle &wheeled_vehicle_in)
    {
        this ->brandname = wheeled_vehicle_in.brandname;
        this -> model = wheeled_vehicle_in.model;
        this -> color = wheeled_vehicle_in.color;
        this -> movementSpeed = wheeled_vehicle_in.movementSpeed;
        this -> placeCount = wheeled_vehicle_in.placeCount;
        return *this;
    }

    ostream& operator << (ostream &out, const Wheeled_vehicle &wheeled_vehicle_in)  ///вывод полной информации в 2 строки об автомобиле
    {
       cout
           << "\t||\tBrandname: " << wheeled_vehicle_in.brandname
           << "\t||\tModel: " << wheeled_vehicle_in.model
           << "\t||\tColor: " << wheeled_vehicle_in.color << endl
           << "\t||\tSpeed: " << wheeled_vehicle_in.movementSpeed
           << "\t||\tPlaces count: " << wheeled_vehicle_in.placeCount
           << "\t||"
        ;
        return out;
    }

    istream& operator >> (istream &in, Wheeled_vehicle &wheeled_vehicle_in) ///последовательный ввод полной информации о легковом автомобиле
    {
        in >> wheeled_vehicle_in.brandname;
        in >> wheeled_vehicle_in.model;
        in >> wheeled_vehicle_in.color;
        in >> wheeled_vehicle_in.movementSpeed;
        in >> wheeled_vehicle_in.placeCount;
        return in;
    }
