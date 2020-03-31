#include "wheeled_vehicle.h"

string const defaultBrandname = "---";

void wheeled_vehicle :: setBrandname (string const * const brandname)
{
    this->brandname = *brandname;
}
void wheeled_vehicle :: setBrandname (string const brandname)
{
    this->brandname = brandname;
}

string& wheeled_vehicle :: getBrandname ()
{
    return brandname;
}
