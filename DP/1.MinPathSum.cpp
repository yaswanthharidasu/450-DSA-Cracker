// Problem Statement:
// ------------------
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// You can only move either down or right at any point in time.
// Example:
// ----------
// Input: 
// grid = [[1,3,1],
//         [1,5,1],
//         [4,2,1]]
// Output: 7

#include<bits/stdc++.h>
using namespace std;

int m,n;
int grid[200][200];

int dp[200][200];
    
int bruteforce(int i, int j){
    // Reached last cell
    if(i==m-1 && j==n-1)
        return grid[m-1][n-1];
        
    // Can move right and bottom
    if(i+1<m && j+1<n){
        return min(bruteforce(i+1, j), bruteforce(i, j+1)) + grid[i][j];   
    }
    // Can move only bottom
    else if(i+1<m){
        return bruteforce(i+1, j) + grid[i][j];   
    }
    // Can move only right
    else if(j+1<n){
        return bruteforce(i, j+1) + grid[i][j];   
    }
    return 0;
}

int topDown(int i, int j){
    // Reached last cell
    if(i==m-1 && j==n-1)
        return grid[m-1][n-1];

    // Already computed value
    if(dp[i][j] != -1)
        return dp[i][j];
        
    // Can move right and bottom
    if(i+1<m && j+1<n){
        dp[i][j] =  min(topDown(i+1, j), topDown(i, j+1)) + grid[i][j];   
    }
    // Can move only bottom
    else if(i+1<m){
        dp[i][j] = topDown(i+1, j) + grid[i][j];   
    }
    // Can move only right
    else if(j+1<n){
        dp[i][j] = topDown(i, j+1) + grid[i][j];   
    }
    return dp[i][j];
}

int bottomUp() {
    memset(dp, 0, sizeof(dp));

    // For 1st row/column cells, the dp[i][j] will be sum of cell value and previous row/column dp value   
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(i==1)
                dp[i][j] = dp[i][j-1] + grid[i-1][j-1];
            else if(j==1)    
                dp[i][j] = dp[i-1][j] + grid[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

int main() {
    
    cin>>m>>n;

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];
    
    memset(dp, -1, sizeof(dp));
    cout<<"Bruteforce: "<<bruteforce(0, 0)<<endl;
    cout<<"Top Down: "<<topDown(0, 0)<<endl;
    cout<<"Bottom Up:"<<bottomUp()<<endl;
}