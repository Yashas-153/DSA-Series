#include<bits/stdc++.h>
using namespace std;

void combination(int arr[], vector<vector<int>> &res, int n, int target, int i,vector<int> &ds){
    cout<<"index is"<<i<<endl;
    //base case
    if( i == n){
        if(target == 0){
            res.push_back(ds);
        }
        return;
    }
    
    ds.push_back(arr[i]);
    
    combination(arr,res,n,target - arr[i],i+1,ds);
    ds.pop_back();
    
    combination(arr,res, n, target,i+1,ds;)
    
    }

vector<vector<int>> combinationsum(int arr[],int n, int target){
    vector<vector<int>> res;
    vector<int> ds;
    combination(arr, res, n ,target, 0, ds);
    return res;

}
int main(){
    vector<int> arr ={ 2,3,6,7,1,5};
    int target = 6;
    int n  = arr.size();
    vector<vector<int>> res= combinationsum(arr, n,target); 
    for(auto x : res){
        for(int i = 0;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}