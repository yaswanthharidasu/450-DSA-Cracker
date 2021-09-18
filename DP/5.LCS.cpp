// Problem Statement:
// ------------------
// Find the length of the longest common subsequence
// Example:
// --------
// s1 = abcde ; s2 = ace
// Output: 3

#include<bits/stdc++.h>
using namespace std;

// Instead of passing strings to the function declare two temporary global variables
string txt1, txt2;

int bruteforce(int m, int n){
        
    // One string is empty
    // Not zero because we need to compare 0th index characters also
    if(m==-1 || n==-1)
        return 0;
    
    int max_length = 0;
    
    if(txt1[m] == txt2[n])
        max_length = 1+bruteforce(m-1, n-1);
    else
        max_length = max(bruteforce(m-1, n), bruteforce(m, n-1));
        
    return max_length;
}

int dp[1000][1000];

int topDown(int m, int n){
    
    // One string is empty
    // Not zero because we need to compare 0th index characters also
    if(m==-1 || n==-1)
        return 0;
    
    // Returning already computed value
    if(dp[m][n] != -1)
        return dp[m][n];
            
    if(txt1[m] == txt2[n])
        dp[m][n] = 1+topDown(m-1, n-1);
    else
        dp[m][n] = max(topDown(m-1, n), topDown(m, n-1));
    
    return dp[m][n];
}

int bottomUp(string text1, string text2) {
    memset(dp, 0, sizeof(dp));
    
    int m = text1.length()+1, n = text2.length()+1;
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            // Two characters matched
            if(text1[i-1] == text2[j-1]){
                // Chopping off last characters in both strings
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                // Chopping off last characters in only one string
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m-1][n-1];
}

int main(){
    string s1, s2;
    cin>>s1>>s2;

    txt1 = s1;
    txt2 = s2;
    memset(dp, 0, sizeof(dp));

    cout<<"Bruteforce: "<<bruteforce(txt1.length()-1, txt2.length()-1);
    cout<<"Top Down: "<<topDown(txt1.length()-1, txt2.length()-1);
    cout<<"Bottom Up: "<<bottomUp(s1, s2);

    return 0;
}
