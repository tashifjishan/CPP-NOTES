#include<iostream>
using namespace std;
class Animal{
    private:
        string name;
    public:
        Animal(string name){
            this->name = name;
        }

        void getName(){
            cout<<this->name<<endl;
        }
};
class Pet{
    private:
        bool isFriendly;
    public:
        Pet(bool friendly){
            isFriendly = friendly;
        }

        void getFriendlyStatus(){
            cout<<"Friendly: "<<isFriendly<<endl;
        }
};
class Dog: public Animal, public Pet{
    private:
        string owner;
    public:
        Dog(string name, string owner, bool friendly): Animal(name), Pet(friendly){
            this->owner = owner;

        };
        
        void getOwner(){
            cout<<this->owner<<endl;
        }
};
int main(){
    Dog rocky("Rocky The Great", "Jimmy", true);
    rocky.getOwner();
    rocky.getName();
    rocky.getFriendlyStatus();
    return 0;
}