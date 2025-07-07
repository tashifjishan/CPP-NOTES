#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student{
    char name[50];
    int age;
    int salary;
};
int main(){
    fstream file("./ex.bin", ios::binary | ios::in | ios::out);
    file.seekg(3*sizeof(student));
    student s;
    file.read((char*)&s, sizeof(s));
    cout<<"Name: "<<s.name<<endl;
    cout<<"Age: "<<s.age<<endl;
    cout<<"Salary: "<<s.salary<<endl;
    file.seekp(3*sizeof(student));
    strcpy(s.name, "Mohan Kumar Chaurasia Bagaha");
    s.age = 118;
    file.write((char*)&s, sizeof(s));
    file.close();
    
    return 0;
}