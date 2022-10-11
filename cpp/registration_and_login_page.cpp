#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

void login();
void Register();
void forgot();
int main()
{
    int c; // choice
    cout << "\t\t\t_______________Login Page_______________\n\n"
         << endl;
    cout << "\t\t\t_______________Main Menu_______________\n"
         << endl;

    cout << "Press 1 to login" << endl;
    cout << "Press 2 to register" << endl;
    cout << "Press 3 if you forgot Your password" << endl;
    cout << "Press 4 to exit" << endl;
    cout << "Please enter your choice" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        Register();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"Thanks you for your time!!!"<<endl;
        break;

    default:
        // system("cls");
        cout << "\tplease select from the options given\n";
        main();
    }
    return 0;
}
void login()
{
    int count;
    string username, password, ID, pass;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> ID >> pass)
    {
        if (ID == username && pass == password)
        {
            count = 1;
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "Your login is successfull" << endl;
        main();
    }
    else
    {
        cout << "Login error: Please check your username and password" << endl;
        main();
    }
}
void Register()
{
    string ruserID, rPassword, rID, rPass;
    cout << "Please enter your Username: ";
    cin >> ruserID;
    cout << "Please enter a password: ";
    cin >> rPassword;
    ofstream f1("records.txt", ios::app);
    f1 << ruserID << ' ' << rPassword << endl;
    cout << "Your registration is successfull" << endl;
    main();
}
void forgot()
{
    int option;
    cout<<"\t\t\t You forgot your password!!!"<<endl;
    cout<<"press 1 to search your password by userId"<<endl;
    cout<<"press 2 to go back to main menu"<<endl;
    cin>>option;
    
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserID, sID, spass;
        cout<<"Please enter your userID: ";
        cin>>suserID;
        fstream f2("records.txt");
        while(f2>>sID>>spass){
            if(sID == suserID){
                count = 1;
            }
        }
        f2.close();
        if(count == 1){
            cout<<"Your password is: "<<spass<<endl;
            main();
        }
        else{
            cout<<"Sorry your account is not found"<<endl;
        }
        break;
    }
    case 2:
        main();
    default:
        cout<<"Wrong choice! Please try again"<<endl;
        main();
        break;
    }
}