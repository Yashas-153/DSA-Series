#include<bits/stdc++.h>
using namespace std;
//Theorem behind algo 
//Prefix sum basically
//Now let’s say we know that the sum of subarray(i, j) = S, and we also know that sum of subarray(i, x) = S where i < x < j.
// We can conclude that the sum of subarray(x+1, j) = 0.
int SubArrayZero(vector<int> arr){
    int n = arr.size();
    int summ = 0;
    int maxx =0;
    unordered_map<int, int> hm;
    for(int i=0;i<n;i++){
        summ += arr[i];
        if (summ = 0){
            maxx = i+1;
        }
        else{
            if(hm.find(summ) == hm.end()){
                hm[summ] = i;
            }
            else{
                maxx = max(i-hm[summ]+1, maxx );
            }
        }
    }
    return maxx;

}
int main(){
    vector<int> arr = {1, 2, -2, 4, -4};
    int res = SubArrayZero(arr);
    cout<<res<<endl;
    return 0;
}