#include <iostream>
#include "display.h"

using namespace std;

int main()
{


    int ch;
    do
    {
        system("clear");
        cout<<"RENTAL MANAGER\n";
        cout<<"0. EXIT.\n";
        cout<<"1. Car menu\n";
        cout<<"2. Client menu\n";
        cout<<"Select option: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            carMenu();
            break;
        case 2:
            clientMenu();
            break;
        }
    }
    while(ch!=0);
    return 0;
}
