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
bool user::login(int passNo,char password[]){
    if(this -> passNo == passNo && strcmp(this->password,password)==0) return true;
            return false;
}
//Function To display Ticket Of Passenger
void user::displayUserInfo(flight &f){
    system("CLS");
	string s; s+="TO : "; s+=f.to;
	string str; str+= "Passenger's Name : "; str+= fname; str += " "; str += lname;
	string fstr; fstr += "Flight No : "; fstr += to_string(f.fNo);
	cout << "\t" << setw(60) << center("***Passenger's Ticket***", 60) << endl;
	cout << "\t"; for (int i = 0; i < 60; i++) cout << "-"; cout << endl;
	cout << "\t"; cout << left  << setw(40) << str << right << setw(20) << fstr << endl;
	cout << "\t"; for (int i = 0; i < 60; i++) cout << "-"; cout << endl;
	cout << "\t"; cout << left << "Passport No : " << passNo << endl;
	cout << "\t"; cout << left << "From : " << setw(23) << f.from << right << setw(30) << s << endl;
	cout << "\t"; for (int i = 0; i < 60; i++) cout << "*"; cout << endl;
	cout << "\t" << setw(60) << center("Thank You For Using Our Service.", 60) << endl;
	cout << "\t"; for (int i = 0; i < 60; i++) cout << "*"; cout << endl;
	fflush(stdin);char e=getchar();
}
bool user::operator == (user const &obj){
	if(obj.passNo == this->passNo) return true;
    return false;
}
void user::updatefNo(flight& f){
	this->fNo = f.fNo;
}
void user::updatefNo(int fNo){
	this->fNo = fNo;
}
int user::retrieve(){
	return this->fNo;
}
#endif
