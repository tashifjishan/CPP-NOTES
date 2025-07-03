# Friend Function 

### ✅ Definition:
A friend function is a function that is not a member of a class but is granted access to its private and protected members.

### ✅ Syntax:
```cpp
class MyClass {
    private:
        int data;
    public:
        friend void showData(MyClass obj);  // Friend function declaration
};
```

### ✅ Key Points:
    - Defined outside the class.
    - Needs to be declared with friend keyword inside the class.
    - Can be a normal function or a member of another class.

### ✅ Example:
```cpp
class A {
    private:
        int x = 10;
    public:
        friend void display(A);  // Friend function
};

void display(A obj) {
    cout << obj.x << endl;  // Accesses private member
}
```
# 🔹 Friend Class 

### ✅ Definition:

A friend class is a class that is given access to the private and protected members of another class.

### ✅ Syntax:
```cpp

class B; // Forward declaration

class A {
    private:
        int data;
    public:
        friend class B;  // Friend class declaration
};
```

### ✅ Key Points:
All member functions of the friend class can access the private/protected data of the other class.

Use when tight coupling is required (e.g., data sharing between classes).

### ✅ Example:
```cpp
class A {
    private:
        int x = 42;
    public:
        friend class B;  // B is a friend of A
};

class B {
    public:
        void show(A obj) {
            cout << obj.x << endl;  // Accessing private member
        }
};
```


### BY ME


```cpp
// Friend function
    #include <iostream>
    using namespace std;
    class A{
        private: 
            int data;
        public:
            A(int data){
                this->data = data;
            }
            
            friend void printer(A obj);
            
    };

    void printer(A obj){
        cout<<obj.data<<endl;
    }

    int main() {
        A one(90);
        
        printer(one);

        return 0;
    }

```


```cpp
    // Friend Class

    #include <iostream>
    using namespace std;

    // Forward declaration of class B
    class B;

    class A {
    private:
        int data;

    public:
        // Constructor to initialize 'data'
        A(int value) {
            data = value;
        }

        // Print function to display the value of 'data'
        void print() {
            cout << "A's data: " << data << endl;
        }

        // Grant class B access to private members of A
        friend class B;
    };

    class B {
    private:
        int data;

    public:
        // Constructor to initialize B with its own value
        B(int value) {
            data = value;
        }

        // Constructor to initialize B using an object of class A
        B(A obj) {
            data = obj.data; // Access private data of A
        }

        // Print function to display the value of 'data'
        void print() {
            cout << "B's data: " << data << endl;
        }
    };

    int main() {
        A sourceA(45);          // Object of A with data 45
        B independentB(90);     // Object of B with its own value
        B copiedFromA(sourceA); // Object of B constructed from object A

        sourceA.print();        // Output: A's data: 45
        independentB.print();   // Output: B's data: 90
        copiedFromA.print();    // Output: B's data: 45

        return 0;
    }

```