#include "car.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <ios>
#include <iosfwd>

using namespace std;

int Car::getID()
{
    return Id;
}
char* Car::getModel()
{
    return Model;
}
char* Car::getMark()
{
    return Mark;
}
char* Car::getRegNb()
{
    return RegNb;
}
char* Car::getVIN()
{
    return VIN;
}

Car::Car()
{
    Id = 0;
    strcpy(Mark, "");
    strcpy(Model, "");
    strcpy(RegNb, "");
    strcpy(VIN, "");
}

void Car::getCar()
{
    cout<<"\tIntroduce Car Id: ";
    cin>>Id;
    cin.get();
    cout<<"\tIntroduce Car Mark: ";
    cin.getline(Mark, 20);
    cout<<"\tIntroduce Car Model: ";
    cin.getline(Model, 20);
    cout<<"\tIntroduce Registration Number: ";
    cin.getline(RegNb, 20);
    cout<<"\tIntroduce VIN: ";
    cin.getline(VIN, 20);
    cout<<endl;
}

void Car::showCar()
{
    cout<<endl;
    cout<<"ID: "<<Id<<endl;
    cout<<"Car Mark: "<<Mark<<endl;
    cout<<"Car Model: "<<Model<<endl;
    cout<<"Car Registration Number: "<<RegNb<<endl;
    cout<<"Car VIN: "<<VIN<<endl;
}

void Car::header()
{
    cout.setf(ios::left);
    cout<<setw(5)<<"ID"
        <<setw(20)<<"Car Mark"
        <<setw(20)<<"Car Model"
        <<setw(20)<<"Registration Number"
        <<setw(20)<<"VIN"<<endl;
    for(int i=1; i<=80; i++)
        cout<<"=";
    cout<<endl;
}

void Car::listView()
{
    cout.setf(ios::left);
    cout<<setw(5)<<Id
        <<setw(20)<<Mark
        <<setw(20)<<Model
        <<setw(20)<<RegNb
        <<setw(20)<<VIN<<endl;
}
