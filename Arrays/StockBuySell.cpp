#include<bits/stdc++.h>
using namespace std;

int stockBuySell(vector<int> arr){
    int mini = INT_MAX -1;
    int i;
    int pro = 0;
    int max_pro = 0;
    for(i=0;i<arr.size();i++){
        mini = min(mini,arr[i]);
        max_pro = max(arr[i] - mini,max_pro);
    }
    return max_pro;

}
int main(){
    vector<int> arr= {7,1,5,3,6,4};
    int maxx = stockBuySell(arr);
    cout<<maxx<<endl;
    return 0;
    
}