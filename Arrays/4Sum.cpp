#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> FourSum(vector<int> arr, int target){
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int sum = 0;
    int i,j,l,r;
    for(i =0;i<n-3;i++){
        for(j=i+1;j<n-2;j++){
            cout<<"i is "<<i<<endl;
            cout<<"j is "<<j<<endl;
            l = j+1;
            r = n-1;
            sum = target - arr[i] + arr[j];
            while( l<r){
                cout<<" left : "<<l<<" right : "<<r<<endl;
                if(arr[l] + arr[r] == sum){
                    cout<<"execued"<<endl;
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
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
            while(j + 1 < n && arr[j + 1] == arr[j]) ++j;
        }
        while(i + 1 < n && arr[i + 1] == arr[i]) ++i;
    }
    return res;
}
int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    //sorted arr {-4,-1,-1,0,1,1,2}
    int target = 0;
    vector<vector<int>> res = FourSum(arr,target);
    for(auto x : res){
        cout<<x[0] <<" "<<x[1] <<" "<<x[2]<<" "<<x[3]<<endl;
    }
    return 0;
}