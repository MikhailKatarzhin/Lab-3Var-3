#include "Vehicle.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

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
