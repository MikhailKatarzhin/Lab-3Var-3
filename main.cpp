#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "vehicle.h"

#include "aeroplane.h"
#include "steamboat.h"
#include "wheeled_vehicle.h"

#include "autobus.h"
#include "Car.h"

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

    std::cout << "SModel:\t" << vehicles[STEAMBOAT][0].getModel() << std::endl;
    std::cout << "SColor:\t" << vehicles[STEAMBOAT][0].getColor() << std::endl;
    std::cout << "SMovementSpeed:\t" << vehicles[STEAMBOAT][0].getMovementSpeed() << std::endl;
    std::cout << "SPlaceCount:\t" << vehicles[STEAMBOAT][0].getPlaceCount() << std::endl;
    std::cout << "STonnage:\t" << ((Steamboat*) &(vehicles[STEAMBOAT][0]))->getTonnage() << std::endl;
    std::cout << "AeFlight_Hours:\t" << ((Aeroplane*) &(vehicles[AEROPLANE][0]))->getFlight_Hours() << std::endl;
}
