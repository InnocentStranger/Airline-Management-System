#ifndef FLIGHT_CPP_
#define FLIGHT_CPP_

#include<bits/stdc++.h>
#include "flight.h"
using namespace std;

    void flight::inputFlightDetails(){
        system("CLS");
        cout << "Enter Flight Details: " << endl;
        cout << "Enter Flight Number: ";  cin >> fNo;
        cout << "Enter Departure Time: "; cin >> dt;
        cout << "Enter Arrival Time: "; cin >> at;
        cout << "Starting From: "; cin >> from;
        cout << "Enter Destination:"; cin >> to;
        cout << "Enter Flight Date:"; cin >> date;
        cout << "Enter Flight Cost:"; cin >> cost;
    }

#endif