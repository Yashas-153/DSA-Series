#include<bits/stdc++.h>
using namespace std;

typedef pair<double,pair<double,double>> tri;

bool comp(tri a, tri b ){
    return a.first > b.first;
}


double findMaxWeight(int wt[], int val[], int n, int W){

    vector<pair<double,pair<double,double>>> vec;
    for(int i =0;i<n;i++){
        int ratio = double(val[i]/wt[i]); 
        vec.push_back({ratio,{val[i],wt[i]}}); 
    }
    sort(vec.begin(),vec.end(),comp);
    int curwt = 0;
    double cur_val =  0; 
    for(int i =0;i<n;i++){
        if(curwt + vec[i].second.second <= W){
            cur_val += vec[i].second.first;
            curwt += vec[i].second.second;
        }
        else{
            cur_val += vec[i].first * (W - curwt);
            break;
        }
    }
    return cur_val;

}

int main(){
    int n = 2;
    int wt[] ={10,20};
    int val[] = {60,100};
    int w = 50;
    cout<<findMaxWeight(wt,val,n,w)<<endl; 
    return 0;
}