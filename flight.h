#ifndef FLIGHT_H_
#define FLIGHT_H_
#include <string>
using namespace std;

class flight{
    // Properties
    string from,to,at,dt,date;
    int cost,fNo;
    public:
        flight(){cost = 0;fNo=0;}
        //methods
        void inputFlightDetails(); // Done
        void displayFlightDetails();
};

#endif