#include<iostream>
#include<fstream>
using namespace std;
struct student{
    char name[50];
    int age;
    int salary;
};
int main(){
    student students[4];
    int pos = 0;
    ifstream file("./ex.bin", ios::binary);
    while(file.peek() !=EOF){
        file.read((char*)&students[pos++], sizeof(student));
    }

    file.close();
    // print all:
    for(int i=0; i<pos; i++){
        student temp = students[i];
        cout<<"Name: "<<temp.name<<endl;
        cout<<"Age: "<<temp.age<<endl;
        cout<<"Salary: "<<temp.salary<<endl;
        cout<<"-----------------"<<endl;
    }
 
    return 0;
}