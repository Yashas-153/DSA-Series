#include<bits/stdc++.h>
using namespace std;

int LIS(int idx1, int idx2, string s1, string s2, vector<vector<int>> &dp){
    if(idx1 == 0 and idx2 == 0){
        return s1[idx1] == s2[idx2];
    }
    if(idx1 < 0 or idx2 < 0){
        return 0;
    }

    if(s1[idx1]== s2[idx2]){
        return 1 + LIS(idx1-1, idx2- 1, s1,s2,dp);
    }
    return 0 + max(LIS(idx1-1,idx2,s1,s2,dp),LIS(idx1,idx2-1,s1,s2,dp));

}

int main(){
    string s1 = "abcedef";
    string s2 = "bkldef";
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1-1));
    cout<<LIS(m-1,n-1,s1,s2,dp);

    return 0;
}