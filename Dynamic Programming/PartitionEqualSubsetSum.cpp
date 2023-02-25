#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

bool f(vi arr, int idx, int target,vii &dp){
    if(target == 0){
        return true;
    }
    if(idx == 0){
        return target == 0;
    }
    if(dp[target][idx] != -1){
        return dp[target][idx];
    }

    bool notTaken = f(arr,idx-1, target,dp);
    bool taken = false;
    if(arr[idx] <= target){
        taken = f(arr,idx-1,target - arr[idx],dp);
    }

    return dp[target][idx]  = taken or notTaken;
}

bool isdivideable(vi arr){
    int n = arr.size();
    int sum = 0;
    for(int i =0 ;i<arr.size();i++){
        sum += arr[i];
    }
    bool ans = false;
    
    if(sum %2 == 0){
        vii dp(sum/2 + 1,vi(n+1,-1));
        ans = f(arr,n-1,sum/2,dp);
    }
    return ans;

}


int main(){
    vector<int> arr ={2,3,3,3,4,5};
    cout<<isdivideable(arr); 
    return 0;
}