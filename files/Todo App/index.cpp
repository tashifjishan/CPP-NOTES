#include<iostream>
#include<fstream>

using namespace std;

class User{
    public:
        string name, email, phone, password;
        
        User(){}
        User(string name, string email, string phone, string password){
            this->name = name;
            this->email = email;
            this->password = password;
            this->phone = phone;

        }

        void profile(){
            cout<<"Name: "<<name<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"Phone: "<<phone<<endl;
        }

        void saveToFile(ofstream &file){
            writeString(file, name);
            writeString(file, email);
            writeString(file, phone);
            writeString(file, password);
        }

        void readFromFile(ifstream& file){
            name = readString(file);
            email = readString(file);
            phone = readString(file);
            password = readString(file);
        }

        bool addTask(string task){
            if(this->taskPos==100){
                return false;
            }else{
                tasks[this->taskPos] = task; 
                this->taskPos+=1;
            }
        }

        void listTasks(){
            for(int i=0; i<this->taskPos; i++){
                cout<<i+1<<". "<<this->tasks[i]<<endl;
            }
        }

    private:
        string tasks[100];
        int taskPos = 0;

        void writeString(ofstream& file, const string content){
            size_t len = content.size();
            file.write((char*)&len, sizeof(len));
            file.write(content.c_str(), len);
        }

        string readString(ifstream& file){
            size_t len;
            file.read((char*)&len, sizeof(len));
            char* buffer = new char[len+1];
            file.read(buffer, len);
            buffer[len] = '\0';
            string result = buffer;
            delete[] buffer;
            return result;
        }
    
};

void login(){
    string givenEmail, givenPassword;
    cout<<"Email Address: ";
    getline(cin, givenEmail);
    cout<<"Enter Password: ";
    getline(cin, givenPassword);

    ifstream file("users.bin", ios::binary);
    User foundUser;
    int match = 0;
    while(file.peek()!=EOF){
        User u;
        u.readFromFile(file);
        if(u.email ==givenEmail && u.password == givenPassword){
            foundUser = u;
            match = 1;
            cout<<"Logged in!"<<endl;
            break;
        }
    }

    if(match){
        cout<<"Welcome "<<foundUser.name<<endl;
    }else{
        cout<<"Could not login!"<<endl;
    }
}

void addTask(){
    string newTask;
    cout<<"Enter new task: ";
    getline(cin, newTask);
    // there might be more than a 100 users at one time. so consider using dynamic arrays
    User users[100];
    int currentPos=0;
    


}

void listTasks(){

}
void signup(){
    ofstream file("users.bin", ios::app | ios::binary);
    if(!file){
        cout<<"Could not open data file!"<<endl;
        return;
    }
    string name, email, phone, password;
    cout<<"Enter Full Name: ";
    getline(cin, name);
    cout<<"Enter Email Address: ";
    getline(cin, email);
    cout<<"Enter Phone Number: ";
    getline(cin, phone);
    cout<<"Enter Password: ";
    getline(cin, password);

    // first check if any user with the same credential exists already

    // proceed to signup

    User u(name, email, phone, password);
    u.saveToFile(file);
    cout<<"Registration Successful!"<<endl;
    file.close();
}

int main(){
    // just to make sure if the file exists!
    ofstream temp("users.bin", ios::binary | ios::app);
    temp.close();


    string command;
    while(true){
        cout<<">> ";
        getline(cin, command);
        if(command=="exit") break;
        else if(command=="login"){
            login();
        }else if(command =="signup"){
            signup();
        }

    }

    return 0;
}