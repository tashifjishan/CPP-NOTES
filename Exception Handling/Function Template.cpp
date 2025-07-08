#include<iostream>
template<typename t>
t add(t a, t b){
    return a+b;
}

using namespace std;

int main(){
    cout<<add<int>(4, 5)<<endl;
    cout<<add<float>(5.5, 9.5)<<endl;
}