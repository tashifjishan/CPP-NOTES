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


