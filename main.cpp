#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "vehicle.h"

#include "aeroplane.h"
#include "steamboat.h"
#include "wheeled_vehicle.h"

#include "autobus.h"
#include "Car.h"

#define min(left, right) (left < right ? left : right)
#define max(left, right) (left > right ? left : right)

int main()
{
    short   nCars = 1;
    short   nAutobus = 1;
    short   nAeroplanes = 1;
    short   nSteamboats = 1;
    Vehicle ** vehicles = new Vehicle*[5];
    vehicles[CAR]       = new Car[nCars];
    vehicles[AUTOBUS]   = new Autobus[nAutobus];
    vehicles[AEROPLANE] = new Aeroplane[nAeroplanes];
    vehicles[STEAMBOAT] = new Steamboat[nSteamboats];

    vehicles[CAR][0].print();
    std::cout << std::endl<< std::endl;
    vehicles[AUTOBUS][0].print();
    std::cout << std::endl<< std::endl;
    vehicles[AEROPLANE][0].print();
    std::cout << std::endl<< std::endl;
    vehicles[STEAMBOAT][0].print();
    std::cout << std::endl<< std::endl;
}
