#include<bits/stdc++.h>
using namespace std;

void combination(vector<vector<int>> &res , vector<int> &ds, int sum , int k, int i){
    //cout<<"index is"<<i<<endl;
    //base case
    if( i>10){
        return;
    }
    if(k==0 ){
        if(sum == 0){
            res.push_back(ds);
        }
        return;
    }
    if(i > sum){
        return;
    }

    ds.push_back(i);
    
    combination(res, ds, sum - i,k-1,i+1);
    ds.pop_back();

    combination(res, ds, sum ,k,i+1);
    
    }

vector<vector<int>> combinationsum(int sum, int k){
    vector<vector<int>> res;
    vector<int> ds;
    combination(res,ds,sum, k,1);
    return res;

}
int main(){
    int sum,k;
    sum = 45;
    k = 9;
    vector<vector<int>> res= combinationsum(sum,k); 
    for(auto x : res){
        for(int i = 0;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}