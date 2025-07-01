# What is an inline function?

An inline function is just a request to the compiler to replace the function call with the function's code.

The compiler may or may not honor that request.

There's no way to "see" it directly in high-level C++ code. 

If interested the generated assembly code can be look


> ❗ Important Notes:

Can't contain loops, switch, or recursion (compiler may reject them as inline).

```cpp

    #include <iostream>
    using namespace std;

    inline int add(int a, int b) {
        return a + b;
    }

    int main() {
        cout << "Sum: " << add(5, 3) << endl;  
        // Compiler may replace this with: cout << "Sum: " << (5 + 3) << endl;
        return 0;
    }

```