// Problem Statement:
// ------------------
// Find the total no.of ways to make the change
// Input: amount = 5, coins = [1,2,5]
// Output: 4
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

#include<bits/stdc++.h>
using namespace std;

int coinChange2(vector<int>& coins, int amount) {
    // Columns indicates the amount
    // Rows indicate the coins we use inorder to calculate amount
    int m = coins.size() + 1;
    int n = amount + 1;
    
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
                
    for(int i=0; i<m; i++){
        // For all no coin cells (i.e. row 0), ans is zero (as already intialized no need to calculate)
        if(i==0)
            continue;
        
        for(int j=0; j<n; j++){
            // For all amount = 0 cells (i.e. column 0), ans needs to be 1
            if(j==0){
                dp[i][j] = 1;
                continue;
            }
            // Finding current_amount - newly_added_coin.
            // If it is <0 then it means newly added coin is not useful in obtaining the amount
            // If it is >=0 then it means the column = remaining_amount and we need to use no.of ways to find that amount 
            int column = j-coins[i-1];
            
            if(column >= 0){
                // Not including the newly added coin + including the newly added coin along with some other coins
                dp[i][j] = dp[i-1][j] + dp[i][column];
            }
            else{
                // Not including the newly added coin
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int n; cin>>n;
    vector<int> coins(n);

    for(int i=0; i<n; i++)
        cin>>coins[i];

    int amount; cin>>amount;

    cout<<coinChange2(coins, amount)<<endl;
    return 0;
}