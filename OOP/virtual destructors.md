# 🔷  Virtual Destructors

If a class has virtual functions and is intended to be inherited from, its destructor should be virtual to ensure proper cleanup when deleting via a base pointer.

- ❌ Problem Without Virtual Destructor:
```cpp
class Base {
public:
    ~Base() {
        cout << "Base Destructor" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived Destructor" << endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b;  // Only Base destructor is called → Memory leak!
}
```
✅ Solution:

```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor" << endl;
    }
};
```