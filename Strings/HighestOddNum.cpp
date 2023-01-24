#include<bits/stdc++.h>
using namespace std;
void highestOddNumber(string num){
    int n = num.length();
    int odd_idx = -1;
    int i =0;
    int start  = -1;
    if(n==1){
        if((num[0] - '0') % 2 != 0){
            cout<<num[0];
            return;
        }
    }
    while(i < n){
        int dig = num[i] - '0';
        if(dig%2 != 0){
            odd_idx = i;
        }
        i++;
    }
    if(odd_idx != -1){
        for(int i=0;i<=odd_idx;i++){
            cout<<num[i];
        }
        cout<<endl;
    }
}


int main(){
    string num = "504";
    highestOddNumber(num);
    return 0;
}