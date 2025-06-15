#include <bits/stdc++.h>
using namespace std;

int getMaxRectangleArea(vector<vector<bool>>& binaryMatrix) {
    int rowCount = binaryMatrix.size();
    int colCount = binaryMatrix[0].size();
    
    vector<vector<int>> heightMatrix(rowCount, vector<int>(colCount, 0));

    for (int col = 0; col < colCount; col++) {
        heightMatrix[0][col] = binaryMatrix[0][col];
        for (int row = 1; row < rowCount; row++) {
            heightMatrix[row][col] = (binaryMatrix[row][col] == 0) ? 0 : heightMatrix[row - 1][col] + 1;
        }
    }

    for (int row = 0; row < rowCount; row++) {
        vector<int> frequency(rowCount + 1, 0);

        for (int col = 0; col < colCount; col++)
            frequency[heightMatrix[row][col]]++;

        int colIndex = 0;
        for (int height = rowCount; height >= 0; height--) {
            while (frequency[height] > 0) {
                heightMatrix[row][colIndex] = height;
                colIndex++;
                frequency[height]--;
            }
        }
    }

    int currentArea, maximumArea = 0;
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            currentArea = (col + 1) * heightMatrix[row][col];
            maximumArea = max(maximumArea, currentArea);
        }
    }

    return maximumArea;
}

int main() {
    vector<vector<bool>> binaryMatrix = {
        { 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 0, 1, 0 }
    };
    
    cout << "Area of the largest rectangle is " << getMaxRectangleArea(binaryMatrix);
    return 0;
}
