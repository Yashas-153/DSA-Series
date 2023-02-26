#include<bits/stdc++.h>
using namespace std;



int getMaxVal(int coins[], int idx,int tar,vector<vector<int>> &dp){
    if(idx == 0){
        if(coins[idx] == tar){
            return dp[idx][tar] = 1;
        }
        return dp[idx][tar] = 0;
    }

    if(dp[idx][tar] != -1){
        return dp[idx][tar];
    }

    int notTaken = getMaxVal(coins,idx-1,tar,dp);
    
    int taken = 0;

    if(coins[idx] <= tar){
        taken = 1 + getMaxVal(coins,idx-1,tar - coins[idx],dp);
    }
    return dp[idx][tar]  = max(taken, notTaken);

}

int knapsack(int coins[],int n,int tar){
    
    vector<vector<int>> dp(n+1,vector<int>(tar+1,-1));
    int ans = getMaxVal(coins,n-1,tar,dp);
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=tar;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;

}

int main(){
    int n = 4; 
    int coins[] ={9,6,5,1};
    int tar = 11;
    cout<<knapsack(coins,n,tar);
    return 0;

}