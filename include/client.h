#ifndef CLIENT_H
#define CLIENT_H
#include <car.h>

using namespace std;

class Client : public Car
{
    int IdClient;
    int CNP;
    char FirstName[20];
    char LastName[20];
    char RentedCar[20];
    char StartDate[20];
    char ReturnDate[20];

public:

    int getIdClient();
    int getCNP();
    char* getFirstName();
    char* getLastName();
    char* getRentedCar();
    char* getStartDate();
    char* getReturnDate();

    Client();
    void GetClient();
    void ShowClient();
    void ClientHeader();
    void ClientListView();
};

#endif // CLIENT_H
