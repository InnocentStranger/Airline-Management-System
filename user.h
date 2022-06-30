#ifndef USER_H_
#define USER_H_

#include <string>
using  namespace std;

class user{
    //Properties
    char fname[20],lname[20],password[20];
    int phoneNo,passNo,fNo;
    public:
        user(){phoneNo = 0,passNo = 0;fNo=0;fname[0]='\0';lname[0]='\0';password[0]='\0';}
        //Methods
        void enterUserInfo();
        void displayUserInfo(flight&);
        bool login(int,char[]);
        // Operaotr overloading
        bool operator == (user const &obj);
        void updatefNo(flight&);
        void updatefNo(int);
        int retrieve();
}users;

#endif