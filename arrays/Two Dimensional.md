```cpp
int matrix[2][2] = {
    {9, 2},
    {4, 6}
};
```
- Here **matrix** is the pointer to the first element of the 2d array in consideration
- If you dereference matrix pointer (i.e. *matrix), you get a pointer to the first element of the first array of the main array.
- now if you dereference *matrix again [i.e. *(*matrix) ], you get: 9

