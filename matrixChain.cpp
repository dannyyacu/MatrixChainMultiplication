#include "matrixChain.h"

#include <typeinfo>
#include <random>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

MatrixChain::MatrixChain(int* dimensions, int num){

  this->dimensions = dimensions;
  this->num = num;

  for(int i=0;i<num;i++){
    generate_matrix(dimensions[i],dimensions[i+1]);
  }
}

void MatrixChain::generate_matrix(int rows, int cols){
  srand(time(0));

  Matrix matrix(rows, vector<int>(cols,0));
  for (int j=0;j<rows;j++){//row
    for (int k=0;k<cols;k++){//
          matrix[j][k] = rand()%NUM+1;
      }
  }
  chain.push_back(matrix);
}

Matrix MatrixChain::multiply(Matrix a, Matrix b){
  //implement here the simple multiplication between two matrices
}

Matrix MatrixChain::dynamicChain(){
  int minimum;
  int n = chain.size();
  Matrix N(n, vector<int>(n, 0));
  Matrix K(n, vector<int>(n, 0));
  
  for(int i = 0; i < n; i++){
    N[i][i] = 0;
  }

  for(int b = 1; b < n; b++){
    for(int i = 0; i < n-b; i++){
      int j = i + b;
      N[i][j] = INT_MAX;
      for(int k = i; k < j; k++){
        minimum = min(N[i][j],  N[i][k] +  N[k+1][j] + dimensions[i] * dimensions[k+1] * dimensions[j+1]);
        if(minimum < N[i][j]){
          K[i][j] = k;
          N[i][j] = minimum;
        }
      }
    }
  }
  cout << N[0][n - 1] << " " << K[0][n - 1] << endl;
  return K;
}
