#include<bits/stdc++.h>
using namespace std;


int lengthOfLastWord(string s) {
    int n = s.length();
    int cnt = 0;
    int i = n-1;
    while(i > 0){
        cout<<"i is "<<i<<endl;
        if(s[i] == ' ' and cnt == 0){
            i--;
            cout<<""
        }
        else if(s[i] != ' ' and cnt == 0){
            cnt++;
            i--;
            cout<<"else if "<<endl;
        } 
        else if(s[i] ==  ' ' and cnt != 0){
            i--;
            break;
            cout<<"break"<<endl;
        }
        else{
            i--;
        }
    }
    return cnt;
}

int main(){
    string s  = "Hello World";
    int ans = lengthOfLastWord(s);
    cout<<ans<<endl;
    return 0;
}