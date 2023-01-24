#include<bits/stdc++.h>
using namespace std;

void toPostfix(string eq){
    stack<char> st;
    int n = eq.length();
    for(int i = 0 ; i < n;  i++){
        if((eq[i] >= 'a' and eq[i] <='z') or  (eq[i]>='A' and eq[i]<= 'Z'))
            cout<<eq[i]<<" ";
        else if(eq[i] == ')'){
            while(st.top()!= '('){
                cout<<st.top()<<" ";
                st.pop();
            }
            st.pop();
        } 
        else{
            st.push(eq[i]);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}


int main(){
    string equation = "(p+q)*(m-n)";
    toPostfix(equation);
    return 0;
}
