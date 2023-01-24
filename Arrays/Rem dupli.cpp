#include<bits/stdc++.h>
using namespace std;

vector<int> remove_dupl(vector<int> arr,int n){
    int i=0;
    for(int j = 0;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return arr;
}


int main(){
    int n = 12;
    vector<int> arr ={1,1,2,2,2,3,3,4,5,6,6,6};
    arr = remove_dupl(arr,n);
    for(auto x: arr){
        cout<<x<<" ";
    }
    return 0;
}   
