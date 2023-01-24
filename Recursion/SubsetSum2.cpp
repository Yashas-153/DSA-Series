#include<bits/stdc++.h>
using namespace std;

void findSum(vector<int> arr, vector<vector<int>> &ds, vector<int> &ans, int idx){
    ds.push_back(ans);
    for(int i = idx; i < arr.size();i++){
        if(i != idx && arr[i] == arr[i-1]){
            continue;
        }
        ans.push_back(arr[i]);
        findSum(arr,ds,ans,i+1);
        ans.pop_back();
    }
}

vector<vector<int>> subsetsum(vector<int> arr){
    vector<vector<int>> ds;
    vector<int> ans;
    sort(arr.begin(),arr.end());
    findSum(arr,ds,ans,0);
    return ds;
}

int main(){
    vector<int> arr ={ 1,2,2,2,3,3,5};
    int n  = arr.size();
    vector<vector<int>> ans = subsetsum(arr);
    for(auto x:ans){
        for(int i =0;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
};  