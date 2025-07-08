#include<iostream>
using namespace std;
template<class T>
class Number{
    private:
     T data;
    public:
        Number(T val){
            this->data = val;
        }

        void print(){
            cout<<data<<endl;
        }
};

using namespace std; 
int main(){
    Number<int> a(90);
    Number<string> b("Nine");
    a.print();
    b.print();

    return 0;
}