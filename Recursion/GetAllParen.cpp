#include<bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans,int n, int open, int close, string op ){
    if(open == 0 && close ==0){
        ans.push_back(op);
        cout<<op<<endl;
        return;
    }
    if(open > 0){
        cout<<"open executed"<<endl;
        op += "(";
        solve(ans,n,open-1, close, op);
    }
    if(close > open){
        cout<<"close exectured"<<endl;
        op += ")";
        solve(ans,n,open, close-1, op);
    }
}

vector<string> getAllParen(int n){
    vector<string> v;
    int open = n, close = n;
    string s = "";
    solve(v,n,open,close,s);
    return v; 
} 

int main(){
    int n = 3;
    vector<string> v = getAllParen(n);
    for(auto x : v){
        cout<<x<<endl;
    }
}