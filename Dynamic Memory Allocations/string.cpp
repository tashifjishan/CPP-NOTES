// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class dstring{
    private:
        char*str;
        int capacity, pos;
    public:
        dstring(){
            str = new char[10];
            capacity = 10;
            pos = 0;
        }
        
        void append(char ch){
            if(pos==capacity){
                capacity = capacity*2;
                char* tempS = new char[capacity];
                for(int i=0; i<pos; i++){
                    tempS[i] = str[i];
                }
                delete[] str;
                str = tempS;
            }
            str[pos++] = ch;
            str[pos] = '\0';
        }
        void print(){
            cout<<str<<endl;
        }
        
        ~dstring(){
            delete[] str;
            str=nullptr;
        }
};
int main() {
    dstring name;
    char ch;
    while(ch!='\n'){
        ch = getchar();
        name.append(ch);
    }

    name.print();

    return 0;
}