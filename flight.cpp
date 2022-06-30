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

    void flight::displayFlightDetails(){

       cout << "\t"; cout << "  " <<
       left << setw(15) << fNo  << "| " 
       << setw(15) << from  << "| "  << 
       setw(15) << to  << "| "  
       << setw(15) << dt <<  "| "  << 
       setw(15) << at <<  "| " 
       << setw(15) << date <<  "| "  <<
       setw(15) << cost << " " << endl;
    }
    bool flight::searchFlight(char to[],char from[]){
            if(strcmp(this->to,to)==0 && strcmp(this->from,from)==0) return true;
            return false;
    }
    bool flight::operator == (flight &f){
        if(this->fNo == f.fNo) return true;
        return false;
    }
    bool flight::cmpFno(int fNo){
        if(this->fNo == fNo) return true;
        return false;
    }
#endif
