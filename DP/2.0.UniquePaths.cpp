// Problem Statement:
// ------------------
// A robot is located at the top-left corner of a m x n grid. The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid.
// How many possible unique paths are there?
// Example:
// --------
// Input: m = 3, n = 7
// Output: 28

#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int bruteforce(int i, int j, int m, int n){
    // Reached outside of the grid
    if(i>=m || j>=n)
        return 0;
    // Reached last cell
    if(i==m-1 && j==n-1){
        return 1;
    }
    // Adding the ways possible by moving down and right
    return bruteforce(i+1, j, m, n) + bruteforce(i, j+1, m, n);
}

int topDown(int i, int j, int m, int n){
    if(i>=m || j>=n)
        return 0;
    
    if(i==m-1 && j==n-1){
        return 1;
    }
    // Checking if already computed
    if(dp[i][j])
        return dp[i][j];
    // Storing the computed values
    return dp[i][j] = topDown(i+1, j, m, n) + topDown(i, j+1, m, n);
}

int bottomUp(int m, int n) {
    memset(dp, 0, sizeof(dp));
    
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(i==1 || j==1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

int main(){
    int m,n; 
    cin>>m>>n;
    cout<<"Bruteforce: "<<bruteforce(0, 0, m, n)<<endl;
    cout<<"Top Down: "<<topDown(0, 0, m, n)<<endl;
    cout<<"Bottom Up: "<<bottomUp(m, n)<<endl;
    return 0;
}