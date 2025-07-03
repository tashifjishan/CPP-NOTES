#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string name = "Tashif Iqbal";
    string email = "tashif@gmail.com";
    string phone = "+918210853664";
    string password = "1234567890";

    ofstream file ("string.dat", ios::binary);
    size_t len = name.size();
    file.write((char*)&len, sizeof(len));
    file.write(name.c_str(), len);

    len = email.size();
    file.write((char*)&len, sizeof(len));
    file.write(email.c_str(), len);


    len = phone.size();
    file.write((char*)&len, sizeof(len));
    file.write(phone.c_str(), len);

    len = password.size();
    file.write((char*)&len, sizeof(len));
    file.write(password.c_str(), len);

    file.close();
    return 0;
}