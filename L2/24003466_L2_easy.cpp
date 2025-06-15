#include <iostream>
#include <vector>
using namespace std;

void multiplyMatrices(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, 
                      vector<vector<int>>& resultMatrix) {
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int rowsB = matrixB.size();
    int colsB = matrixB[0].size();

    if (colsA != rowsB) {
        cout << "Invalid Input: Incompatible matrix dimensions." << endl;
        exit(EXIT_FAILURE);
    }

    resultMatrix.resize(rowsA, vector<int>(colsB, 0)); 
  
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    vector<vector<int>> matrixA = { {1, 1}, {2, 2} };
    vector<vector<int>> matrixB = { {1, 1}, {2, 2} };
    vector<vector<int>> resultMatrix;

    multiplyMatrices(matrixA, matrixB, resultMatrix);

    cout << "Multiplication of given two matrices is:\n";
    for (const auto& row : resultMatrix) {
        for (int value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }

    return 0;
}
