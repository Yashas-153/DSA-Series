#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ThreeSum(vector<int> arr, int target){
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int sum = 0;
    int i,l,r;
    for(i =0;i<n-2;i++){
        cout<<"i is "<<i<<endl;
        if(i==0 or (i>0  and arr[i] != arr[i-1])){
            l = i+1;
            r =n-1;
            while( l<r){
                cout<<" left : "<<l<<" right : "<<r<<endl;
                if(arr[i] + arr[l] + arr[r] == target){
                    cout<<"execued"<<endl;
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[l]);
                    temp.push_back(arr[r]);
                    res.push_back(temp);
                    while(l < r and arr[l] == arr[l+1]) l++;
                    while(l < r and arr[r]== arr[r-1]) r--;
                    l++;
                    r--;
                }
                else if(target - arr[i] > arr[l] + arr[r]){
                    l++;
                }
                else 
                    r--;   
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {-1,1,1,2,0,-4 ,-1};
    //sorted arr {-4,-1,-1,0,1,1,2}
    int target = 0;
    vector<vector<int>> res = ThreeSum(arr,target);
    for(auto x : res){
        cout<<x[0] <<" "<<x[1] <<" "<<x[2]<<endl;
    }
    return 0;
}