#include<iostream>
using namespace std;

class intlist {
private:
    int* data = new int[10];
    int size = 10;
    int pos = 0;

public:
    // Destructor to prevent memory leak
    ~intlist() {
        delete[] data;
    }

    intlist(const intlist& other){
        this->data = other.data;
    }

    void push(int value) {
        if (pos == size) {
            size += 10;
            int* temp = data;
            data = new int[size];
            for (int i = 0; i < pos; i++) {
                data[i] = temp[i];
            }
            delete[] temp;
        }
        data[pos++] = value;
    }

    void print() {
        cout << "[";
        for (int i = 0; i < pos; i++) {
            cout << data[i];
            if (i != pos - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    intlist marks;
    marks.push(4);
    marks.push(5);
    marks.push(90);
    marks.push(120);
    marks.push(50);
    marks.push(550);
    marks.push(120);
    marks.push(98);
    marks.push(45);
    marks.push(90);
    marks.push(120);
    marks.push(980);
    marks.push(980);
    marks.push(980);
    marks.push(980);
    marks.push(980);

    marks.print();

    intlist ids;
    ids.print();
    return 0;
}



// # Rule of three and rule of 5