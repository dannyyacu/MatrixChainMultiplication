# Dynamic Programming
In this assignment, you will implement the dynamic programming solution to the matrix chain multiplication problem.

All the information you need regarding dynamic programming can be found in your textbook (Algorithm Design and Applications, Chapter 12).

### Step 1 - Setup
Other than the `main.cpp` file, your implementation will be limited to `matrixChain.cpp`. You should always be able to compile everything with something simple like: `c++ *.cpp -o main`.

The `main.cpp` file provided can be used for debugging your initial implementation.  


Take your time to understand the structure of these files.
- in `main.cpp` you have an array defining the dimensions of matrices that you want to multiply.
- `matrixChain.h` is a class that stores the actual chain of matrices.
- `chain` stores the matrices (each Matrix is a bidimensional vector) while `dimensions` stores the sizes of these matrices.
- as we have seen in class, the matrix at position i in `chain` has number of rows = `dimensions[i]` and number of columns = `dimensions[i+1]`.

The constructor of the class `ChainMatrix` takes as input an array of dimensions `dimensions` and the number of matrices `num`. Remember that this number is always 1 less the number of dimensions you have in the array `dimensions`.
By calling the constructor a sequence of `num` matrices will be generated. 

Two functions are already implemented the constructor `MatrixChain` and `generate_matrix`. These are creating the matrices for you.


### Step 3 - Dynamic programming approach, minimum number of steps

As a first step let's implement function `dynamicChain`. Here you should implement the algorithm discussed in class. This will compute the matrix N storing the minimum number of steps required for multiplying the chain of matrices.

Once completed, print the last value computed in the matrix (the one telling you the number of steps required to multiply this chain of matrices, and return the full matrix.


### Step 4 - Dynamic programming approach, subdivision.

Let's extend the previous function now. Modify the algorithm so to also compute the matrix K storing all the k values describing how to get to the optimal solution.

Once you have created the matrix K, print the top-right most value in the matrix (in addition to the value for N) and return the matrix K.

### Step 5 - Wrapping up and constructing the final main.cpp file

Once you are confident your program is doing what it should, uncomment the first two lines of the `main.cpp` file. Your code should look like this

```c++
    int array[] = {84,87,78,16,94,36,87,93,50,22,63,28,91,60,64,27,41,27,73,37,12,69,68,30,83,31,63,24,68,36,30,3,23,59,70,68,94,57,12,43,30,74,22,20,85,38,99,25,16,71,14,27,92,81,57,74,63,71,97,82,6,26,85,28,37,6,47,30,14,58,25,96,83,46,15,68,35,65,44,51,88,9,77,79,89,85,4,52,55,100,33,61,77,69,40,13,27,87,95,40,96};
    MatrixChain chain = MatrixChain(array, 100);
    
    Matrix m = chain.dynamicChain(); 

return 0;
```
The function `dynamicChain()` should print the value in the top-right corner of N followed by the value in the top-right corner of K. The two values should be separated by a blank space only. (Please stick to this synthax to make sure the Autograder will work appropriately)

Additionally, update this README file, copy and paste the results printed by your program.

[UPDATE HERE]


### Step 5 BONUS - Complete the dynamic programming multiplication (+2 on final grade)

Now that you have the matrix K we know what is the correct order for applying our matrix multiplications. So let's do this.

First, create a new main file called `main-bonus.cpp` by copying `main.cpp`.

Start by implementing the function `Matrix multiply(Matrix a, Matrix b);` in `MatrixChain` that, given two matrices, returns their multiplication.

Then, modify function `dynamicChain()` again. This time, instead of returning K, use K for computing the matrix multiplications in the optimal sequence. Then, return the matrix `M` obtained, instead of returning K, and add the following line to your `main-bonus.cpp` file.


```c++
    cout << "Final matrix sizes " << M.size() << " " << M[0].size() << endl;

return 0;
```

[UPDATE HERE THE VALUES RETURNED]

