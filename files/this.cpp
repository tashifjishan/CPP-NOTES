#include <iostream>
#include <fstream>
using namespace std;

class User {
public:
    string fullName;
    string email;
    string password;
    string address;
    string phone;

    // Serialize object
    void writeToFile(ofstream &out) {
        writeString(out, fullName);
        writeString(out, email);
        writeString(out, password);
        writeString(out, address);
        writeString(out, phone);
    }

    // Deserialize object
    void readFromFile(ifstream &in) {
        fullName = readString(in);
        email = readString(in);
        password = readString(in);
        address = readString(in);
        phone = readString(in);
    }

    void display() {
        cout << "\n===== User Details =====\n";
        cout << "Name    : " << fullName << endl;
        cout << "Email   : " << email << endl;
        cout << "Address : " << address << endl;
        cout << "Phone   : " << phone << endl;
    }

private:
    void writeString(ofstream &out, const string& str) {
        size_t len = str.size();
        out.write((char*)&len, sizeof(len));
        out.write(str.c_str(), len);
    }

    string readString(ifstream &in) {
        size_t len;
        in.read((char*)&len, sizeof(len));
        char* buffer = new char[len + 1];
        in.read(buffer, len);
        buffer[len] = '\0';
        string result(buffer);
        delete[] buffer;
        return result;
    }
};

// Check if user already exists
bool userExists(const string& email, const string& fileName) {
    ifstream fin(fileName, ios::binary);
    if (!fin) return false;

    while (fin.peek() != EOF) {
        User u;
        u.readFromFile(fin);
        if (u.email == email) {
            fin.close();
            return true;
        }
    }

    fin.close();
    return false;
}

// Authenticate login
bool login(const string& email, const string& password, const string& fileName, User &foundUser) {
    ifstream fin(fileName, ios::binary);
    if (!fin) return false;

    while (fin.peek() != EOF) {
        User u;
        u.readFromFile(fin);
        if (u.email == email && u.password == password) {
            foundUser = u;
            fin.close();
            return true;
        }
    }

    fin.close();
    return false;
}

// Sign up new user
void signup(const string& fileName) {
    User u;
    cout << "\n--- Sign Up ---\n";
    cout << "Enter full name: ";
    getline(cin, u.fullName);

    cout << "Enter email: ";
    getline(cin, u.email);

    if (userExists(u.email, fileName)) {
        cout << "⚠️ Email already registered. Try logging in.\n";
        return;
    }

    cout << "Enter password: ";
    getline(cin, u.password);

    cout << "Enter address: ";
    getline(cin, u.address);

    cout << "Enter phone number: ";
    getline(cin, u.phone);

    ofstream fout(fileName, ios::binary | ios::app);
    if (!fout) {
        cout << "❌ Error writing to file.\n";
        return;
    }

    u.writeToFile(fout);
    fout.close();

    cout << "✅ Sign-up successful!\n";
}

// Login user
void loginUser(const string& fileName) {
    string email, password;
    cout << "\n--- Login ---\n";
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter password: ";
    getline(cin, password);

    User found;
    if (login(email, password, fileName, found)) {
        cout << "✅ Login successful!\n";
        found.display();
    } else {
        cout << "❌ Sorry! You must sign up first.\n";
    }
}

int main() {
    const string fileName = "users.dat";
    int choice;

    ofstream temp(fileName, ios::app | ios::binary);
    temp.close();  // Ensure file exists

    while (true) {
        cout << "\n====== User Auth System (Binary Storage) ======\n";
        cout << "1. Sign Up\n2. Login\n0. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();  // Clear input buffer

        if (choice == 1)
            signup(fileName);
        else if (choice == 2)
            loginUser(fileName);
        else if (choice == 0)
            break;
        else
            cout << "⚠️ Invalid choice. Try again.\n";
    }

    return 0;
}
