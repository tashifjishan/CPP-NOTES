#include<iostream>
using namespace std;
int main(){
    try
    {
        try{
            throw 100;
        }catch(int e){
            cout<<"From the inner catch block!"<<endl;
            throw e;
        }
    }
    catch(const int e)
    {
        std::cerr << "From outside: "<<e << '\n';
    }
    
}