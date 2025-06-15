#include <bits/stdc++.h>
using namespace std;

bool isValidMove(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col) {
    return (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) &&
            grid[row][col] == 1 && !visited[row][col];
}

void findShortestPath(vector<vector<int>> &grid, vector<vector<bool>> &visited,
                      int currRow, int currCol, int targetRow, int targetCol,
                      int &minDistance, int currentDistance) {
    if (currRow == targetRow && currCol == targetCol) {
        minDistance = min(currentDistance, minDistance);
        return;
    }

    visited[currRow][currCol] = true;

    if (isValidMove(grid, visited, currRow + 1, currCol))
        findShortestPath(grid, visited, currRow + 1, currCol, targetRow, targetCol, minDistance, currentDistance + 1);
    
    if (isValidMove(grid, visited, currRow, currCol + 1))
        findShortestPath(grid, visited, currRow, currCol + 1, targetRow, targetCol, minDistance, currentDistance + 1);
    
    if (isValidMove(grid, visited, currRow - 1, currCol))
        findShortestPath(grid, visited, currRow - 1, currCol, targetRow, targetCol, minDistance, currentDistance + 1);
    
    if (isValidMove(grid, visited, currRow, currCol - 1))
        findShortestPath(grid, visited, currRow, currCol - 1, targetRow, targetCol, minDistance, currentDistance + 1);
    
    visited[currRow][currCol] = false;
}

int getShortestPathLength(vector<vector<int>> &grid, pair<int, int> &start, pair<int, int> &end) {
    if (grid.empty() || grid[start.first][start.second] == 0 || grid[end.first][end.second] == 0)
        return -1;

    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols));
    int minDistance = INT_MAX;

    findShortestPath(grid, visited, start.first, start.second, end.first, end.second, minDistance, 0);

    return (minDistance != INT_MAX) ? minDistance : -1;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> end = {3, 4};

    int distance = getShortestPathLength(grid, start, end);
    cout << distance;

    return 0;
}
