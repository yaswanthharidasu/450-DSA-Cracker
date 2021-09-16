// Problem Statement:
// ------------------
// Find the max profit obtained if each item can be included only once
// Example:
// ----------
// 4 5
// 5 3 2 1
// 60 50 70 30
// Ouput: 120

#include<bits/stdc++.h>
using namespace std;

int bruteforce(int i, int weight, int n, int wt[], int val[]){
    
    // Weight exceeded or items are completed 
    if(weight <= 0 || i>=n)
        return 0;
        
    int maxProfit = 0;
    
    // If weight of current item is greater than knapsack weight then cannot include that item
    if(wt[i] > weight)
        maxProfit = bruteforce(i+1, weight, n, wt, val);
    else
        // Include item or not include item
        maxProfit = max(bruteforce(i+1, weight-wt[i], n, wt, val) + val[i], bruteforce(i+1, weight, n, wt, val));
        
    return maxProfit;
}

int dp[10001][10001];

int topDown(int i, int weight, int n, int wt[], int val[]){
    // Weight exceeded or items are completed 
    if(weight <= 0 || i>=n)
        return 0;
        
    if(dp[i][weight] != -1)
        return dp[i][weight];

    // If weight of current item is greater than knapsack weight then cannot include that item
    if(wt[i] > weight)
        dp[i][weight] = bruteforce(i+1, weight, n, wt, val);
    else
        // Include item or not include item
        dp[i][weight] = max(bruteforce(i+1, weight-wt[i], n, wt, val) + val[i], bruteforce(i+1, weight, n, wt, val));
        
    return dp[i][weight];
}

int bottomUp(int w, int n, int wt[], int val[]) 
{ 
    int items = n+1;
    int weight = w+1;
    
    int dp[items][weight];

    memset(dp, 0, sizeof(dp));
    
    for(int i=1; i<items; i++){
        for(int j=1; j<weight; j++){            
            // Finding difference between knapsack size (j) and weight of the newly added item
            int column = j-wt[i-1];
            if(column >= 0){
                // Including that weight (that means it's value is added )
                // Not including that weight
                dp[i][j] = max(dp[i-1][j], dp[i-1][column]+val[i-1]);
            }
            else{
                // If current knapsack size is less than newly added item's weight then the item cannot be included
                dp[i][j] = dp[i-1][j];
            }   
        }
    }
    return dp[items-1][weight-1];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/yaswanth/M.Tech/450-DSA-Cracker/input.txt", "r", stdin);
        freopen("/home/yaswanth/M.Tech/450-DSA-Cracker/output.txt", "w", stdout);
    #endif
    
    int n, w;
    cin>>n>>w;
    
    int wt[n], val[n];
    
    for(int i=0;i<n;i++)
        cin>>wt[i];
    
    for(int i=0;i<n;i++)
        cin>>val[i];

    memset(dp, -1, sizeof(dp));
        
    cout<<"Brute force: "<<bruteforce(0, w, n, wt, val)<<endl;    
    cout<<"Top Down: "<<topDown(0, w, n, wt, val)<<endl;
    cout<<"Bottom Up: "<<bottomUp(w, n, wt, val)<<endl;
	return 0;
}