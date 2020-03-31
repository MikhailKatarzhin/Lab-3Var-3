#include <iostream>
#include "Car.h"

using namespace std;
    Car :: Car()
    {
        setModel("Model#1");
        setMovementSpeed(defaultMovementSpeed);
        setColor("UNKNOWN");
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Car :: Car(string const * const model_in, int speed_in, string const * const color_in)
    {
        this -> model = *(model_in);
        this -> movementSpeed = speed_in;
        this -> color = *(color_in);
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Car :: Car(Car const &otherCar)
    {
        this -> model = otherCar.model;
        this -> movementSpeed = otherCar.movementSpeed;
        this -> color = otherCar.color;
        ///cout << "\nConstruction copy... " << this;   ///лог о создании
    }
    void Car :: print() const
    {
       cout << "||\tModel: " << this->model << "\t||\tSpeed: " << this->movementSpeed << "\t||\tColor: " << this->color << "\t||";
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
    {
        return model;
    }

    string& Car :: getColor()
    {
        return color;
    }


    Car& Car :: operator ++()
    {
        if (this->model == "Legendary") this->model = "Mythical";
        if (this->model == "Epic") this->model = "Legendary";
        if (this->model == "Rarity") this->model = "Epic";
        if (this->model == "Normal") this->model = "Rarity";
        this->movementSpeed += 20;
        return *this;
    }

    Car Car:: operator ++(int)
    {
        return ++(*this);
    }

    Car& Car :: operator --()
    {
        if (this->model == "Rarity") this->model = "Normal";
        if (this->model == "Epic") this->model = "Rarity";
        if (this->model == "Legendary") this->model = "Epic";
        if (this->model == "Mythical") this->model = "Legendary";
        if (this->movementSpeed > 20) this->movementSpeed -= 20;
        return *this;
    }

    Car Car:: operator --(int)
    {
        return --(*this);
    }

    bool Car :: operator == (const Car &car_in)
    {
        return ((this -> model == car_in.model)&&(this -> movementSpeed == car_in.movementSpeed)&&(this -> color == car_in.color));
    }

    bool Car :: operator != (const Car &car_in)
    {
        return ((this -> model != car_in.model)||(this -> movementSpeed != car_in.movementSpeed)||(this -> color != car_in.color));
    }

    bool Car :: operator > (const Car &car_in)
    {
        if ((this -> model == "Mythical")&&(car_in.model != "Mythical"))
            {return true;}
        if ((this -> model == "Legendary")&&(car_in.model != "Mythical")&&(car_in.model != "Legendary"))
            {return true;}
        if ((this -> model == "Epic")&&((car_in.model == "Normal")||(car_in.model == "Rarity")))
            {return true;}
        return ((this -> model == "Rarity")&&(car_in.model == "Normal"));
    }

    bool Car :: operator < (const Car &car_in)
    {
        if ((this -> model == "Normal")&&(car_in.model != "Normal"))
            {return true;}
        if ((this -> model == "Rarity")&&(car_in.model != "Normal")&&(car_in.model != "Rarity"))
            {return true;}
        if ((this -> model == "Epic")&&((car_in.model == "Legendary")||(car_in.model == "Mythical")))
            {return true;}
        return ((this -> model == "Legendary")&&(car_in.model == "Mythical"));
    }

    bool Car :: operator <= (const Car &car_in)
    {
        return ((*(this) == car_in) || (*(this) < car_in));
    }

    bool Car :: operator >= (const Car &car_in)
    {
        return ((*(this) == car_in) || (*(this) > car_in));
    }

    Car& Car :: operator = (const Car &car_in)
    {
        this -> model = car_in.model;
        this -> movementSpeed = car_in.movementSpeed;
        this -> color = car_in.color;
        return *this;
    }

    ostream& operator << (ostream &out, const Car &car_in)
    {
        out << "||\tModel: " << car_in.model << "\t||\tSpeed: " << car_in.movementSpeed << "\t||\tColor: " << car_in.color << "\t||";
        return out;
    }

    istream& operator >> (istream &in, Car &car_in)
    {
        in >> car_in.model;
        in >> car_in.movementSpeed;
        in >> car_in.color;
        return in;
    }
