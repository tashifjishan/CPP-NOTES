# Inline Member Functions

### Definition:

Inline member functions are defined inside the class definition. The compiler may attempt to insert the function’s code directly at the point of call to reduce function call overhead.

#### Key Points:

- Defined within the class body.
- Automatically considered for inlining.
- May improve performance for short, frequently used functions.
- Not guaranteed to be inlined — the compiler decides.

#### Example:

```cpp
class MyClass {
public:
    int add(int a, int b) {
        return a + b;  // Inline function
    }
};

```
# Non-Inline Member Functions

### Definition:

Non-inline member functions are declared inside the class but defined outside the class body. These functions are typically compiled separately and not inlined.

#### Key Points:

- Declared in the class, defined outside.
- Not inlined unless explicitly marked with inline.
- Suitable for long or complex functions.

#### Example:
```cpp
class MyClass {
public:
    int multiply(int a, int b);  // Declaration
};

int MyClass::multiply(int a, int b) {  // Definition
    return a * b;
}

```