#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(int arr[]){
    vector<int> res(n,-1);
    stack<int> st;
    st.push(arr[n-1]);
    for(int i = 2*n - 2;i >= 0; i--){
        if(arr[i] < st.top()){
            while(!st.empty() and st.top() < arr[i]){
                st.pop();
            }
            res[i % n] = st.top();
        }
        else{
            res[i] = st.top();
            st.push(arr[i]);
        }
    }

}

int main(){
    int arr[] = {3,10,4,2,1,2,6,1,7,2,9};
    vector<int> res = nextGreater(arr);
    for(auto x : res){
        cout<<x<<" ";
    }
    
    return 0;
}
