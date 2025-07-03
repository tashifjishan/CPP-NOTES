#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string name, email, phone, password;

    ifstream file("string.dat", ios::binary);
    int len;
    file.read((char*)&len, sizeof(len));
    char* buffer = new char[len+1];
    file.read(buffer, len);
    buffer[len] = '\0';
    name = buffer;
    delete[] buffer;
    
    file.read((char*)&len, sizeof(len));
    buffer = new char[len+1];
    file.read(buffer, len);
    buffer[len] = '\0';
    email = buffer;
    delete[] buffer;

    file.read((char*)&len, sizeof(len));
    buffer = new char[len+1];
    file.read(buffer, len);
    buffer[len] = '\0';
    phone = buffer;
    delete[] buffer;

    file.read((char*)&len, sizeof(len));
    buffer = new char[len+1];
    file.read(buffer, len);
    buffer[len] = '\0';
    password = buffer;
    delete[] buffer;

    
    file.close();


    cout<<"Name: "<<name<< endl;
    cout<<"Email: "<<email<< endl;
    cout<<"Phone: "<<phone<< endl;
    cout<<"Password: "<<password<< endl;
}