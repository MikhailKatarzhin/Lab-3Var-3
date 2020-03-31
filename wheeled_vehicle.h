#include "vehicle.h"
#include <string>

class wheeled_vehicle: public vehicle
{
protected:
    string brandname;
public:
    static string const defaultBrandname;
    void setBrandname (string const * const brandname);
    void setBrandname (string const brandname);
    string& getBrandname ();
};
