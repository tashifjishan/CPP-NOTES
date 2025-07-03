#include<iostream>
#include<fstream>
using namespace std;


int main(){
    // int x = 987;
    // ofstream file("data.dat", ios::binary);
    // file.write((char*)&x, sizeof(x));
    // file.close();

    int y;
    ifstream file("data.dat", ios::binary);
    file.read((char*)&y, sizeof(y));
    file.close();

    cout<<"The value of y: "<<y;

    return 0;
}