#include<iostream>
#include<fstream>
using namespace std;
main()
{
    char ch=a;
    string name= abuzar;
    float num= 0.8976;
    fstream file;
    file.open("example.txt",ios::out);
    file << ch << endl << name << endl << num;
    file.close();

}