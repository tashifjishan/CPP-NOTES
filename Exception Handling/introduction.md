# 🔹 Basics of Exception Handling

- Exception: Runtime error or abnormal condition.

Handling Exception: Using try, throw, and catch to detect and handle errors gracefully without crashing the program.

Syntax:
```cpp
try {
    // Code that may throw exception
    throw exception_type;
}
catch(exception_type var) {
    // Code to handle exception
}
```
## 🔹Exception Handling Mechanism

- try block – Wraps code that might throw an exception.
- throw statement – Used to throw an exception when a problem occurs.
- catch block – Catches and handles the exception thrown.
- 💡 One try block can have multiple catch blocks.

## 🔹 Throwing Mechanism

- Used to signal an error or exceptional condition.
Syntax: throw value;

- Example:

```cpp 
throw "Division by zero error";
```
## 🔹 Catching Mechanism

- Syntax: catch(data_type var) { /* handle */ }

- Multiple catch blocks for different exception types.
- Catch-all handler: catch(...) { }
```cpp
try {
    int a = 10, b = 0;
    if(b == 0) throw "Cannot divide by zero";
    cout << a / b;
}
catch(const char* msg) {
    cout << "Error: " << msg << endl;
}
```
## 🔹 Rethrowing an Exception
- Use throw; inside catch block to rethrow.
- Useful when one part handles logging and another handles termination.
```cpp
try {
    try {
        throw 100;
    }
    catch(int e) {
        cout << "Handling inside inner catch, rethrowing...\n";
        throw; // rethrow
    }
}
catch(int e) {
    cout << "Caught in outer catch: " << e << endl;
}
```

# 📦 Function Template and Class Template
### 🔹 Function Template
Allows writing generic functions for different data types.
```cpp
template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add<int>(2, 3) << endl;
    cout << add<float>(2.5, 3.5) << endl;
}
```
### 🔹 Class Template

Generic class definition, instantiated with different types.
```cpp
template<class T>
class Box {
    T data;
public:
    Box(T val) : data(val) {}
    void display() { cout << data << endl; }
};

int main() {
    Box<int> intBox(10);
    Box<string> strBox("Hello");
    intBox.display();
    strBox.display();
}
```
### 🧬 Class Template with Inheritance
🔹 Derived Class from a Template Class
```cpp
template <class T>
class Base {
public:
    T val;
    Base(T v) : val(v) {}
    void show() { cout << "Base: " << val << endl; }
};

template <class T>
class Derived : public Base<T> {
public:
    Derived(T v) : Base<T>(v) {}
    void display() { cout << "Derived: " << this->val << endl; }
};
```
### 🔹 Derived Class as a Template from a Non-template Base
```cpp
class Base {
public:
    void baseMethod() { cout << "Base class method" << endl; }
};

template <class T>
class Derived : public Base {
    T data;
public:
    Derived(T d) : data(d) {}
    void show() { cout << "Data: " << data << endl; }
};
```
