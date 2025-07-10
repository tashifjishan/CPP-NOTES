# 🔷 1. What is Polymorphism?

Definition:
Polymorphism in C++ refers to the ability of a function, operator, or object to behave in different ways depending on the context. It enables code reuse, flexibility, and extensibility in OOP.

"One interface, many implementations."

# 🔷 2. Types of Polymorphism in C++
Type	Other Name(s)	Binding Time	Achieved Through

- Compile-time(Static Polymorphism):
    -- Achieved at compile time by function and operator overloading
- Run-time (Dynamic Polymorphism):	
    -- Achieved At Runtime	
    -- Function Overriding via Virtual Functions

## ✅ Compile-Time Polymorphism
### 🔹 A. Function Overloading

Definition:
Same function name with different parameter lists (number/type/order of arguments).

Example:
```cpp
#include <iostream>
using namespace std;

class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }

    void show(double d) {
        cout << "Double: " << d << endl;
    }

    void show(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print obj;
    obj.show(5);         // Integer version
    obj.show(3.14);      // Double version
    obj.show("Hello");   // String version
    return 0;
}
```

### 🔹 B. Operator Overloading

Definition:
Redefining how an operator works for user-defined types.

Example: Overloading + operator
```cpp
#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 2), c2(1, 7);
    Complex c3 = c1 + c2;  // Calls overloaded +
    c3.display();          // Output: 4 + 9i
    return 0;
}
```

## ✅ Run-Time Polymorphism

### 🔹 Function Overriding with Virtual Functions
Definition:
When a base class function is redefined in a derived class using the same signature. It allows dynamic dispatch.

- **Key Concept:** Use virtual keyword in base class.

Example:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->sound();  // Output: Dog barks
    a2->sound();  // Output: Cat meows

    delete a1;
    delete a2;

    return 0;
}
```
#### 🔹 Notes on Virtual Functions
- Use virtual keyword in base class to enable dynamic binding.
- If not marked virtual, the base class version is called even when pointing to a derived object.
- If a class has a pure virtual function, it becomes an abstract class.

- 🔹 Pure Virtual Function and Abstract Class Example
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Shape* s = new Circle();
    s->draw();  // Output: Drawing Circle
    delete s;
    return 0;
}
```


#  Practice Questions
- Write a program that overloads a function to calculate area of a circle, square, and rectangle.

- Create a base class Vehicle with a virtual function run(), and override it in derived classes Car and Bike.

