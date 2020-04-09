#include "Vehicle.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Vehicle::setModel(string const * const model_in)
    {
        this -> model = *model_in;
    }
    void Vehicle::setModel(string const model_in)
    {
        this -> model = model_in;
    }

    string& Vehicle::getModel()
    {
        return model;
    }

    void Vehicle::setColor(string const * const color_in)
    {
        this -> color = *color_in;
    }
    void Vehicle::setColor(string const color_in)
    {
        this -> color = color_in;
    }

    string& Vehicle::getColor()
    {
        return color;
    }

    void Vehicle::setMovementSpeed(int const movementSpeed)
    {
        this -> movementSpeed = (int)movementSpeed;
    }
    void Vehicle::setMovementSpeed(short int const movementSpeed)
    {
        this -> movementSpeed = (int)movementSpeed;
    }
    void Vehicle::setMovementSpeed(unsigned int const movementSpeed)
    {
        this -> movementSpeed = (int)movementSpeed;
    }
    void Vehicle::setMovementSpeed(unsigned short int const movementSpeed)
    {
        this -> movementSpeed = (int)movementSpeed;
    }

    int Vehicle::getMovementSpeed() const
    {
        return movementSpeed;
    }

    void Vehicle::setPlaceCount(int const placeCount)
    {
        this -> placeCount = (unsigned int)placeCount;
    }
    void Vehicle::setPlaceCount(short int const placeCount)
    {
        this -> placeCount = (unsigned int)placeCount;
    }
    void Vehicle::setPlaceCount(unsigned int const placeCount)
    {
        this -> placeCount = (unsigned int)placeCount;
    }
    void Vehicle::setPlaceCount(unsigned short int const placeCount)
    {
        this -> placeCount = (unsigned int)placeCount;
    }

    unsigned int Vehicle::getPlaceCount() const
    {
        return placeCount;
    }

    VehicleType Vehicle::getVehicleType() const
    {
        return type;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженные операторы

    Vehicle& Vehicle::operator ++()
    {
        this->movementSpeed += 20;
        return *this;
    }

    Vehicle& Vehicle::operator ++(int)
    {
        this->placeCount +=2;
        return *this;
    }

    Vehicle& Vehicle::operator --()
    {
        this->movementSpeed -= 20;
        return *this;
    }

    Vehicle& Vehicle::operator --(int)
    {
        if (this->placeCount > 2)
        this->placeCount -=2;
        return *this;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Функции

    void changeMovementSpeed( Vehicle * const vehicle )
    {
        short   tmpSpeed;
        while(1)
        {
            cout << "\nEntry speed of vehicle(more than 0):\t";
            string buffer;
            cin >> buffer;
            istringstream bufferStream(buffer);
            bufferStream >> tmpSpeed;
            if ( tmpSpeed > 0 )
            {
                vehicle->setMovementSpeed(tmpSpeed);
                break;
            }else{
                cout << "\nInvalid input, repeat..." << endl;
            }
        }
    }

    void changePlaceCount( Vehicle * const vehicle )
    {
        short   tmpPlaceCount;
        while(1)
        {
            cout << "\nEntry place count of vehicle(more than 0):\t";
            string buffer;
            cin >> buffer;
            istringstream bufferStream(buffer);
            bufferStream >> tmpPlaceCount;
            if ( tmpPlaceCount > 0 )
            {
                vehicle->setPlaceCount(tmpPlaceCount);
                break;
            }else{
                cout << "\nInvalid input, repeat..." << endl;
            }
        }
    }

    void changeModel( Vehicle * const vehicle )  ///Функция для изменения поля Model для указанного объекта Vehicle
    {
        string tmpModel;
        cout << "\nEntry model of vehicle:\t";
        cin >> tmpModel;
        vehicle->setModel( &tmpModel );
    }

    void changeColor( Vehicle * const vehicle )
    {
        cout << "\nEntry the color of the car:\t";
        string tmpColor;
        cin >> tmpColor;
        vehicle->setColor( tmpColor );
    }
