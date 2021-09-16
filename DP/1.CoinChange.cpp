// Problem Statement:
// ------------------
// Find min no.of coins to make the change
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Input: coins = [2], amount = 3
// Output: -1

#include<bits/stdc++.h>
using namespace std;

int dp[10000] = {0};

int bruteforce(vector<int>& coins, int amount) {
        
    if(amount == 0)
        return 0;
    
    if(amount < 0)
        return -1;
    
    int minCoins = INT_MAX;
    
    for(int coin: coins){
        int remaining = amount - coin;
        int ans = bruteforce(coins, remaining);
        if(ans != -1){
            minCoins = min(minCoins, ans+1);
        }
    }
    
    if(minCoins == INT_MAX)
        minCoins = -1;
    
    return minCoins;
}
    
int coinChange(vector<int>& coins, int amount) {
    
    if(amount == 0)
        return 0;
    
    if(amount < 0)
        return -1;
    
    // Checking if already computed
    if(dp[amount])
        return dp[amount];
    
    int minCoins = INT_MAX;
    
    for(int coin: coins){
        int remaining = amount - coin;
        int ans = coinChange(coins, remaining);
        if(ans != -1){
            minCoins = min(minCoins, ans+1);
            // Storing the computed new value
            dp[amount] = minCoins;
        }
    }
    
    if(minCoins == INT_MAX){
        minCoins = -1;
        // Storing the computed new value
        dp[amount] = -1;
    }
    
    return dp[amount];
}

int main(){

    int n; cin>>n;
    vector<int> coins(n);

    for(int i=0; i<n; i++)
        cin>>coins[i];

    int amount; cin>>amount;

    cout<<coinChange(coins, amount)<<endl;
    return 0;
}