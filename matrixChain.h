#ifndef MATRIXCHAIN_H
#define MATRIXCHAIN_H

#include <iostream>
#include <vector>

#define NUM 100 //maximum value for a cell of the matrix

using namespace std;

typedef vector<vector<int> > Matrix;

class MatrixChain
{
protected:
    vector<Matrix> chain;
    int* dimensions;
    int num;

  public:
    MatrixChain(int* array, int num);
    Matrix multiply(Matrix a, Matrix b); //TODO - BONUS
    Matrix dynamicChain(); //TODO


    void printDimensions(){
      //print the dimensions generated
      cout << "{";
      for(int i=0; i<num; i++){
        cout << dimensions[i] << ",";
      }
      cout << dimensions[num] << "}" << endl;
    }

  private:
    void generate_matrix(int, int);
};

#endif
