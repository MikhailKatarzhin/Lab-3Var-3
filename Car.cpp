#include <iostream>
#include "Car.h"

using namespace std;
    Car :: Car()
    {
        setBrandname("___");
        setModel("Model#0");
        setColor("UNKNOWN");
        setPlaceCount(defaultPlaceCount);
        setMovementSpeed(defaultMovementSpeed);
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Car :: Car(string const * const brandname_in
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

    Car :: Car(Car const &otherCar)
    {
        this -> brandname = otherCar.brandname;
        this -> model = otherCar.model;
        this -> color = otherCar.color;
        this -> movementSpeed = otherCar.movementSpeed;
        this -> placeCount = otherCar.placeCount;
        ///cout << "\nConstruction copy... " << this;   ///лог о создании
    }
    void Car :: print() const
    {
       cout
           << "\t||\tBrandname: " << this->brandname
           << "\t||\tModel: " << this->model
           << "\t||\tColor: " << this->color << endl
           << "\t||\tSpeed: " << this->movementSpeed
           << "\t||\tPlaces count: " << this->placeCount
           << "\t||"
        ;
    }

    void Car :: setModel(string const * const model_in)
    {   this -> model = *model_in;  }
    void Car :: setModel(string const model_in)
    {   this -> model = model_in;  }

    void Car :: setColor(string const * const color_in)
    {   this -> color = *color_in;  }
    void Car :: setColor(string const color_in)
    {   this -> color = color_in;  }

    string& Car :: getModel()
    {   return model;   }

    string& Car :: getColor()
    {   return color;   }


    Car& Car :: operator ++()
    {
        this->movementSpeed += 20;
        return *this;
    }

    Car Car:: operator ++(int)
    {
        this->placeCount +=2;
        return *this;
    }

    Car& Car :: operator --()
    {
        this->movementSpeed -= 20;
        return *this;
    }

    Car Car:: operator --(int)
    {
        if (this->placeCount > 2)
        this->placeCount -=2;
        return *this;
    }

    bool Car :: operator == (const Car &car_in)
    {
        return (
                    (this -> brandname == car_in.brandname)
                    &&(this -> model == car_in.model)
                    &&(this -> color == car_in.color)
                    &&(this -> movementSpeed == car_in.movementSpeed)
                    &&(this -> placeCount == car_in.placeCount)
                );
    }

    bool Car :: operator != (const Car &car_in)
    {
        return (
                    (this -> brandname != car_in.brandname)
                    ||(this -> model != car_in.model)
                    ||(this -> color != car_in.color)
                    ||(this -> movementSpeed != car_in.movementSpeed)
                );
    }

    bool Car :: operator > (const Car &car_in)
    {
        if (this->brandname <= car_in.brandname)
            return false;
        if (this -> model <= car_in.model)
            return false;
        if (this -> color <= car_in.color)
            return false;
        if (this -> movementSpeed <= car_in.movementSpeed)
            return false;
        return (this -> placeCount > car_in.placeCount);
    }

    bool Car :: operator < (const Car &car_in)
    {
        if (this->brandname >= car_in.brandname)
            return false;
        if (this -> model >= car_in.model)
            return false;
        if (this -> color >= car_in.color)
            return false;
        if (this -> movementSpeed >= car_in.movementSpeed)
            return false;
        return (this -> placeCount < car_in.placeCount);
    }

    bool Car :: operator <= (const Car &car_in)
    {
        if (this->brandname > car_in.brandname)
            return false;
        if (this -> model > car_in.model)
            return false;
        if (this -> color > car_in.color)
            return false;
        if (this -> movementSpeed > car_in.movementSpeed)
            return false;
        return (this -> placeCount <= car_in.placeCount);
    }

    bool Car :: operator >= (const Car &car_in)
    {
        if (this->brandname < car_in.brandname)
            return false;
        if (this -> model < car_in.model)
            return false;
        if (this -> color < car_in.color)
            return false;
        if (this -> movementSpeed < car_in.movementSpeed)
            return false;
        return (this -> placeCount >= car_in.placeCount);
    }

    Car& Car :: operator = (const Car &car_in)
    {
        this ->brandname = car_in.brandname;
        this -> model = car_in.model;
        this -> color = car_in.color;
        this -> movementSpeed = car_in.movementSpeed;
        this -> placeCount = car_in.placeCount;
        return *this;
    }

    ostream& operator << (ostream &out, const Car &car_in)
    {
       cout
           << "\t||\tBrandname: " << car_in.brandname
           << "\t||\tModel: " << car_in.model
           << "\t||\tColor: " << car_in.color << endl
           << "\t||\tSpeed: " << car_in.movementSpeed
           << "\t||\tPlaces count: " << car_in.placeCount
           << "\t||"
        ;
        return out;
    }

    istream& operator >> (istream &in, Car &car_in)
    {
        in >> car_in.brandname;
        in >> car_in.model;
        in >> car_in.color;
        in >> car_in.movementSpeed;
        in >> car_in.placeCount;
        return in;
    }
