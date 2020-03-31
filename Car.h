#include <string>
#include "wheeled_vehicle.h"

using namespace std;
class Car : public wheeled_vehicle
{
protected:
    string model;
    string color;
public:
    Car();
    Car(string const * const model_in, int speed_in, string const * const color_in);
    Car(Car const &car);
    void print() const;
    void setModel(string const * const model_in);
    void setModel(string const model_in);
    void setColor(string const * const color_in);
    void setColor(string const color_in);

    Car& operator ++();
    Car operator ++(int);
    Car& operator --();
    Car operator --(int);
    bool operator == (const Car &car_in);
    bool operator != (const Car &car_in);
    bool operator > (const Car &car_in);
    bool operator < (const Car &car_in);
    bool operator <= (const Car &car_in);
    bool operator >= (const Car &car_in);
    Car& operator = (const Car &car_in);
    friend ostream& operator << (ostream &out, const Car &car_in);
    friend istream& operator >> (istream &in, Car &car_in);

    string& getModel();
private:
    string& getColor();
};
