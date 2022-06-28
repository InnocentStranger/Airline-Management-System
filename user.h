#ifndef USER_H_
#define USER_H_

#include <string>
using  namespace std;

class user{
    //Properties
    string fname,lname,to,from;
    int phoneNo,passNo;
    public:
        user(){phoneNo = 0,passNo = 0;}
        //Methods
        void enterUserInfo();
        void displayUserInfo();
};

#endif