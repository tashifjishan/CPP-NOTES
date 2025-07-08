#include<iostream>
using namespace std;

void divide(int a, int b){
    try{
        if(b==0) throw "Cannot divide by zero!";
        int result = a/b;
        cout<<"Result: "<<result<<endl;
    }catch(const char* msg){
        cerr<<msg<<endl;
    }
}
int main(){
    divide(4,5);
    divide(40, 8);
    divide(8, 0);
}