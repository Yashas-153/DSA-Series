#include<bits/stdc++.h>
using namespace std;

void subsetsum(vector<int> arr, int n, int i,int sum){
    //base case
    if( i == n){
        cout<<sum<<" ";
        return;
    }
    //ds.push_back(arr[i]);
    
    subsetsum(arr, n, i+1,sum);
    //ds.pop_back();
    subsetsum(arr,n,i+1,sum + arr[i]);
    
    }


int main(){
    vector<int> arr ={ 5,2,1};
    int n  = arr.size();
    subsetsum(arr,n,0,0);
    return 0;
};  