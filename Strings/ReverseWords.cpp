#include<bits/stdc++.h>
using namespace std;

void ReverseWords(string s){
    stack<string> st;
    string res = "";
    string token = "";
    for(int i =0;i<s.length();i++){
        if(s[i] == ' '){
            st.push(token);    
            cout<<"token is "<<token<<endl;
            token = "";
        }
        else if(i == s.length()-1){
            token += s[i];
            st.push(token);
            token = "";
        }
        else{
            token += s[i];
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void reverseWordOpt(string s){
    int n = s.length();
    int i = 0;
    string temp ="",ans = "";
    while(i < n){
        char ch = s[i];
        if(ch == ' '){
            if(ans != ""){
                ans = temp + " " + ans;
                }
            else
                ans = temp;
            temp = "";
        }
        else    
            temp += ch;
        i++;
    }
    if(temp != ""){
        if(ans != ""){
            ans = temp + " "+ ans;
        }
        else{
            ans = temp;
        }
    }
    cout<<ans<<endl;
}

int main(){
    string str= {"This course is really good"};
    reverseWordOpt(str);
    return 0;
}