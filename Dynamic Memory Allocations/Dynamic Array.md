```cpp

#include <iostream>
using namespace std;

void push(int*& arr, int& capacity, int& pos, int newValue){
    if(pos==capacity){
        capacity=capacity+5;
        int* temp = new int[capacity];
        for(int i=0; i<pos; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        
    }
    
    arr[pos++] = newValue;
}

void print(const int* arr, const int pos){
    cout<<"[";
    for(int i=0; i<pos; i++){
        cout<<arr[i]<<(i==pos-1 ?"":", ");
    }
    cout<<"]"<<endl;
}


int main() {
    int* marks = new int[5];
    int capacity = 5;
    int pos = 0;
    push(marks, capacity, pos, 90);
    push(marks, capacity, pos, 95);
    push(marks, capacity, pos, 95);
    push(marks, capacity, pos, 95);
    push(marks, capacity, pos, 95);
    push(marks, capacity, pos, 95);
    push(marks, capacity, pos, 95);
    push(marks, capacity, pos, 190);
    push(marks, capacity, pos, 247930);
    print(marks, pos);
    
    delete[] marks;
    marks = nullptr;
    return 0;
}
```