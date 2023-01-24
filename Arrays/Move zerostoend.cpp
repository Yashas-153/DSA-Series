#include<bits/stdc++.h>
using namespace std;


void movezeros(vector<int> &arr){
    int i = -1,j;
    int n = arr.size();
    for(j = 0;j < n; j++){
        if(arr[j]!=0){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
int main(){
    vector<int> arr = {1,0,2,1,4,0,0,4,0,4,5,0};
    int n = arr.size();
    movezeros(arr);
    for(auto x: arr){
        cout<<x<<" ";
    }
    return 0;
}