#include<bits/stdc++.h>
using namespace std;

void genAllSub(char s[],int len, int n){
    if(len == n){
        cout<<s<<' ';
        return;
    }
    if(s[len -1 ] == '0'){
        s[len] = '1';
        genAllSub(s,len+1,n);
        s[len] ='0'; 
        genAllSub(s,len+1,n);
    }
    if(s[len - 1] == '1'){
        s[len] = '0';
        genAllSub(s,len+1,n); 
    }

}

void generate(int n){
    char s[n];
    s[0] = '0';
    genAllSub(s,1,n);

    s[0] = '1';
    genAllSub(s,1,n);
    
}

int main(){
    int n = 3;
    generate(n);
    return 0;
}