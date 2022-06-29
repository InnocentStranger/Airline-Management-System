#ifndef USER_H_
#define USER_H_

#include <string>
using  namespace std;

class user{
    //Properties
    string fname,lname,password;
    int phoneNo,passNo,fNo;
    public:
        user(){phoneNo = 0,passNo = 0;fNo=0;}
        //Methods
        void enterUserInfo();
        void displayUserInfo(flight&);
        bool login(int,string);

};

#endif