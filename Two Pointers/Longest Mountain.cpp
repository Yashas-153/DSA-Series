#include<bits/stdc++.h>
using namespace std;

int longestMountain(vector<int>& arr) {
    int n = arr.size();
    int i=0;
    int inc = 0;
    int dec = 0;
    int maxi = 0;
    while(i + 1 < n ){
        if(arr[i] < arr[i+1]){
            while(i+1<n and arr[i]<arr[i+1]){
                inc++;
                //cout<<"ele is "<<arr[i]<<" inc is "<<inc<<endl;
                i++;
            }
            while(i+1<n and arr[i] > arr[i+1]){
                dec++;
                //cout<<"ele is "<<arr[i]<<" dec is "<<inc<<endl;
                i++;
            }
            if(dec != 0 and inc != 0){
                maxi = max(inc+dec +1,maxi);
            }
            //cout<<"maxi is "<<maxi<<endl;
            inc = 0;
            dec = 0;
            //i++;
        }
        else{
            i++;
        }
    }
    if(maxi < 3)
        maxi = 0;
    return maxi;    
}

int main(){
    vector<int> arr = {8,9,2,4,5,6,7,6,1,0,3,2};
    int ans = longestMountain(arr);
    cout<<ans<<endl;
    return 0;
}