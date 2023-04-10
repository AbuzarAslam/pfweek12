#include<iostream>
#include<fstream>
using namespace std;
void readDataFromFile();
main()
{
    readDataFromFile();
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
        cout << endl<<username<<endl<<password;
    }
    file.close();
}