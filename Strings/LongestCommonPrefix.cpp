#include<bits/stdc++.h>
using namespace std;
 
string lcp(vector<string> str){
    int minn = INT_MAX;
    int idx = -1;
    for(int i =0;i<str.size();i++){
        if(minn > str[i].length()){
            minn = str[i].length();
            idx = i;
        }
    }
    int count = 0;
    int min_count = INT_MAX;
    string min_str = str[idx];
    for(int j= 0;j<str.size();j++){
        int i = 0;
        while(i < minn and str[j][i] == min_str[i]){
            count++;
            i++;
        }
        min_count = min(count,min_count);
        count = 0;
    }
    cout<<min_count<<endl;
    string res = min_str.substr(0,min_count);
    return res;
}
int main(){
    vector<string> str = {"geeksforgeeks", "geeks", "geek","geezer"};
    string res = lcp(str); 
    cout<<res<<endl;
    return 0;
}   