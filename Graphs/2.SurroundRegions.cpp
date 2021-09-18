// Problem Statement:
// ------------------
// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// Example:
// ---------
// board = [
//     ["X","X","X","X"],
//     ["X","O","O","X"],
//     ["X","X","O","X"],
//     ["X","O","X","X"]]

// Output:
// [["X","X","X","X"],
// ["X","X","X","X"],
// ["X","X","X","X"],
// ["X","O","X","X"]]

#include<bits/stdc++.h>
using namespace std;
    
int m,n;
int board[200][200];

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};


bool isValid(int i, int j){
    return i>=0 && j>=0 && i<m && j<n;   
}

void DFS(int i, int j, char ch){
    // Changing the cell with the req character
    board[i][j] = ch;
    // Exploring its adjacent cells
    for(int k=0; k<4; k++){
        // If adjacent cell is valid and has 'O' 
        if(isValid(i+x[k], j+y[k]) && board[i+x[k]][j+y[k]] == 'O')
            DFS(i+x[k], j+y[k], ch);
    }
}


int main(){
    cin>>m>>n;

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>board[i][j];

    // First, finding the 'O's present on the edges of the board and convert them to 'Z'
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j] == 'O')
                DFS(i, j, 'Z');
        }
    }

    // Then convert the remaining O's to X's (because they are not adjacent to any O's which are present on the edges)
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 'O')
                DFS(i,j,'X');
        }
    }
    
    // Finally convert the Z's into O's
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 'Z')
                board[i][j] = 'O';
        }
    }
    return 0;
}

// Explanation:
// -------------
// Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
// Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
