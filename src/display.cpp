#include <iostream>
#include <string.h>
#include <stdio.h>
#include "display.h"
#include "client.h"
#include "car.h"

using namespace std;

void addCar()
{
    Car l;
    ofstream fout;
    fout.open("cars.bin", ios::app);
    l.getCar();
    fout.write((char*)&l, sizeof(l));
    cout<<"Car info has been saved\n";
    fout.close();
}

void addClient()
{
    Client s;
    ofstream fout;
    fout.open("clients.bin", ios::app);
    s.GetClient();
    fout.write((char*)&s, sizeof(s));
    cout<<"Client info has been saved\n";
    fout.close();
}

void displayCar()
{
    Car l;
    int stall;
    ifstream fin("cars.bin");
    int rec = 0;
    system("clear");
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(rec<1)
            l.header();
        l.listView();
        rec++;
    }
    fin.close();
    cout<<"\nThere is a total of "<<rec<<" cars stored...\n";
    cout<<"\nPress 0  to return to menu\n";
    cin>>stall;
}

void modify()
{
    Car l;
    int n, flag=0,pos;
    fstream fin("cars.bin", ios::in|ios::out);
    cout<<"Introduce car ID: ";
    cin>>n;
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(n==l.getID())
        {
            pos=fin.tellg();
            cout<<"Modifying data...\n";
            l.showCar();
            flag++;
            fin.seekg(pos-sizeof(l));
            l.getCar();
            fin.write((char*)&l,sizeof(l));
            cout<<"\nSuccessfuly modified data...\n";
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Number of cars with ID-ul: "<<n<<" not available...\n";
}

void searchbyID()
{
    Car l;
    int n, flag=0;
    ifstream fin("cars.bin");
    cout<<"Introduce car Id to be searched: ";
    cin>>n;
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(n==l.getID())
        {
            l.showCar();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Car with Id: "<<n<<" is not available...\n";
}

void searchByMark()
{
    Car l;
    int flag=0;
    char mark[20];
    ifstream fin("cars.bin");
    cout<<"Introduce car mark to be searched: ";
    cin.ignore();
    cin.getline(mark, 20);
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(strcasecmp(mark, l.getMark())==0)
        {
            l.showCar();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Car of mark: "<<mark<<"is not available...\n";
}

void searchByModel()
{
    Car l;
    int flag=0, rec=0;
    char model[20];
    ifstream fin("cars.bin");
    cout<<"Introduce car model to be searched: ";
    cin.ignore();
    cin.getline(model, 20);
    while(fin.read((char*)&l,sizeof(l)))
    {
        if (strcasecmp(model, l.getModel())==0)
        {
            if(rec<1)
                l.header();
            l.listView();
            flag++;
            rec++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Car of model: "<<model<<" is not available...\n";
}

void searchByRegNumber()
{
    Car l;
    int flag=0, rec=0;
    char regnb[20];
    ifstream fin("cars.bin");
    cout<<"Introduce registration number to be searched: ";
    cin.ignore();
    cin.getline(regnb,20);
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(strcasecmp(regnb, l.getRegNb())==0)
        {
            if(rec<1)
                l.header();
            l.listView();
            flag++;
            rec++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Car with registration number: "<<regnb<<" is not available...\n";
}

void displayClient()
{
    Client s;
    int stall;
    ifstream fin("clients.bin");
    int rec = 0;
    system("clear");
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(rec<1)
            s.ClientHeader();
        s.ClientListView();
        rec++;
    }
    fin.close();
    cout<<"\nThere are a total of " <<rec<< " stored...\n";
    cout<<"\nPress 0  to return to menu\n";
    cin>>stall;
}

void modifyClient()
{
    Client s;
    int n, flag=0,pos;
    fstream fin("clients.bin", ios::in|ios::out);
    cout<<"Introduce client Id: ";
    cin>>n;
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(n==s.getIdClient())
        {
            pos=fin.tellg();
            cout<<"Following data will be modified...\n";
            s.ShowClient();
            flag++;
            fin.seekg(pos-sizeof(s));
            s.GetClient();
            fin.write((char*)&s,sizeof(s));
            cout<<"\nData modified with success...\n";
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Client number Id: "<<n<<" is not available...\n";
}

void searchByIdClient()
{
    Client s;
    int n, flag=0;
    ifstream fin("clients.bin");
    cout<<"Introduce client Id: ";
    cin>>n;
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(n==s.getIdClient())
        {
            s.ShowClient();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Client with Id: "<<n<<" is not available...\n";
}

void searchByFirstName()
{
    Client s;
    int flag=0;
    char FirstName[20];
    ifstream fin("clients.bin");
    cout<<"Introduce client first name to be searched: ";
    cin.ignore();
    cin.getline(FirstName, 20);
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(strcasecmp(FirstName, s.getFirstName())==0)
        {
            s.ShowClient();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Client with first name: "<<FirstName<<"is not available...\n";
}

void searchByLastName()
{
    Client s;
    int flag=0;
    char LastName[20];
    ifstream fin("clients.bin");
    cout<<"Introduce client last name: ";
    cin.ignore();
    cin.getline(LastName, 20);
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(strcasecmp(LastName, s.getLastName())==0)
        {
            s.ShowClient();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"Client sith last name: "<<LastName<<"is not available..\n";
}

void searchByRentedCar()
{
    Client s;
    int flag=0;
    char RentedCar[20];
    ifstream fin("clients.bin");
    cout<<"Introduce rented car to be searched: ";
    cin.ignore();
    cin.getline(RentedCar, 20);
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(strcasecmp(RentedCar, s.getRentedCar())==0)
        {
            s.showCar();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"No client rented: "<<RentedCar<<"\n";
}

void searchByStartDate()
{
    Client s;
    int flag=0;
    char StartDate[20];
    ifstream fin("clients.bin");
    cout<<"Introduce start date to search: ";
    cin.ignore();
    cin.getline(StartDate, 20);
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(strcasecmp(StartDate, s.getStartDate())==0)
        {
            s.ShowClient();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"No car rented at that date: "<<StartDate<<"\n";
}

void searchByReturnDate()
{
    Client s;
    int flag=0;
    char ReturnDate[20];
    ifstream fin("clients.bin");
    cout<<"Introduce return date: ";
    cin.ignore();
    cin.getline(ReturnDate, 20);
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(strcasecmp(ReturnDate, s.getReturnDate())==0)
        {
            s.ShowClient();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"No client rented this car: "<<ReturnDate<<"\n";
}

void deleteClient(int n)
{
    Client s;
    ifstream inFile;
    ofstream outFile;
    inFile.open("clients.bin", ios::binary);
    if(!inFile)
    {
        cout << "File open failed";
        return;
    }
    outFile.open("deleteclient.bin", ios::binary);
    inFile.seekg(0, ios::beg);
    while(inFile.read(reinterpret_cast<char*>(&s), sizeof(Client)))
    {
        if(s.getIdClient() != n)
        {
            outFile.write(reinterpret_cast<char*>(&s),sizeof(Client));
        }
    }
    inFile.close();
    outFile.close();
    remove("clients.bin");
    rename("deleteclient.bin", "clients.bin");
    cout <<"\nClient was deleted!";
}

void deleteCar(int n)
{
    Car l;
    ifstream inFile;
    ofstream outFile;
    inFile.open("cars.bin", ios::binary);
    if(!inFile)
    {
        cout << "File open failed";
        return;
    }
    outFile.open("deletecar.bin", ios::binary);
    inFile.seekg(0, ios::beg);
    while(inFile.read(reinterpret_cast<char*>(&l), sizeof(Car)))
    {
        if(l.getID() != n)
        {
            outFile.write(reinterpret_cast<char*>(&l),sizeof(Car));
        }
    }
    inFile.close();
    outFile.close();
    remove("cars.bin");
    rename("deletecar.bin", "cars.bin");
    cout <<"\nCar was deleted!";
}

void carSearchMenu()
{
    int ch;
    do
    {
        system("clear");
        cout<<"CAR SEARCH\n";
        cout<<"0. Back\n";
        cout<<"1. Search by ID\n";
        cout<<"2. Search by mark:\n";
        cout<<"3. Search by model:\n";
        cout<<"4. Search by registration number:\n";
        cout<<"5. Search by VIN\n";
        cout<<"Select option: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            searchbyID();
            break;
        case 2:
            searchByMark();
            break;
        case 3:
            searchByModel();
            break;
        case 4:
            searchByRegNumber();
            break;
        default:
            cout<<"\a";
        }
    }
    while(ch!=0);
}

void clientSearchMenu()
{
    int ch;
    do
    {
        system("clear");
        cout<<"CLIENT SEARCH\n";
        cout<<"0. Back\n";
        cout<<"1. Search by ID\n";
        cout<<"2. Search by first name\n";
        cout<<"3. Search by last name\n";
        cout<<"4. Search by CNP\n";
        cout<<"5. Search by start date\n";
        cout<<"6. Search by return date\n";
        cout<<"Select option: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            searchByIdClient();
            break;
        case 2:
            searchByFirstName();
            break;
        case 3:
            searchByLastName();
            break;
        case 4:
            searchByRentedCar();
            break;
        case 5:
            searchByStartDate();
            break;
        case 6:
            searchByReturnDate();
            break;
        default:
            cout<<"\a";
        }
    }
    while(ch!=0);
}

void carMenu()
{
    int ch;
    int nr;
    do
    {
        system("clear");
        cout<<"CAR MENU\n";
        cout<<"0. Back to main menu\n";
        cout<<"1. Add a car\n";
        cout<<"2. Print all cars\n";
        cout<<"3. Search for a car\n";
        cout<<"4. Delete car\n";
        cout<<"5. Modify car details\n";
        cout<<"Select option: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            addCar();
            break;
        case 2:
            displayCar();
            break;
        case 3:
            carSearchMenu();
            break;
        case 4:
            cout<<"Introduce car ID: \n";
            cin>>nr;
            deleteCar(nr);
            break;
        case 5:
            modify();
            break;
        }
    }
    while(ch!=0);
}

void clientMenu()
{
    int ch;
    int nr;
    do
    {
        system("clear");
        cout<<"CLIENT MENU\n";
        cout<<"0. Back to main menu\n";
        cout<<"1. Add client\n";
        cout<<"2. Print client\n";
        cout<<"3. Search client\n";
        cout<<"4. Modify client info\n";
        cout<<"5. Delete client\n";
        cout<<"Select option: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            addClient();
            break;
        case 2:
            displayClient();
            break;
        case 3:
            clientSearchMenu();
            break;
        case 4:
            modifyClient();
            break;
        case 5:
            cout<<"Introduce client ID: \n";
            cin>>nr;
            //deleteClient(nr);
            break;
        default:
            cout<<"\a";
        }
    }
    while(ch!=0);
}
