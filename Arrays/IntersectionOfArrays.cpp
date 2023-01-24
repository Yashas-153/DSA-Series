#include<bits/stdc++.h>
using namespace std;

vector<int> IntersectionOf2Arrays(vector<int> arr1, vector<int> arr2, int m, int n){
    int i=0,j=0;
    vector<int> res;
    while(i<m and j<n){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            res.push_back(arr1[i]);
            i++;
            j++;
        }
    }
}
int main(){
    vector<int> arr1 = {1,2,3,4,6,8,10};
    vector<int> arr2 = {2,5,6,9,10,15};
    int m = arr1.size();
    int n = arr2.size();
    vector<int> res = IntersectionOf2Arrays(arr1,arr2,m,n);
    for(auto x: res){
        cout<<x<<" ";
    }
    return 0;
}