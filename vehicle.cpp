#include "Vehicle.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Vehicle::Vehicle()
    {
        setModelDefault();
        setColorDefault();
        setPlaceCountDefault();
        setMovementSpeedDefault();
    }

    Vehicle::Vehicle(
            std::string const   &model,
            std::string const   &color,
            int const           movementSpeed,
            int const           placeCount
            )
    {
        setModel        ( model );
        setColor        ( color );
        setMovementSpeed( movementSpeed );
        setPlaceCount   ( placeCount );
    }

    Vehicle::Vehicle( Vehicle const &vehicle )
    {
        setModel        ( vehicle.model );
        setColor        ( vehicle.color );
        setMovementSpeed( vehicle.movementSpeed );
        setPlaceCount   ( vehicle.placeCount );
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Vehicle::setModelDefault()
    {
        this->model = "Model#0";
    }
    void Vehicle::setColorDefault()
    {
        this->color = "UNKNOWN";
    }
    void Vehicle::setPlaceCountDefault()
    {
        this->placeCount = 1;
    }
    void Vehicle::setMovementSpeedDefault()
    {
        this->movementSpeed = 0;
    }


    void Vehicle::print() const
    {
       std::cout                    << " || "               <<
                "Type Vehicle:\t"   << getVehicleTypeName() << "\t|| " <<
                "Model:\t"          << this->model          << "\t|| " <<
                "Speed:\t"          << this->movementSpeed  << "\t|| " <<
                std::endl           << " || "               <<
                "Places count:\t"   << this->placeCount     << "\t|| " <<
                "Color:\t"          << this->color          << "\t|| "
                ;
    }


    void Vehicle::setModel( std::string const &model )
    {
        this->model = model;
    }
    std::string Vehicle::getModel() const
    {
        return model;
    }



    void Vehicle::setColor( std::string const &color )
    {
        this->color = color;
    }
    std::string Vehicle::getColor() const
    {
        return color;
    }



    void Vehicle::setMovementSpeed( int const movementSpeed )
    {
        this->movementSpeed = (int)movementSpeed;
    }
    void Vehicle::setMovementSpeed( short int const movementSpeed )
    {
        this->movementSpeed = (int)movementSpeed;
    }
    void Vehicle::setMovementSpeed( unsigned int const movementSpeed )
    {
        this->movementSpeed = (int)movementSpeed;
    }
    void Vehicle::setMovementSpeed( unsigned short int const movementSpeed )
    {
        this->movementSpeed = (int)movementSpeed;
    }
    void Vehicle::setMovementSpeed( std::string const &movementSpeed )
    {
        std::istringstream bufferStream(movementSpeed);
        bufferStream >> this->movementSpeed;
    }
    int Vehicle::getMovementSpeed() const
    {
        return movementSpeed;
    }



    void Vehicle::setPlaceCount( int const placeCount )
    {
        this->placeCount = (unsigned int)placeCount;
    }
    void Vehicle::setPlaceCount( short int const placeCount )
    {
        this->placeCount = (unsigned int)placeCount;
    }
    void Vehicle::setPlaceCount( unsigned int const placeCount )
    {
        this->placeCount = (unsigned int)placeCount;
    }
    void Vehicle::setPlaceCount( unsigned short int const placeCount )
    {
        this->placeCount = (unsigned int)placeCount;
    }
    void Vehicle::setPlaceCount( std::string const &placeCount )
    {
        int tmpPlaceCount;
        std::istringstream bufferStream( placeCount );
        bufferStream >> tmpPlaceCount;
        if( tmpPlaceCount >= 1 )
        this->placeCount = (unsigned int)tmpPlaceCount;
    }
    unsigned int Vehicle::getPlaceCount() const
    {
        return placeCount;
    }

    VehicleType Vehicle::getVehicleType() const
    {
        return type;
    }
    std::string Vehicle::getVehicleTypeName() const
    {
        switch( type )
        {
            case UNKNOWN    :
                {
                    std::string tmp = "UNKNOWN";
                    return tmp;
                }
            case CAR        :
                {
                    std::string tmp = "CAR";
                    return tmp;
                }
            case AUTOBUS    :
                {
                    std::string tmp = "AUTOBUS";
                    return tmp;
                }
            case AEROPLANE  :
                {
                    std::string tmp = "AEROPLANE";
                    return tmp;
                }
            case STEAMBOAT  :
                {
                    std::string tmp = "STEAMBOAT";
                    return tmp;
                }
        }
        std::string tmp = "UNKNOWN";
        return tmp;
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
        if( this->placeCount > 2 )
        this->placeCount -=2;
        return *this;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Функции

    void changeMovementSpeed( Vehicle &vehicle )
    {
        short   tmpSpeed;
        while( true )
        {
            std::cout   << "\nEntry speed of vehicle( more than 0 ):\t";
            std::string buffer;
            std::cin    >> buffer;
            std::istringstream bufferStream( buffer );
            bufferStream >> tmpSpeed;
            if( tmpSpeed > 0 )
            {
                vehicle.setMovementSpeed( tmpSpeed );
                break;
            }else{
                std::cout << "\nInvalid input, repeat...\n";
            }
        }
    }

    void changePlaceCount( Vehicle &vehicle )
    {
        short   tmpPlaceCount;
        while( true )
        {
            std::cout   << "\nEntry place count of vehicle( more than 0 ):\t";
            std::string buffer;
            std::cin    >> buffer;
            std::istringstream bufferStream( buffer );
            bufferStream >> tmpPlaceCount;
            if( tmpPlaceCount > 0 )
            {
                vehicle.setPlaceCount( tmpPlaceCount );
                break;
            }else{
                std::cout << "\nInvalid input, repeat...\n";
            }
        }
    }

    void changeModel( Vehicle &vehicle )
    {
        std::string tmpModel;
        std::cout   << "\nEntry model of vehicle:\t";
        std::cin    >> tmpModel;
        vehicle.setModel( tmpModel );
    }

    void changeColor( Vehicle &vehicle )
    {
        std::cout   << "\nEntry the color of the car:\t";
        std::string tmpColor;
        std::cin    >> tmpColor;
        vehicle.setColor( tmpColor );
    }
