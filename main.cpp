#include<bits/stdc++.h>
#include "flight.cpp"
#include "user.cpp"
#include "helperFunctions.cpp"
using namespace std;
void UserMenu(user &u){
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
            case 1: {displayAllFlight();fflush(stdin);char e=getchar();break;}
            case 2: {displaySpecificFlight();fflush(stdin);char e=getchar(); break;}
            case 3: {bookTicket(u);fflush(stdin);char e=getchar();break;}
            case 4: {cancelTicket(u);fflush(stdin);char e = getchar();break;}
            case 5: {displayTicket(u);break;}
            case 6: {updateUser(u);return;}
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
            case 1: {insertFlight();break;}
            case 2: {deleteSpecificFlight();fflush(stdin);char e=getchar();break;}
            case 3: {deleteAllFlight();break;}
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
                string username,password;
                cout << "Enter Username : "; cin >> username;
                cout << "Enter Password : "; cin >> password;
                if(username == "admin" && password == "admin") AdminMenu();
                else {cout << "\t Wrong Credientals. " << endl;fflush(stdin);char e=getchar();}
                break;
            }
            case 2: {
                int passNo;
                char password[20];
                cout << "Enter Your Passport No : "; cin >> passNo;
                cout << "Enter Your Password : "; cin >> password;
                pair<bool,user> flag = userLogin(passNo,password);
                if(flag.first) UserMenu(flag.second);
                else {cout << " Wrong Credientals." << "\n";fflush(stdin);char e=getchar();}

                break;
            }
            case 3: {
                addNewUser(); // With Unique Passport Number
                break;
            }
            case 4: {system("CLS"); cout << "Thanks for using our Service." << endl; return;}
            default: { cout << "Invalid Choice."; fflush(stdin);int c=getchar();}
        }
    }
}
int main(){
    MainMenu();
    return 0;
}