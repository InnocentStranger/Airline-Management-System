#ifndef USER_CPP_
#define USER_CPP_

#include<bits/stdc++.h>
#include "user.h"
#include "flight.h"
using namespace std;
// Helper Function for Orientation
string center(const string s, const int w) {
	stringstream ss, spaces;
	int padding = w - s.size();                 // count excess room to pad
	for (int i = 0; i < padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str();    // format with padding
	if (padding > 0 && padding % 2 != 0)        // if odd #, add 1 space
		ss << " ";
	return ss.str();
}
// Function to make a user account.
void user::enterUserInfo(){
    system("CLS");
    cout << "Enter First Name : "; cin >> fname;
    cout << "Enter last Name : "; cin >> lname;
    cout << "Enter Passport No : "; cin >> passNo;
    cout << "Enter Phone No : "; cin >> phoneNo;
    cout << "Set Password : "; cin >> password;
}        
bool user::login(int passNo,string password){
    if(this -> passNo == passNo && this->password == password) return true;
            return false;
}
//Function To display Ticket Of Passenger
void user::displayUserInfo(flight &f){
    system("CLS");
	cout << "\t" << setw(60) << center("***Passenger's Ticket***", 60) << endl;
	cout << "\t"; for (int i = 0; i < 60; i++) cout << "-"; cout << endl;
	cout << "\t"; cout << left  << "Passenger's Name : " << fname << " " << lname << endl;
	cout << "\t"; for (int i = 0; i < 60; i++) cout << "-"; cout << endl;
	cout << "\t"; cout << left << "Passport No : " << passNo << endl;
	cout << "\t"; cout << left << "From : " << setw(23) << f.from << right << setw(30) << "TO : " << left << f.to << endl;
	cout << "\t"; for (int i = 0; i < 60; i++) cout << "*"; cout << endl;
	cout << "\t" << setw(60) << center("Thank You For Using Our Service.", 60) << endl;
	cout << "\t"; for (int i = 0; i < 60; i++) cout << "*"; cout << endl;
}
#endif
