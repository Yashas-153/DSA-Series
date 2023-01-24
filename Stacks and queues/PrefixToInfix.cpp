#include<bits/stdc++.h>
using namespace std;

void toInfix(string eq){
    int i = 0;
    stack<char> st;
    int n = eq.length();
    while(i<n) {
        if((eq[i] >= 'a' and eq[i] <='z') or  (eq[i]>='A' and eq[i]<= 'Z')){
            cout<<eq[i]<<" ";
            if(st.top() == '+' or st.top() == '-' or st.top() == '/' or st.top() == '*'){
                cout<<st.top()<<" ";
                st.pop();
            }
            else if(st.top() == '('){
                while(st.size() > 0 and st.top()== '('){
                    //cout<<"size of stack is"<<st.size()<<endl;
                    cout<< ")" <<" ";
                    st.pop();
                }
                if(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
            }
        }
        else{
            //cout<<"added "<<eq[i]<<endl;
            st.push('(');
            st.push(eq[i]);
            cout<<"("<<" ";
        }
        i++;
    }
}

int main(){
    string eq = "*-A/BC-/AKL";
    toInfix(eq);
    return 0;

}