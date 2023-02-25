#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

int f(vi arr, int idx, int target,vii &dp){
    if(target == 0){
        return dp[idx][target] = 1;
    }
    if(idx == 0){
        if(arr[0] ==  target){
            return dp[idx][target] =1;
        }
        return dp[idx][target] = 0;
    }

    if(dp[idx][target] != -1){
        return dp[idx][target];
    }

    int notTaken = f(arr,idx-1, target,dp);
    int taken = 0;
    if(arr[idx] <= target){
        taken = f(arr,idx-1,target - arr[idx],dp);
    }

    return dp[idx][target]  = taken + notTaken;
}

int minDiff(vi arr,int target){
    int n = arr.size();
    
    vii dp(n+1,vi(target + 1,-1));
    int ans = f(arr,n-1,target,dp);
    return ans;

}


int main(){
    vector<int> arr ={1,2,2,3};
    int tar = 3;
    cout<<minDiff(arr,tar); 
    return 0;
}