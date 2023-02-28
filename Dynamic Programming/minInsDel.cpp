#include<bits/stdc++.h>
using namespace std;

int tabulation(string s1, string s2){
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
                dp[i][j]  = 1+ min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];


}

int f(string &s1 , string &s2, int i, int j){
    //BASECASE
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(s1[i] == s2[j]){
        return f(s1,s2,i-1,j-1);
    }
    return  1 + min(f(s1,s2,i,j-1),f(s1,s2,i-1,j));
}

int minInsDel(string s1, string s2){
    int m = s1.length();
    int n = s2.length();

    return f(s1,s2,m-1,n-1);

}

int main(){
    string s1 = "abcdef";
    string s2 = "ance";

    cout<<minInsDel(s1,s2)<<endl;
    cout<<tabulation(s1,s2);
    return 0;

}