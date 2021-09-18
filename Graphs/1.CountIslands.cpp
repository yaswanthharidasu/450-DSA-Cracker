// Problem statement:
// ------------------
// Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Example:
// --------
// grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
// Output: 2

#include <bits/stdc++.h>
using namespace std;

int m,n;
int grid[501][501];

int x[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int y[8] = {1, -1, 0, 0, 1, -1, -1, 1};

// Checking for valid index
bool isValid(int i, int j){
    return i>=0 && j>=0 && i<m && j<n;
}

void DFS(int i, int j){
    // Making the cell visited by changing the value from 1 to 2
    grid[i][j] = 2;
    // Traversing its adjacent cells
    for(int k=0; k<8; k++){
        if(isValid(i+x[k], j+y[k]) && grid[i+x[k]][j+y[k]] == 1){
            DFS(i+x[k], j+y[k]);
        }
    }
}

int countIslands(int m, int n) {
    int islands = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            // If the cell is not visited and cell is not water (i.e. land)
            if(grid[i][j] != 2 && grid[i][j] != 0){
                islands += 1;
                DFS(i,j);
            }
        }
    }
    return islands;
}

int main() {
    cin>>m>>n;
    for (int i=0; i<m; i++) 
        for (int j=0; j<n; j++) 
            cin>>grid[i][j];

    cout<<countIslands(m,n);
    return 0;
}
