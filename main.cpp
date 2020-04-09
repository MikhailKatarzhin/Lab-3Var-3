#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "vehicle.h"
#include "wheeled_vehicle.h"
#include "Car.h"
#include "autobus.h"
#include "aeroplane.h"
#include "steamboat.h"

#define min(left, right) (left < right ? left : right)
#define max(left, right) (left > right ? left : right)

using namespace std;


void resizeCars( Car ** cars, short const size, short const newSize )
{
    Car *newCars = new Car[newSize];
    for( short i = 0; i < min( size, newSize ); ++i )
    {
        newCars[i] = cars[0][i];
    }
    delete[] cars[0];
    *cars=newCars;
}

Car* resizeCars( Car const * const cars, short const size, short const newSize )
{
    Car *newCars = new Car[newSize];
    for( short i = 0; i < min( size, newSize ); ++i )
    {
        newCars[i] = cars[i];
    }
    delete[] cars;
    return newCars;
}

void addSomeCar( Car ** cars, short * const countOfCar )
{
    short   addCount = 0;
    while( addCount < 1 )
    {
        cout << "How many car add in database?" << endl;
        string buffer;
        cin >> buffer;
        istringstream bufferStream(buffer);
        bufferStream >> addCount;
        if( addCount > 0 )
        {
            break;
        }else{
            cout << "\nInvalid input, repeat..." << endl;
        }
    }
    //cars = resizeCars(cars, countOfCar, countOfCar + addCount);
    resizeCars( cars, *( countOfCar ), *( countOfCar )+addCount );
    *( countOfCar ) += addCount;
    for( ; 0 < addCount; --addCount )
    {
        system( "cls" );
        while( 1 )
        {
            cout << "\nCar #" << *( countOfCar )-addCount+1 << " \n|| Model ||\t|| Speed ||\t|| Color ||" << endl;
            cin >> cars[0][*( countOfCar )-addCount];
            if( cars[0][*( countOfCar )-addCount].getMovementSpeed() > 0 )
            {
                break;
            }else{
                cout << "\nInvalid input speed, repeat..." << endl;
            }
        }
    }
}

int main()
{

    short   countOfCar = 1;
    short   countOfAutobus = 0;
    short   countOfAeroplane = 0;
    short   countOfSteamboat = 0;
    short   i = 0;
    Vehicle ** vehicles = new Vehicle*[5];
    vehicles[CAR] = new Car[countOfCar];
    vehicles[AUTOBUS] = new Autobus[countOfAutobus];
    vehicles[AEROPLANE] = new Aeroplane[countOfAeroplane];
    vehicles[STEAMBOAT] = new Steamboat[countOfSteamboat];
    Car *cars = new Car[1];
    while( countOfCar )
    {
        system( "cls" );
        cout << "\n\t\t\t***Car's database***\n\n";
        showAllCars( countOfCar, cars );
        i = requestNumberOfCar( countOfCar );
        if( 0 == i )
        {
            delete[] cars;
            return 0;
        }

        while( i != 0 )
        {
            system( "cls" );
            cout << "\nYou are working with car #" << i << "\t" << cars[i-1] << endl; ///Падает тут
            cars[i-1].showMenuActions();
            short var;
            string buffer;
            cin >> buffer;
            istringstream bufferStream(buffer);
            bufferStream >> var;
            switch( var )
            {
                case 0:
                    i = 0;
                    break;
                case 1:
                    system( "cls" );
                    changeModel( &vehicles[CAR][i-1] );
                    break;
                case 2:
                    system( "cls" );
                    changeMovementSpeed( &vehicles[CAR][i-1] );
                    break;
                case 3:
                    system( "cls" );
                    changeColor( &vehicles[CAR][i-1] );
                    break;
                case 4:{
                    cars = resizeCars( cars, countOfCar, countOfCar+1 );
                    //resizeCars(&cars, countOfCar, countOfCar+1);
                    ++countOfCar;
                    cars[countOfCar-1] = cars[i-1];
                    break;}
                case 5:{
                    cars[i-1] = cars[countOfCar-1];
                    cars = resizeCars( cars, countOfCar, countOfCar-1 );
                    //resizeCars(&cars, countOfCar, countOfCar-1);
                    --countOfCar;
                    i = 0;
                    break;}
                case 6:
                    addSomeCar( &cars, &countOfCar );
                    break;
                case 7:
                    ( ++cars[i-1] ) ++;
                    break;
                case 8:
                    ( --cars[i-1] ) --;
                    break;
                case 9:
                    short y;
                    do{
                        cout << "\nSelect enemy for battle(to " << countOfCar <<"): ";
                        cin >> y;
                    }while( ( y < 0 )||( y > countOfCar ) );
                    if( ( cars[i-1] ).getMovementSpeed() < cars[y-1].getMovementSpeed() )
                    {
                        system( "cls" );
                        cout << "\n\n\t!!!Win car... IN RIGHT CONNER!!!" << endl;
                        system( "pause" );
                        ++cars[y-1];
                        cars[y-1]++;
                        cars[i-1] = cars[countOfCar-1];
                        cars = resizeCars( cars, countOfCar, countOfCar-1 );
                        //resizeCars(&cars, countOfCar, countOfCar-1);
                        --countOfCar;
                    }else{
                        if( cars[i-1].getMovementSpeed()== cars[y-1].getMovementSpeed() )
                        {
                            system( "cls" );
                            cout << "\n\n\tWin car... No, no winner... Both rivals fell.." << endl;
                            system( "pause" );
                            --cars[i-1];
                            --cars[y-1];
                        }else{
                            if( cars[i-1].getMovementSpeed() > cars[y-1].getMovementSpeed() )
                            {
                                system( "cls" );
                                cout << "\n\n\n\t\t!!!Win car... IN LEFT CONNER!!!" << endl;
                                system( "pause" );
                                ++cars[i-1];

                                cars[y-1] = cars[countOfCar-1];
                                cars = resizeCars( cars, countOfCar, countOfCar-1 );
                                //resizeCars(&cars, countOfCar, countOfCar-1);
                                --countOfCar;
                            }
                        }
                    }
                    i = 0;
                    break;
            }
        }
    }
    if( countOfCar == 0 )
    {
        system( "cls" );
        showAllCars( countOfCar, cars );
        cout << "\n\n\t||**||\tWe're out of cars\t||**||\n\n";
    }
}
