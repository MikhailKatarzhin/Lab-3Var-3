#include "Car.h"

/// ///////////////////////////////////////////////////////////////////////////////
/// ������������

using namespace std;

///������ �����������
Car::Car()
{
    type = CAR;
    setBrandname("___");
    setModel("Model#0");
    setColor("UNKNOWN");
    setPlaceCount(defaultPlaceCount);
    setMovementSpeed(defaultMovementSpeed);
    ///cout << "\nConstruction... " << this;    ///��� � ��������
}
///����������� � �����������
Car::Car(string const * const brandname_in
           , string const * const model_in
           , string const * const color_in
           , int const movementSpeed_in
           , int const placeCount_in)
{
    type = CAR;
    this -> brandname = *(brandname_in);
    this -> model = *(model_in);
    this -> color = *(color_in);
    this -> movementSpeed = movementSpeed_in;
    this -> placeCount = placeCount_in;
    ///cout << "\nConstruction... " << this;    ///��� � ��������
}
///����������� �����������
Car::Car(Car const &otherCar)
{
    type = CAR;
    this -> brandname = otherCar.brandname;
    this -> model = otherCar.model;
    this -> color = otherCar.color;
    this -> movementSpeed = otherCar.movementSpeed;
    this -> placeCount = otherCar.placeCount;
    ///cout << "\nConstruction copy... " << this;   ///��� � ��������
}

/// ///////////////////////////////////////////////////////////////////////////////
/// ������

void Car::showMenuActions() ///����� �� ����� ���� ������ �������� � �������� Car
{
    cout << "\n\t\t\t***Menu***" << endl;
    cout << "\t0)Menu up" << endl;
    cout << "\t1)Set model of car" << endl;
    cout << "\t2)Set speed of car" << endl;
    cout << "\t3)Set color of car" << endl;
    cout << "\t4)Create a duplicate of this car" << endl;
    cout << "\t5)Delete this car" << endl;
    cout << "\t6)Add some cars" << endl;
    cout << "\t7)Upgrade car" << endl;
    cout << "\t8)Downgrade car" << endl;
    cout << "\t9)Battle between cars!!!" << endl;
}


/// ///////////////////////////////////////////////////////////////////////////////
/// ������������ ���������

/// ///////////////////////////////////////////////////////////////////////////////
/// �������

void showAllCars( short countOfCar, Car const * const cars )    ///����� �� ����� ����� ������ ������������ �������� Car
{
    for (short i = 0; i < countOfCar; i++)
    {
        cout << "\n" << i+1 << ")";
        cars[i].print();
    }
}

short requestNumberOfCar( short const countOfCar )  ///������ ����� ������ ����� �������� Car � ���������
{
    short i;
    do{
        cout << "\n\nEntry number of car(to " << countOfCar << ") or close program(input 0)\n" << endl;
        string buffer;
        cin >> buffer;
        istringstream bufferStream(buffer);
        bufferStream >> i;
    }while( ( i < 0 )||( i > countOfCar ) );
    return i;
}
