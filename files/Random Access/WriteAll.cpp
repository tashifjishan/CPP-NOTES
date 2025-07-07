#include<iostream>
#include<fstream>

using namespace std;
struct student{
    char name[50];
    int age;
    int salary;
};
int main(){
    student students[] = {
        {"Mohan Kumar Chaurasia", 98, 98000},
        {"Manohar Lal Khitpitiya", 78, 78000},
        {"Sanjana Dagar", 19, 19000 },
        {"Mohan Kanaujiya", 23, 23000}
    };

    ofstream file("ex.bin", ios::binary);
    for(int i=0; i<4; i++){
        student temp = students[i];
        file.write((char*)&temp, sizeof(temp));
    }
    file.close();

    return 0;
   
}