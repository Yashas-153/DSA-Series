#include<bits/stdc++.h>
using namespace std;

void getAllSubseq(vector<char> finl,string s, int n, int i){
    if(i==n-1){
        for(auto x:finl)
            cout<<x;
        cout<<endl;
        return;
    }
    finl.push_back(s[i]);
    getAllSubseq(s,finl,n,i+1);
    finl.pop_back(s[i]);
    getAllSubseq(s,finl,n,i+1); 

}

int main(){
    int n = 3;
    string s = "abc";
    vector<char> finl;
    getAllSubseq(finl,s,n,0 )
}