#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // char name[10][50]={
    //     "Tashif Iqbal",
    //     "Rajendra Prasad"
    // };

    // char tasks[10][100] = {
    //     "I have to do something",
    //     "I have to eat food!"
    // };

    // char name[10][50] = {"Tashif Iqbal", "Lipika Shukla"};
    // char tasks[10][100] = {"Have to do something", "have to eat food!"};
    fstream file("./index.bin", ios::binary | ios::in | ios::out);

    if(!file) cout<<"Could not open file!"<<endl;

    // for(int i=0; i<10; i++){
    //     file.write(name[i], sizeof(name[i]));
    // }
    // for(int i=0; i<10; i++){
    //     file.write(tasks[i], sizeof(tasks[i]));
    // }

    file.close();
    cout<<"Done!"<<endl;
    return 0;
}



