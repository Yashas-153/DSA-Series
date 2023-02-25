#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

bool f(vi arr, int idx, int target,vii &dp){
    if(target == 0){
        return dp[idx][target] = true;
    }
    if(idx == 0){
        return dp[idx][target] = arr[0] ==  target;
    }
    if(dp[idx][target] != -1){
        return dp[idx][target];
    }

    bool notTaken = f(arr,idx-1, target,dp);
    bool taken = false;
    if(arr[idx] <= target){
        taken = f(arr,idx-1,target - arr[idx],dp);
    }

    return dp[idx][target]  = taken or notTaken;
}

int minDiff(vi arr){
    int n = arr.size();
    int sum = 0;
    for(int i =0 ;i<arr.size();i++){
        sum += arr[i];
    }
    
    vii dp(n+1,vi(sum+1,-1));
    for(int i =0;i<=sum;i++){
        bool dummy = f(arr,n-1,i,dp);
    }

    int mini = 1e9;
    for(int i = 0;i<=sum ; i++){
        if(dp[n-1][i]){
        int diff =abs(i -(sum - i));
        mini = min(diff,mini);
        }
    }
    /*for(int i =0;i<=n;i++){
        for(int j= 0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return mini;

}


int main(){
    vector<int> arr ={8,6,5};
    cout<<minDiff(arr); 
    return 0;
}