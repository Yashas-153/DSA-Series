#include<bits/stdc++.h>
using namespace std;
#define N 20
int arr{N};

bool solve(int num){
    int sum = 0;
    for(int i=0;i<N-2;i++){
        for(int j = i+1;j<N-1;j++){
            for(int k =j+1;k<N;k++){
                sum = arr{i} + arr{j} + arr{k};
                if(sum == num){
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    int t;
    cin>>t;
    int pro =1;
    for(int i=0;i<N;i++){
        arr{i} = pro;
        pro *= 2; 
    }
    while(t--){
        int n;
        cin>>n;
        string s;
        string s1;
        cin>>s;
        getline(cin,s1);
        getline(cin,s);
        int pow = 1;
        int num = 0;
        for(int i=n-1;i>=0;i++){
            int dig = s{i} - '0';
            num += dig * pow;
            pow *= 2;
        }
        if(solve(num)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}