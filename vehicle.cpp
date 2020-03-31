#include "vehicle.h"

    void vehicle :: setMovementSpeed(int const movementSpeed)
    {
        this -> movementSpeed = (int)movementSpeed;
    }
    void vehicle :: setMovementSpeed(short int const movementSpeed)
    {
        this -> movementSpeed = (int)movementSpeed;
    }
    void vehicle :: setMovementSpeed(unsigned int const movementSpeed)
    {
        this -> movementSpeed = (int)movementSpeed;
    }
    void vehicle :: setMovementSpeed(unsigned short int const movementSpeed)
    {
        this -> movementSpeed = (int)movementSpeed;
    }

    int vehicle :: getMovementSpeed() const
    {
        return movementSpeed;
    }

    void vehicle :: setPlaceCount(unsigned int const placeCount)
    {
        this -> placeCount = (unsigned int)placeCount;
    }
    void vehicle :: setPlaceCount(unsigned short int const placeCount)
    {
        this -> placeCount = (unsigned int)placeCount;
    }

    unsigned int vehicle :: getPlaceCount() const
    {
        return placeCount;
    }
