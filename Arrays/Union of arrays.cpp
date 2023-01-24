#include<bits/stdc++.h>
using namespace std;


vector<int> UnionOfTwoArrays(vector<int> arr1, vector<int> arr2,int m,int n){
    vector<int> res;
    int i = 0,j=0;
    while(i<m and j<n){
        if(arr1[i] == arr2[j]){
            res.push_back(arr1[i]);
            i++;
            j++;    
        }
        else if(arr1    [i] < arr2[j]){
            res.push_back(arr1[i]);
            i++;
        }
        else{
            res.push_back(arr2[j]);
            j++;
        }
    } 
    while(i<m){
        if(res.back()!= arr1[i]){
            res.push_back(arr1[i]);
        }
        i++;
    }  
    while(j<n){
        if(res.back()!= arr2[j]){
            res.push_back(arr2[j]);
        }
        j++;
    }
    return res;
}
int main(){
    vector<int> arr1 = {1,2,3,4,6,8,10};
    vector<int> arr2 = {2,3,4,5,6,7,8,9,10,11,11};
    int m = arr1.size();
    int n = arr2.size();
    vector<int> res = UnionOfTwoArrays(arr1,arr2,m,n);
    for(auto x: res){
        cout<<x<<" ";
    }
    return 0;
}