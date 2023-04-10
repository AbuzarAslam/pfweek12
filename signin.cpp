#include<iostream>
#include<fstream>
using namespace std;
bool signIn(string username,string password);
bool isValidUsername(string username);
void signUp(string username,string password);
void storeInfile(string username,string password);
int takeChoice();
void viewUser();
void readDataFromFile();
int usercount=0;
string Username[10];
string Password[10];
string Role[10];
main()
{
    int choice;
    system("cls");
    while(choice!=0)
    {
        bool decision;
        string username;
        string password;
        string role;
        choice=takeChoice();
        if(choice==1)
        {
            system("cls");
            cout << "Enter username....";
            cin >> username;
            cout << "Enter password....";
            cin >> password;
            cout << "Enter your role(Manager/Customer)....";
            cin >> role;
            decision=isValidUsername(username);
            if(decision==true)
            {
                signUp(username,password);
                storeInfile(username,password);
                cout << "Signed up successfully"<<endl;
            }
            else
            {
                cout << "Same user exist"<<endl;
            }
        }
        else if(choice==2)
        {
            system("cls");
            cout << "Enter username....";
            cin >> username;
            cout << "Enter password....";
            cin >> password;
            signIn(username,password);
            decision=signIn(username,password);
            if(decision==true)
            {
                cout << "Login Successfully"<< endl;
            }
            else
            {
                cout << "Invalid Credentials"<< endl;
            }
        }
        else if(choice==3)
        {
            system("cls");
            readDataFromFile();
            viewUser();
        }
    }

}
int takeChoice()
{
    int choice;
    cout << "1.Sign up "<< endl;
    cout << "2.Sign In "<< endl;
    cout << "3.View Users "<< endl;
    cout << "0.Exit "<< endl;
    cout << "Enter choice...";
    cin >> choice;
    return choice;
}
void signUp(string username,string password)
{
    Username[usercount] = username;
    Password[usercount] = password;
    usercount++;
}
void storeInfile(string username,string password)
{
    fstream file;
    file.open("myFile.txt",ios::app);
    file << username << endl;
    file << password << endl;
    file.close();
}
void viewUser()
{
    system("cls");
    for(int n=0;n<usercount;n++)
    {
        cout << n+1<<"."<<Username[n] << "\t" << Password[n]<<endl;
    }
}
bool signIn(string username,string password)
{
    bool flag=false;
    for(int n=0;n<usercount;n++)
    {
        if(username==Username[n] && password==Password[n])
        {
            flag= true;
            break;
        }
    }
    return flag;
}
bool isValidUsername(string username)
{
    bool flag = true;
    for(int n=0;n<usercount;n++)
    {
        if(username==Username[n])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void readDataFromFile()
{
    string username;
    string password;
    fstream file;
    file.open("myFile.txt",ios::in);
    while(!file.eof())
    {
        getline(file,username);
        getline(file,password);
    }
    file.close();
}