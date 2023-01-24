#include<bits/stdc++.h>
using namespace std;


bool ispalin(string s){
    int n = s.length();
    int c = 0;
    for(int i=0;i<n;i++){
        if(s[i]== s[n-i-1]){
            c++;
        }
        else{
            break;
        }
    }
    if( c == n){
        //cout<<"string "<<s<<" is "<<"palindrome"<<endl;
        return true;
    }
    return false;
}
int MaxPalin(string str){
    int res = 0;
    int n= str.length();
    int maxx = INT_MIN;
    for(int i =0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int len = 0;
            string sub_str = str.substr(i,j);
            if(ispalin(sub_str)){
                len = j -i +1;
            }
            maxx = max(len,maxx);
        }
    }
    return res = maxx;;
}
int main(){
    string s = "acddaabaa";
    int res = MaxPalin(s);
    cout<<res<<endl;
    return 0;
}