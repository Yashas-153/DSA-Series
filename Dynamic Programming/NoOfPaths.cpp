#include<bits/stdc++.h>
using namespace std;
int getPaths(int n, int m, int x, int y, vector<vector<int>> &dp){
    if( x == n - 1 and y == m -1){
        return 1;
    }
    if( x >= n or y >=m ){
        return 0;
    }
    if(dp[x][y]!= -1){
        return dp[x][y];
    }
    
    int down = getPaths(n,m,x +1, y,dp);
    int right =  getPaths(n,m,x,y+1,dp);
    return dp[x][y] = down + right; 
}


int countPaths(int n, int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return getPaths(n,m,0,0,dp);
}

int main(){
    int n = 3;
    int m = 2;
    cout<<countPaths(n,m);
    return 0;
}