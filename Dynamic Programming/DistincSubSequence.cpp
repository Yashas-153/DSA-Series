#include<bits/stdc++.h>
using namespace std;

int bf(string s, string t){
    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i = 0;i<=m;i++){
        dp[i][0] = 1;
    }
    // for(int i = 1;i<=m;i++){
    //     dp[i][0] = 0;
    // }
    
    for(int i =1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];

        }
    }
    for(int i =0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            cout<< dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];

}
int f(string s, string t, int i, int j,vector<vector<int>> &dp){
    //basecase 
    if(j < 0) return  1;
    if(i < 0) return  0;

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] = f(s,t,i-1,j-1,dp) + f(s,t,i-1,j,dp);
    }else
    return dp[i][j] = f(s,t,i-1,j,dp);
}

int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return  bf(s,t);
    
}

int main(){
    string s = "babgbag";
    string t = "bag";
    cout<<bf(s,t);
}