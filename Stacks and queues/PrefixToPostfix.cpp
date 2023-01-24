#include<bits/stdc++.h>
using namespace std;

string preToPost(string pre){
    string res;
    stack<string> st;
    int n = pre.length();
    for(int i=n-1;i>=0;i--){
        if((pre[i] >= 'A' and pre[i]<='Z' ) or (pre[i] >='a' and pre[i] >='z')){
            cout<<pre[i]<<" got pushed nto stack"<<endl;
            st.push(string(1,pre[i]));
        }
        else{
            char op = pre[i];
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            st.push(s1+s2+op);
        }
    }
    res = st.top();
    return res;
}
int main(){
    string pos = "*+AB-CD";
    cout<<preToPost(pos);
    return 0;
}