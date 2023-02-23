#include<bits/stdc++.h>
using namespace std;

int getsum(int arr[], vector<int> &dp, int idx){
    if(idx < 0){
        return 0;
    }
    
    if(dp[idx]!= -1){
        return dp[idx];
    }

    int s1 = arr[idx] + getsum(arr,dp,idx-2);
    int s2 = getsum(arr, dp, idx -1);

    return dp[idx] = max(s1,s2);
}

int  findSum(int arr[], int n ){
    vector<int> dp(n+1,-1);
    int ans = getsum(arr,dp,n-1);
    return ans;

}

int main(){
    int arr[] = {1,2,3,1,3,5,8,1,9};
    cout<<findSum(arr,9);
}