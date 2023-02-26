#include<bits/stdc++.h>
using namespace std;



int getMaxVal(int wt[], int val[], int idx,int W,vector<vector<int>> &dp){
    if(idx == 0){
        if(wt[idx] <= W){
            return dp[idx][W] = val[idx];
        }
        return dp[idx][W] = 0;
    }

    if(dp[idx][W] != -1){
        return dp[idx][W];
    }

    int notTaken = getMaxVal(wt,val,idx-1,W,dp);
    
    int taken = 0;

    if(wt[idx] <= W){
        taken = val[idx] +  getMaxVal(wt,val,idx-1,W - wt[idx],dp);
    }
    return dp[idx][W]  = max(taken, notTaken);

}

int knapsack(int wt[],int val[],int n,int W){
    
    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
    int ans = getMaxVal(wt,val,n-1,W,dp);
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;

}

int main(){
    int n = 4; 
    int val[] = {5,4,8,6};
    int wt[] = {1,2,3,4};
    int W =  5;
    cout<<knapsack(wt,val,n,W);
    return 0;

}