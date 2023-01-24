#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
} 

bool countFreq(vector<int> arr){
    unordered_map<int,int> mp;
    for(auto x : arr){
        mp[x]++;
    }

    vector<pair<int,int>> p;
    for(auto it : mp){
        p.push_back(make_pair(it.first,it.second));
    }
    
    sort(p.begin(),p.end(),cmp);
    for(auto x : p){
        for(int i = 0;i<x.second;i++){
            cout<<x.first<<" ";
        }    
    }

}

int main(){
    vector<int> arr ={5,5,5,4,6,4,3,3,2,1,5,5};
    countFreq(arr);
    
}