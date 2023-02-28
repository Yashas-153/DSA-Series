#include<bits/stdc++.h>
using namespace std;

int editDistaceTabulation(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

    for(int i =0;i<=m;i++){
        dp[i][0] = i;
    }
    for(int j = 0;j<=n;j++){
        dp[0][j] = j;
    }

    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j]  = 1+ min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }

    return dp[m][n];


}

int f(string &s1, string &s2, int i , int j,vector<vector<int>> &dp){
    //basecase 
    if(i < 0) return j+1;
    if(j < 0) return  i+1;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s1[i] == s2[j]){
        //cout<<"if"<<endl;
        return dp[i][j] = f(s1,s2,i-1,j-1,dp);
    }
    else
    return dp[i][j] = 1 + min(f(s1,s2,i-1,j-1,dp),min(f(s1,s2,i,j-1,dp),f(s1,s2,i-1,j,dp)));
}

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return f(word1,word2,m-1,n-1,dp);
}

int main(){
    string s1 = "horse";
    string s2 = "ros";
    cout<<minDistance(s1,s2)<<endl;
    cout<<editDistaceTabulation(s1,s2);
}