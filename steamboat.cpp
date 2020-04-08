#include "Steamboat.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// Конструкторы

    Steamboat::Steamboat()
    {
        type = STEAMBOAT;
        setModel("Model#0");
        setColor("UNKNOWN");
        setPlaceCount(defaultPlaceCount);
        setMovementSpeed(defaultMovementSpeed);
        setTonnage(0);
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Steamboat::Steamboat(
                string const * const model_in,
                string const * const color_in,
                int const movementSpeed_in,
                int const placeCount_in,
                int const tonnage)
    {
        type = STEAMBOAT;
        this -> model = *(model_in);
        this -> color = *(color_in);
        this -> movementSpeed = movementSpeed_in;
        this -> placeCount = placeCount_in;
        this -> tonnage = tonnage;
        ///cout << "\nConstruction... " << this;    ///лог о создании
    }

    Steamboat::Steamboat(Steamboat const &otherSteamboat)
    {
        type = STEAMBOAT;
        this -> model = otherSteamboat.model;
        this -> color = otherSteamboat.color;
        this -> movementSpeed = otherSteamboat.movementSpeed;
        this -> placeCount = otherSteamboat.placeCount;
        this -> tonnage = otherSteamboat.tonnage;
        ///cout << "\nConstruction copy... " << this;   ///лог о создании
    }

/// ///////////////////////////////////////////////////////////////////////////////
/// Методы

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
/// Перегруженые операторы

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

    ostream& operator << (ostream &out, const Steamboat &steamboat_in)  ///вывод полной информации в 2 строки об автомобиле
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

    istream& operator >> (istream &in, Steamboat &steamboat_in) ///последовательный ввод полной информации о легковом автомобиле
    {
        in >> steamboat_in.model;
        in >> steamboat_in.color;
        in >> steamboat_in.movementSpeed;
        in >> steamboat_in.placeCount;
        in >> steamboat_in.tonnage;
        return in;
    }
