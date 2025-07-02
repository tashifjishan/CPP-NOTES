# Static Data Members in C++

- Shared by all objects of a class (i.e., class-level variable, not instance-level).
- Only one copy exists in memory, regardless of the number of objects.
- Useful for common properties like a counter for number of objects

```cpp
    class MyClass {
        public:
            static int count; // Declaration
    };
    int MyClass::count = 0; // Definition outside the class

```

# Key Features:
 - Must be defined outside the class.
 - Can be private, protected, or public.
 - Accessed using either object or class name

```cpp
    MyClass::count;
    obj.count;
```

## Example:
    ```cpp
        class Student {
            public:
                static int totalStudents;
                Student() {
                    totalStudents++;
                }
        };
        int Student::totalStudents = 0;

    ```
# Static Member Functions in C++

## ✅ What are they?
- Belong to the class, not to any specific object.
- Can be called without creating an object.
- Can only access static members (not instance variables).

### ✅ Syntax:
```cpp
    class MyClass {
    public:
        static void show() {
            cout << "Static function called";
        }
    };
```
### ✅ Usage:

```cpp
MyClass::show();  // No need to create object
```
### ✅ Limitations:
- Cannot access non-static members directly.
- No this pointer inside a static function (because it's not tied to any object).

### 🔹 Combined Example:
```cpp
#include <iostream>
using namespace std;

class Math {
public:
    static int counter;
    Math() {
        counter++;
    }
    static void displayCount() {
        cout << "Objects created: " << counter << endl;
    }
};
int Math::counter = 0;

int main() {
    Math m1, m2;
    Math::displayCount(); // Output: Objects created: 2
}
```
### 🔹 Summary Table
Feature                     	Static Data Member	Static Member Function
Belongs to class	                        ✅	            ✅
Shared among objects	                    ✅	            ✅
Needs object to call?	                    ❌	            ❌ (can use class name)
Access non-static members?	                ❌	            ❌
Uses this pointer?	                        ❌	            ❌
Defined outside class?	                    ✅ (must)	    ❌ (optional)










