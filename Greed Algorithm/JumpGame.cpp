#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int reachable = 0;
    for(int i =0;i<nums.size();i++){
        if(reachable < i){
            return 0;
        }    
        else{
            reachable = max(reachable, i + nums[i] );
        }
        
    }
    return 1;
    
}

int main(){
    vector<int> nums  = {3,2,1,0,4};
    cout<<canJump(nums)<<endl;
    return 0;
}