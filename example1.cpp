#include<iostream>
#include<fstream>
using namespace std;
main()
{

    fstream file;
    file.open("myFile.txt",ios::out);
    file << "this is sampel text";
    file.close();

}