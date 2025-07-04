// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class money{
    private:
        int crores, lakhs, thousands, hundreds, tens, ones;
    public:
        money& setCrores(int value){
            this->crores = value;
            return *this;
        }
        
        money& setLakhs(int value){
            this->lakhs = value;
            return *this;
        }
        
        void print(){
            cout<<crores<<" crores, "<<lakhs<<" lakhs"<<endl;
        }
};
int main() {
    money cash;
    // money something = cash.setCrores(9);
    // cash.setLakhs(20);
    // cash.print();
    // something.print();

    cash.setCrores(9).setLakhs(90).print();
    //output: 9 crores, 90 lakhs
    cash.print();
    //output: 9 crores, 1976397347 lakhs

    //after returning reference to the same object both give the same output

    return 0;
}



 
 Manipulator Functions

 this pointer
 pointers and multidimensional arrays
 
 File stream functions, 
 Sequential access and random access file processing, Binary file operations, 



: Operator Overloading (unary operator, binary 
operator overloading), 

Type conversions - basic type to class type, class type to basic type
