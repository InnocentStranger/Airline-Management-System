#ifndef FLIGHT_H_
#define FLIGHT_H_
#include <string>
using namespace std;

class flight{
    // Properties
    char from[20],to[20],at[20],dt[20],date[20];
    int cost,fNo;
    public:
        flight(){cost = 0;fNo=0;from[0]='\0';to[0]='\0';at[0]='\0';dt[0]='\0';date[0]='\0';}
        //methods
        void inputFlightDetails(); // Done
        void displayFlightDetails();
        bool searchFlight(char[],char[]);
        bool operator == (flight &f);
        bool cmpFno(int fNo);
        friend class user;
};

#endif