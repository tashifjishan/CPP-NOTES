#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct student {
    char name[50];
    int age;
    int salary;
};

int main() {
    fstream file("./ex.bin", ios::binary | ios::in | ios::out);
    
    if (!file) {
        cerr << "❌ Error: Could not open file.\n";
        return 1;
    }

    const int index = 3; // 4th record (0-based)
    streampos readPos = index * sizeof(student);

    // Move to the 4th record to read
    file.seekg(readPos);
    if (!file) {
        cerr << "❌ Error: seekg failed.\n";
        return 1;
    }

    student s;
    file.read((char*)&s, sizeof(s));
    if (!file) {
        cerr << "❌ Error: Failed to read student record. File may not have enough records.\n";
        return 1;
    }

    cout << "✅ Original Record:\n";
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Salary: " << s.salary << endl;

    // Modify the record
    const char* newName = "Mohan Kumar Chaurasia Bagaha";
    if (strlen(newName) >= sizeof(s.name)) {
        cerr << "❌ Error: New name too long for buffer.\n";
        return 1;
    }

    strcpy(s.name, newName);
    s.age = 118;

    // Move to same record to overwrite
    file.seekp(readPos);
    if (!file) {
        cerr << "❌ Error: seekp failed.\n";
        return 1;
    }

    file.write((char*)&s, sizeof(s));
    if (!file) {
        cerr << "❌ Error: Failed to write updated student record.\n";
        return 1;
    }

    cout << "✅ Record updated successfully.\n";
    file.close();
    return 0;
}
