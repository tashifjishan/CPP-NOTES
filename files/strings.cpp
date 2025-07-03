#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // string content = "The quick brown fox jumps over the lazy dog and does the impossible!";

    // ofstream file("string.dat", ios::binary);
    // size_t len = content.size();
    // file.write((char*)&len, sizeof(len));
    // file.write(content.c_str(), len);
    // file.close();
    
    string message;
    ifstream file("string.dat", ios::binary);
    int length;
    file.read((char*)&length, sizeof(length));
    char* data = new char[length+1];
    file.read(data, length);
    data[length] = '\0';
    message = data;
    delete[] data;
    file.close();


    cout<<"Read: "<<message<<endl;
}