// Problem Statement:
// ------------------
// A robot is located at the top-left corner of a m x n grid. The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid.
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and space is marked as 1 and 0 respectively in the grid.

#include<bits/stdc++.h>
using namespace std;

int m,n;
int grid[100][100];
int dp[101][101];

int bruteforce(int i, int j){
    // Moving out of the grid
    if(i>=m || j>=n)
        return 0;
    
    // Reached end of the grid
    if(i==m-1 && j==n-1)
        return 1;
    
    // Obstacle present
    if(grid[i][j] == 1)
        return 0;
    
    
    return bruteforce(i+1, j) + bruteforce(i, j+1);
}

int topDown(int i, int j){
    // Moving out of the grid
    if(i>=m || j>=n)
        return 0;
    
    // Obstacle present
    if(grid[i][j] == 1)
        return 0;

    // Reached end of the grid, End of the grid can also have obstacle hence checking obstacle condition first
    if(i==m-1 && j==n-1)
        return 1;

    // Checking if already computed
    if(dp[i][j])
        return dp[i][j];

    return dp[i][j] = topDown(i+1, j) + topDown(i, j+1);
}

int bottomUp(int m, int n) {
    memset(dp, 0, sizeof(dp));
    // Traversing first column
    // If no obstacle, then no.of paths possible from starting cell to that cell is 1
    // If there is obstacle in a cell, then we cannot enter that cell and all the remaining cells in the first column 
    for(int i=1; i<m; i++){
        if(grid[i-1][0] == 0)
            dp[i][1] = 1;
        else
            break;
    }
    // Traversing first row
    // If no obstacle, then no.of paths possible from starting cell to that cell is 1
    // If there is obstacle in a cell, then we cannot enter that cell and all the remaining cells in the first row 
    for(int j=1; j<n; j++){
        if(grid[0][j-1] == 0)
            dp[1][j] = 1;
        else
            break;
    }
    // Finding possible paths for remaining cells
    for(int i=2; i<m; i++){
        for(int j=2; j<n; j++){
            if(grid[i-1][j-1] == 1)
                continue;
                
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

int main(){
    cin>>m>>n;

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];

    cout<<"Bruteforce: "<<bruteforce(0, 0)<<endl;
    cout<<"Top Down: "<<topDown(0, 0)<<endl;
    cout<<"Bottom Up: "<<bottomUp(m, n)<<endl;
    return 0;
}