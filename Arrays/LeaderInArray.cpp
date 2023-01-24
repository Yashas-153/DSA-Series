#include<bits/stdc++.h>
using namespace std;
// start from the end and check if the number is greater than the previous highest and if it add it to the leaders list 
// and if not just move on
    
vector<int> LeaderInArrray(vector<int> arr){
    int n = arr.size();
    vector<int> lead;
    int highest =arr[n-1];
    lead.push_back(highest);
    for(int i = n-2;i>=0;i--){
        if(arr[i] > highest){
            highest = arr[i];
            lead.push_back(arr[i]);
        }
    }
    return lead;
}
int main(){
    vector<int> arr= {10, 22, 12, 3, 0, 6};
    vector<int> lead = LeaderInArrray(arr);
    for(auto x : lead){
        cout<<x<<" ";
    }
    return 0;
    
}