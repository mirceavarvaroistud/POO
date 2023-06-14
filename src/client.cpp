#include "client.h"


using namespace std;

    int Client::getIdClient()
    {
        return IdClient;
    }
    int Client::getCNP()
    {
        return CNP;
    }
    char* Client::getFirstName()
    {
        return FirstName;
    }
    char* Client::getLastName()
    {
        return LastName;
    }
    char* Client::getRentedCar()
    {
        return RentedCar;
    }
    char* Client::getStartDate()
    {
        return StartDate;
    }
    char* Client::getReturnDate()
    {
        return ReturnDate;
    }

Client::Client()
{
        IdClient = 0;
        CNP = 0;
        strcpy(FirstName, "");
        strcpy(LastName, "");
        strcpy(RentedCar, "");
        strcpy(StartDate, "");
        strcpy(ReturnDate, "");
}

void Client::GetClient()
{
    cout<<"\tIntroduce ID: ";
    cin>>IdClient;
    cout<<"\tIntroduce CNP: ";
    cin>>CNP;
    cout<<"\tIntroduce First Name: ";
    cin.get();
    cin.getline(FirstName, 20);
    cout<<"\tIntroduce Last Name: ";
    cin.getline(LastName, 20);
    cout<<"\tIntroduce Rented Car: ";
    cin.getline(RentedCar, 20);
    cout<<"\tIntroduce Start Date: ";
    cin.getline(StartDate, 20);
    cout<<"\tIntroduce Return Date: ";
    cin.getline(ReturnDate, 20);
    cout<<endl;
}

void Client::ShowClient()
{
    cout<<endl;
    cout<<"ID Client: "<<IdClient<<endl;
    cout<<"CNP: "<<CNP<<endl;
    cout<<"First Name: "<<FirstName<<endl;
    cout<<"Last Name: "<<LastName<<endl;
    cout<<"Rented Car: "<<RentedCar<<endl;
    cout<<"Start Date: "<<StartDate<<endl;
    cout<<"Return Date: "<<ReturnDate<<endl;
}

void Client::ClientHeader()
{
    cout.setf(ios::left);
    cout<<setw(5)<<"ID"
        <<setw(12)<<"CNP"
        <<setw(15)<<"First Name"
        <<setw(15)<<"Last Name"
        <<setw(25)<<"Rented Car"
        <<setw(15)<<"Start Date"
        <<setw(15)<<"Return Date"<<endl;
    for(int i=1; i<=89; i++)
        cout<<"=";
    cout<<endl;
}

void Client::ClientListView()
{
    cout.setf(ios::left);
    cout<<setw(5)<<IdClient
        <<setw(12)<<CNP
        <<setw(15)<<FirstName
        <<setw(15)<<LastName
        <<setw(25)<<RentedCar
        <<setw(15)<<StartDate
        <<setw(15)<<ReturnDate<<endl;
}
