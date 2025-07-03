// #include<iostream>
// #include<fstream>
// using namespace std;

// int main(){
//     int a[] = {1, 2, 3, 4, 5, 980, 9876};
    
//     ofstream file("arr.dat", ios::binary);
//     file.write((char*)&a, sizeof(a));
//     file.close();


//     return 0;

// }


#include <iostream>
#include <fstream>

using namespace std;
int main(){
    int arr[50];
    ifstream file("arr.dat", ios::binary);
    file.read((char*)arr, sizeof(arr));
    file.close();

    cout<<arr[6]<<endl;
    arr[7] = 90;
    cout<<arr[7];
    return 0;
}