#include<bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums){
int currEnd = 0,farthest = 0;
    int ns = 0;
    int n = nums.size();
    for(int i = 0;i<nums.size()-1;i++){
        farthest = max(farthest,i + nums[i]);
        if(currEnd == i){
            ns++;
            currEnd = farthest;
        }
    }
    return ns;
}

int main(){
    vector<int> nums  = {2,3,1,1,4};
    cout<<jump(nums)<<endl;
    return 0;
}