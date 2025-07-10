
# 🔷 1. What is a Pure Virtual Function?

Definition:
A pure virtual function is a virtual function that has no implementation in the base class. It is declared by assigning = 0 in the class declaration.

It forces derived classes to provide their own implementation of the function.

- ✅ Syntax:
```cpp
class Base {
public:
    virtual void display() = 0;  // Pure virtual function
};
```
# 🔷 2. Abstract Class

Definition:
A class is called abstract if it contains at least one pure virtual function.
You cannot instantiate (create objects of) an abstract class.

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};
```
# 🔷 3. Concrete Class

Definition:
A concrete class is a class that implements all pure virtual functions inherited from abstract classes. You can create objects of a concrete class.

✅ Example:
```cpp
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    // Shape s;          // ❌ Error: Cannot instantiate abstract class
    Circle c;            // ✅ OK
    Shape* s = &c;
    s->draw();           // Output: Drawing Circle
    return 0;
}
```
# 🔷 4. Real Example: Abstract Base Class and Concrete Derived Classes
```cpp
#include <iostream>
using namespace std;

// Abstract class
class Animal {
public:
    virtual void sound() = 0;  // Pure virtual function
    virtual ~Animal() {}       // Virtual destructor
};

// Concrete class
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

// Another concrete class
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
# 🔶 Key Rules and Notes

- Pure virtual function	virtual void func() = 0;
- Abstract class	Contains at least one pure virtual function
- Cannot instantiate	Objects of abstract classes are not allowed
- Concrete class	Implements all inherited pure virtual functions
- Can inherit abstract	Another class can inherit from abstract and remain abstract

# 🔁 Derived Abstract Classes
You can also create a chain of abstract classes:
```cpp
class A {
public:
    virtual void show() = 0;
};

class B : public A {
    // Still abstract, as show() is not implemented
};

class C : public B {
public:
    void show() override {
        cout << "C's show" << endl;
    }
};
```
# Practice Exercises
- Create an abstract class Vehicle with a pure virtual function startEngine(). Derive Car and Bike and override the function.

-Create a Shape base class and implement draw() in Circle, Square, and Triangle.

- Try to create an object of an abstract class (expect compilation error).

