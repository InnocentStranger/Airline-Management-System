#include<bits/stdc++.h>
#include "flight.cpp"
#include "user.cpp"
#include "helperFunctions.cpp"
using namespace std;
void UserMenu(){
    int choice;

    while(1){
        system("CLS");
        cout << "-----------------Airline Management System-----------------" << "\n";
        cout << " 1. View All Flight Schedules. " << "\n";
        cout << " 2. Search For A Particular Flight." << "\n";
        cout << " 3. Book a Ticket. " << "\n";
        cout << " 4. Cancel Ticket. " << "\n";
        cout << " 5. Display Ticket. " << "\n";
        cout << " 6. Exit." << "\n";
        cout << "Enter Your Choice: "; cin >> choice;
        switch(choice){
            case 1: {break;}
            case 2: {break;}
            case 3: {break;}
            case 4: {break;}
            case 5: {break;}
            case 6: {return;}
            default: { cout << "Invalid Choice."; fflush(stdin); int c=getchar();}
        }
    }
}
void AdminMenu(){
    int choice;
    while(1){
        system("CLS");       
        cout << "-----------------Airline Management System-----------------" << "\n";
        cout << " 1. Enter New Flight Schedule." << "\n";
        cout << " 2. Delete A Particular Flight Schedule. " << "\n";
        cout << " 3. Delete All Flight. " << "\n";
        cout << " 4. Return to Main Menu. " << "\n"; 
        cout << " Enter Your Choice: "; cin >> choice;
        switch(choice){
            case 1: {break;}
            case 2: {break;}
            case 3: {break;}
            case 4: {return;}
            default: { cout << "Invalid Choice."; fflush(stdin); int c=getchar();}
        }
    }
}
void MainMenu(){
    int choice;
    while(1){
        system("CLS");        
        cout << "-----------------Airline Management System-----------------" << "\n";
        cout << " 1. Admin Login." << "\n";
        cout << " 2. User Login. " << "\n";
        cout << " 3. User Signup. " << "\n";
        cout << " 4. Exit. " << "\n";
        cout << " Enter Your Choice: "; cin >> choice;
        switch(choice){
            case 1: {
                AdminMenu();break;
            }
            case 2: {
                UserMenu();break;
            }
            case 3: { break;}
            case 4: {system("CLS"); cout << "Thanks for using our Service." << endl; return;}
            default: { cout << "Invalid Choice."; fflush(stdin);int c=getchar();}
        }
    }
}
int main(){
    MainMenu();
    return 0;
}