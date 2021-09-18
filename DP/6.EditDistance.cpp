#include<bits/stdc++.h>
using namespace std;

string w1, w2;
int dp[501][501];
int bruteforce(int m, int n){
    // Both strings are emtpy
    if(m == -1 && n == -1)
        return 0;

    // If the target string is empty then we need to delete the remanining characters from string w1
    if(n == -1)
        return m+1;
    
    // If the string w1 is empty then we need to the insert the remaining characters of the target string
    if(m == -1)
        return n+1;
    
    // If last characters of w1 and target string matched then no operation need to be performed and move to next character
    if(w1[m] == w2[n]){
        return bruteforce(m-1, n-1);
    }
    else{
        // One operation needs to perfomed here. We have 3 options:
        // 1. Replace the character            -> Then both characters matches, hence we can proceed to next character
        // 2. Delete the character from w1     -> Then we move to next character of w1 and compare
        // 3. Insert the character in w1       -> Then both characters match, hence we can proceed to next character
        return min({bruteforce(m-1, n-1), bruteforce(m-1, n), bruteforce(m, n-1)})+1;
    }
}

int topDown(int m, int n){
    // Both strings are emtpy
    if(m == -1 && n == -1)
        return 0;

    // If the target string is empty then we need to delete the remanining characters from string w1
    if(n == -1)
        return m+1;
    
    // If the string w1 is empty then we need to the insert the remaining characters of the target string
    if(m == -1)
        return n+1;
    
    // If last characters of w1 and target string matched then no operation need to be performed and move to next character
    if(w1[m] == w2[n]){
        dp[m][n] = topDown(m-1, n-1);
    }
    else{
        // One operation needs to perfomed here. We have 3 options:
        // 1. Replace the character            -> Then both characters matches, hence we can proceed to next character
        // 2. Delete the character from w1     -> Then we move to next character of w1 and compare
        // 3. Insert the character in w1       -> Then both characters match, hence we can proceed to next character
        dp[m][n] = min({topDown(m-1, n-1), topDown(m-1, n), topDown(m, n-1)})+1;
    }

    return dp[m][n];
}

int main(){

    string s1, s2;
    cin>>s1;
    cin>>s2;

    w1 = s1, w2 = s2;
    memset(dp, 0, sizeof(dp));

    // cout<<"Brute force: "<<bruteforce(0, w, n, wt, val)<<endl;    
    // cout<<"Top Down: "<<topDown(0, w, n, wt, val)<<endl;
    // cout<<"Bottom Up: "<<bottomUp(w, n, wt, val)<<endl;
}