#include<bits/stdc++.h>
using namespace std;

// put all the array elements in hashset and for each element find its previous element in the hashset
// and count the number of consecutive finds
int consecutive(vector<int> arr){
    int n = arr.size();
    unordered_set<int> s;
    for(auto x: arr){
        s.insert(x);
    } 
    int max_s = 0;
    int streak = 1;
    for(auto ele : s){
        while(s.find(ele - 1) != s.end()){
            ele = ele - 1;
            streak++;
        }
        max_s = max(max_s,streak);
        streak =1; 
    }
    return max_s;
}

int main(){
    vector<int> arr= {100,200,1,2,3,4};
    int res = consecutive(arr);
    cout<<res<<endl;
    return 0;
    
    
}