
✅ Definition:

Function overloading allows multiple functions in the same scope to have the same name but different parameter lists (i.e., different type or number of parameters).

```cpp

    #include <iostream>
    using namespace std;

    void display(int i) {
        cout << "Integer: " << i << endl;
    }

    void display(double d) {
        cout << "Double: " << d << endl;
    }

    void display(string s) {
        cout << "String: " << s << endl;
    }

    int main() {
        display(10);         // Calls display(int)
        display(5.5);        // Calls display(double)
        display("Hello");    // Calls display(string)
        return 0;
    }

```