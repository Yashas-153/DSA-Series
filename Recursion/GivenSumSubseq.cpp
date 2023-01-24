#include<bits/stdc++.h>
using namespace std;

void givensum(int arr[], int n, int req ,vector<int> &ds, int sum, int i){
    if(i == n){
        if(sum == req){
            for(auto x : ds){
             cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //cout<<"index is "<<i<<endl;
    ds.push_back(arr[i]);
    sum += arr[i];
    givensum(arr,n,req,ds,sum,i+1);
    sum -= arr[i];
    ds.pop_back();
    givensum(arr,n,req,ds,sum,i+1);  
}

bool givenSum(int arr[], int n, int req ,vector<int> &ds, int sum, int i){
    if(i == n){
        if(sum == req){
            for(auto x :ds ){
                cout<<x<<" ";
            }
            cout<<endl;
        return true;
        }
        return false;
    }

    ds.push_back(arr[i]);
    sum += arr[i];
    if(givenSum(arr,n,req,ds,sum,i+1)== true)
        return true;
    sum -= arr[i];
    ds.pop_back();
    if(givenSum(arr,n,req,ds,sum,i+1)==true)
        return true;
    return false;

}

int GivenSum(int arr[], int n, int req , int sum, int i){
    if(i == n){
        if(sum == req){
            return 1;
        }
        return 0;
    }
    sum += arr[i];
    int left = GivenSum(arr,n,req,sum,i+1);
    sum -= arr[i];
    int right = GivenSum(arr,n,req,sum,i+1);  

    return left + right;
}


int main(){
    int arr[] = {1,2,1};
    int sum = 2;
    int n = 3;
    vector<int> res;
    cout<<"Ex1"<<endl;
    givensum(arr,n,sum,res,0,0);
    cout<<"Ex2"<<endl;
    givenSum(arr,n,sum,res,0,0);
    cout<<"ex3"<<endl;
    int ans = GivenSum(arr,n,sum,0,0); 
    cout<<ans;
    return 0;
}