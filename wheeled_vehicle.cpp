#include "wheeled_vehicle.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Wheeled_vehicle::Wheeled_vehicle() : Vehicle()
    {
        setBrandnameDefault();
    }

    Wheeled_vehicle::Wheeled_vehicle(
                std::string const   &brandname,
                std::string const   &model,
                std::string const   &color,
                int const           movementSpeed,
                int const           placeCount
                ) : Vehicle( model, color, movementSpeed, placeCount )
    {
        this->brandname = brandname;
    }

    Wheeled_vehicle::Wheeled_vehicle( Wheeled_vehicle const &wheeled_vehicle ) : Vehicle( wheeled_vehicle )
    {
        this->brandname = wheeled_vehicle.brandname;
    }


/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

    void Wheeled_vehicle::setBrandnameDefault()
    {
        this->brandname = "___";
    }

    void Wheeled_vehicle::print() const
    {
       std::cout <<
                "\t||\tBrandname: "     << this->brandname      <<
                "\t||\tModel: "         << this->model          <<
                "\t||\tColor: "         << this->color << "\n"  <<
                "\t||\tSpeed: "         << this->movementSpeed  <<
                "\t||\tPlaces count: "  << this->placeCount     <<
                "\t||"
        ;
    }

    void Wheeled_vehicle::showMenuActions() const{}

    void Wheeled_vehicle::setBrandname ( std::string const &brandname )
    {
        this->brandname = brandname;
    }

    std::string& Wheeled_vehicle::getBrandname ()
    {
        return brandname;
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Перегруженые операторы

    bool Wheeled_vehicle::operator == (const Wheeled_vehicle &wheeled_vehicle)
    {
        return (
                (this -> brandname == wheeled_vehicle.brandname)         &&
                (this -> model == wheeled_vehicle.model)                 &&
                (this -> color == wheeled_vehicle.color)                 &&
                (this -> movementSpeed == wheeled_vehicle.movementSpeed) &&
                (this -> placeCount == wheeled_vehicle.placeCount)
                );
    }

    bool Wheeled_vehicle::operator != (const Wheeled_vehicle &wheeled_vehicle)
    {
        return (
                ( this -> brandname != wheeled_vehicle.brandname )           ||
                ( this -> model != wheeled_vehicle.model )                   ||
                ( this -> color != wheeled_vehicle.color )                   ||
                ( this -> movementSpeed != wheeled_vehicle.movementSpeed )
                );
    }

    bool Wheeled_vehicle::operator > ( const Wheeled_vehicle &wheeled_vehicle )
    {
        if( this->brandname     <= wheeled_vehicle.brandname )
            return false;
        if( this->model         <= wheeled_vehicle.model )
            return false;
        if( this->color         <= wheeled_vehicle.color )
            return false;
        if( this->movementSpeed <= wheeled_vehicle.movementSpeed )
            return false;
        return ( this->placeCount > wheeled_vehicle.placeCount );
    }

    bool Wheeled_vehicle::operator < ( const Wheeled_vehicle &wheeled_vehicle )
    {
        if( this->brandname     >= wheeled_vehicle.brandname )
            return false;
        if( this->model         >= wheeled_vehicle.model )
            return false;
        if( this->color         >= wheeled_vehicle.color )
            return false;
        if( this->movementSpeed >= wheeled_vehicle.movementSpeed )
            return false;
        return ( this->placeCount < wheeled_vehicle.placeCount );
    }

    bool Wheeled_vehicle::operator <= (const Wheeled_vehicle &wheeled_vehicle)
    {
        if( this->brandname     > wheeled_vehicle.brandname )
            return false;
        if( this->model         > wheeled_vehicle.model )
            return false;
        if( this->color         > wheeled_vehicle.color )
            return false;
        if( this->movementSpeed > wheeled_vehicle.movementSpeed )
            return false;
        return ( this->placeCount <= wheeled_vehicle.placeCount );
    }

    bool Wheeled_vehicle::operator >= ( const Wheeled_vehicle &wheeled_vehicle )
    {
        if( this->brandname     < wheeled_vehicle.brandname )
            return false;
        if( this->model         < wheeled_vehicle.model )
            return false;
        if( this->color         < wheeled_vehicle.color )
            return false;
        if( this->movementSpeed < wheeled_vehicle.movementSpeed )
            return false;
        return ( this->placeCount >= wheeled_vehicle.placeCount );
    }

    Wheeled_vehicle& Wheeled_vehicle::operator = ( const Wheeled_vehicle &wheeled_vehicle )
    {
        this->brandname         = wheeled_vehicle.brandname;
        this-> model            = wheeled_vehicle.model;
        this-> color            = wheeled_vehicle.color;
        this-> movementSpeed    = wheeled_vehicle.movementSpeed;
        this-> placeCount       = wheeled_vehicle.placeCount;
        return *this;
    }

    std::ostream& operator << ( std::ostream &out, const Wheeled_vehicle &wheeled_vehicle )
    {
       out <<
            "\t||\tBrandname: " << wheeled_vehicle.brandname        <<
            "\t||\tModel: " << wheeled_vehicle.model                <<
            "\t||\tColor: " << wheeled_vehicle.color << std::endl   <<
            "\t||\tSpeed: " << wheeled_vehicle.movementSpeed        <<
            "\t||\tPlaces count: " << wheeled_vehicle.placeCount    <<
            "\t||"
        ;
        return out;
    }

    std::istream& operator >> ( std::istream &in, Wheeled_vehicle &wheeled_vehicle )
    {
        in >> wheeled_vehicle.brandname;
        in >> wheeled_vehicle.model;
        in >> wheeled_vehicle.color;
        in >> wheeled_vehicle.movementSpeed;
        in >> wheeled_vehicle.placeCount;
        return in;
    }
