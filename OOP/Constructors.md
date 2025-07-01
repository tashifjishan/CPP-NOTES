# What is a constructor?

A constructor is a special member function of a class that is automatically called when an object is created.

Its main purpose is to initialize objects.

**Syntax**

```cpp

        class ClassName {
        public:
            ClassName(){
                //constructor
            };  
        };


```

# Key Features of Constructors:
- Same name as the class.
- No return type (not even void).
- Automatically invoked when an object is created.
- Can be overloaded (multiple constructors with different parameters).

# Types of Constructors

1. Default Constructor
    - Takes no parameters.
    - Called when no arguments are passed during object creation.

        ```cpp

                    class Example {
                        public:
                            Example() {
                                cout << "Default constructor called";
                            }
                    };
        ```

2. Parameterized Constructor
    - Takes arguments.
    - Allows initialization with specific values.
    ```cpp
        class Example {
            private:
                int value;
            public:
                Example(int x) {
                   value = x;
                }
        };
    ```

3. Copy Constructor
    - Takes reference to an object of the same class.
    - Used to create a copy of an object.

    ```cpp
        class Example {
            public:
                int a;
                Example(int x) { a = x; }
                Example(const Example &obj) {
                    a = obj.a;
                }
        };
    ```


4. Constructor with Default Arguments
    - Allows parameters to have default values.

```cpp
        class MyClass {
        public:
            MyClass(int x = 0, int y = 0) {
                // constructor with default arguments
            }
        };

```

5. Dynamic Constructor
    - Allocates memory dynamically using new inside the constructor.

```cpp
        class MyClass {
            int *arr;
        public:
            MyClass(int size) {
                arr = new int[size]; // dynamic memory allocation
            }
        };
```

6. Explicit Constructor

```cpp
        class MyClass {
        public:
            explicit MyClass(int x) {
                cout << "Value: " << x << endl;
            }
        };

        void display(MyClass obj) {}

        int main() {
            display(10); // ❌ Error: Cannot convert int to MyClass implicitly
            display(MyClass(10)); // ✅ OK: Explicit construction
        }
```

    - display() expects a parameter of type MyClass.
    - But you gave it an int (10).
    - C++ checks: "Hey, do I have a way to turn an int into a MyClass?"
    - It finds that MyClass(int) exists — a constructor that takes an int.
    - So C++ automatically calls that constructor to convert 10 into a MyClass object.