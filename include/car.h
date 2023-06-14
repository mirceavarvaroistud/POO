#ifndef CAR_H
#define CAR_H
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <ios>
#include <iosfwd>


class Car
{

    int Id;
    char Model[20];
    char Mark[20];
    char RegNb[20];
    char VIN[20];
public:
    Car();
    int getID();
    char* getModel();
    char* getMark();
    char* getRegNb();
    char* getVIN();


    void getCar();
    void listView();
    void showCar();
    void header();
};


#endif // CAR_H
