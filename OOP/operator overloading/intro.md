Operator overloading allows you to define custom behavior for operators (+, -, ++, --, etc.) when used with user-defined types (like classes).

# Unary Operator Overloading: 
```cpp

    class Point {
    int x, y;
    public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-() {
        return Point(-x, -y);
    }
    }
```
- Prefix ++:
```cpp
    Counter operator++() {
        ++value;
        return *this;
    }
```
- Postfix ++ has a dummy int parameter

```CPP
    Counter operator++(int) {
        Counter temp = *this;
        value++;
        return temp;
    }
```

# Binary operator overloading

```cpp
class Complex {
    float real, imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overload +
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        std::cout << real << " + " << imag << "i\n";
    }
};

int main() {
    Complex c1(1.2, 3.4), c2(5.6, 7.8);
    Complex c3 = c1 + c2;
    c3.display();  // Output: 6.8 + 11.2i
}

```