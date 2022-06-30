#ifndef HELP_CPP_
#define HELP_CPP_

void insertFlight(){
    flight temp,f;f.inputFlightDetails();
    ofstream fout;
    ifstream fin;
    fout.open("Flights.dat",ios::app|ios::binary);
    fin.open("Flights.dat",ios::binary|ios::in);

    if(fin){
        fin.read((char*)&temp,sizeof(temp));
        while(fin){
            if(temp == f) {cout << "Flight Already Exists." << endl; fflush(stdin); char e = getchar();fin.close();fout.close();return;}
            fin.read((char*)&temp,sizeof(temp));
        }
    }
    fout.write((char*)&f,sizeof(f));
    cout << "Flight Schedule Added. " << endl; fflush(stdin);
    char e = getchar();
    fout.close();
    fin.close();
}
bool findfNo(int fNo){
    ifstream fin;
    fin.open("Flights.dat",ios::binary);
    flight f;
    fin.read((char*)&f,sizeof(f));
    while(fin){
        if(f.cmpFno(fNo)) return true;
        fin.read((char*)&f,sizeof(f));
    }
    return  false;
}
void displaySpecificFlight(){
    char to[20],from[20];
    cout << "Enter Starting Point : "; cin >> from;
    cout << "Enter Destination : "; cin >> to;
    system("CLS");
    cout << "\t  " << left << setw(15) << "Flight No" << "| " << setw(15) << "From" << "| " << setw(15) <<
    "Destination" << "| " << setw(15) << "Depart. Time" << "| " << setw(15) << "Arrival Time" << "| " << 
    setw(15) << "Date" << "| " << setw(15) << "Cost" << endl;
    cout << "\t"; for(int i=0;i<120;i++) cout << "-"; cout << endl;

    ifstream fin; flight f;
    fin.open("Flights.dat",ios::binary);
    fin.read((char*)&f,sizeof(f));
    if(fin){
        if(f.searchFlight(to,from)) {f.displayFlightDetails();return;}
    }
    cout << "\tFlight Not Found. " << endl;
}
void displayAllFlight(){
    system("CLS");
    cout << "\t  " << left << setw(15) << "Flight No" << "| " << setw(15) << "From" << "| " << setw(15) <<
    "Destination" << "| " << setw(15) << "Depart. Time" << "| " << setw(15) << "Arrival Time" << "| " << 
    setw(15) << "Date" << "| " << setw(15) << "Cost" << endl;
    cout << "\t"; for(int i=0;i<120;i++) cout << "-"; cout << endl;
    flight f;
    ifstream fin;
    fin.open("Flights.dat",ios::binary);
    if(!fin){cout << "\t  No Flight Schedule Found." << endl; return;}
    while(fin.read((char*)&f,sizeof(f))){
        f.displayFlightDetails();
    }
}
void deleteAllFlight(){
    ofstream fout;
    fout.open("Flights.dat",ios::binary);
    fout.close();
    cout << "All Flight Schedule Deleted." << endl;
    fflush(stdin);char e = getchar();
}
void deleteSpecificFlight(){
    int fNo; 
    cout << "Enter Flight Numeber to Be deleted : "; cin >> fNo;
    if(!findfNo(fNo)){cout << "No Such Flight Exist." << endl;}
    flight f;
    ifstream fin;
    ofstream fout;
    fin.open("Flights.dat",ios::binary);
    fout.open("temp.dat",ios::binary);
    fin.read((char*)&f,sizeof(f));
    while(fin){
        if(!f.cmpFno(fNo))fout.write((char*)&f,sizeof(f));
        fin.read((char*)&f,sizeof(f));
    }
    fin.close();
    fout.close();
    remove("Flights.dat");
    rename("temp.dat","Flights.dat");
}
bool findfNo(user &u){
    ifstream fin;
    fin.open("Flights.dat",ios::binary);
    flight f;
    fin.read((char*)&f,sizeof(f));
    while(fin){
        if(f.cmpFno(u.retrieve())) return true;
        fin.read((char*)&f,sizeof(f));
    }
    return  false;
}
void bookTicket(user &u){
    if(findfNo(u)){cout << "Ticket Already Exist.";return;}
    char to[20],from[20];
    cout << "Enter Starting Point : "; cin >> from;
    cout << "Enter Destination : "; cin >> to;

    ifstream fin; flight f;
    fin.open("Flights.dat",ios::binary);
    fin.read((char*)&f,sizeof(f));
    if(fin){
        if(f.searchFlight(to,from)) {cout << "Ticket Successfully Booked." << endl;u.updatefNo(f);return;}
    }
    cout << "\tFlight Not Found. Ticket Can't be obtained." << endl;

}
void cancelTicket(user& u){
    if(!findfNo(u)){cout << "No Ticket Exist." << endl;return;}
    string s;
    cout << "Are you sure you want to cancel ticket?(Enter: yes to delete) ";cin >> s;
    if(s=="yes"){cout << "Your Ticket is Cancelled Successfully." << endl;u.updatefNo(-1);}
    else {cout << "Your Ticket is Still Intact."<< endl;}
}
void displayTicket(user& u){

    ifstream fin;
    fin.open("Flights.dat",ios::binary);
    flight f;
    fin.read((char*)&f,sizeof(f));
    while(fin){
        if(f.cmpFno(u.retrieve())){u.displayUserInfo(f);return;}
        fin.read((char*)&f,sizeof(f));
    }
    cout << "You are not Registered.\n";fflush(stdin);char e=getchar();
}
pair<bool,user> userLogin(int passNo,char password[]){
    user u;
    ifstream fin;
    fin.open("Users.dat",ios::binary);
    if(!fin){cout << "User Not Found. " << endl; fin.close();return make_pair(false,u);}
    fin.read((char*)&u,sizeof(u));
    while(fin){
        if(u.login(passNo,password)) {fin.close();return make_pair(true,u);}
        fin.read((char*)&u,sizeof(u));
    }
    fin.close();
    return make_pair(false,u);
}
void addNewUser(){
    user temp,u;u.enterUserInfo();
    ofstream fout;
    ifstream fin;
    fout.open("Users.dat",ios::app|ios::binary);
    fin.open("Users.dat",ios::binary|ios::in);

    if(fin){
        fin.read((char*)&temp,sizeof(temp));
        while(fin){
            if(temp == u) {cout << "Passport Number Already Exists." << endl; fflush(stdin); char e = getchar();fin.close();fout.close();return;}
            fin.read((char*)&temp,sizeof(temp));
        }
    }
    fout.write((char*)&u,sizeof(u));
    cout << "User Added. " << endl; fflush(stdin);
    char e = getchar();
    fout.close();
    fin.close();
}
void updateUser(user &u){
    user w;
    ifstream f;
    f.open("Users.dat",ios::in|ios::binary);
    ofstream fout;
    fout.open("temp.dat",ios::binary);
        f.read((char*)&w,sizeof(w));
        while(f){
            if(!(w == u))fout.write((char*)&w,sizeof(w));
            f.read((char*)&w,sizeof(w));
        }
    fout.write((char*)&u,sizeof(u));
    fout.close();
    f.close();
    remove("Users.dat");
    rename("temp.dat","Users.dat");
}
#endif
// Operator Overloading To check if passport number exist or not.