#include<bits/stdc++.h>
using namespace std;

string solve(string s){
    int n = s.length();
    int i = 0;
    int j = 0;
    vector<int> arr(26,0);
    while(i < n){
        if((s[i] >= 'a' and s[i] <='z') or(s[i] >='A' and s[i] <= 'Z')){
            char ch = (char)tolower(s[i]);
            cout<<"if"<<endl;
            j = i+1;
            string str = "";
            while(j<n and (s[j] >= '0' and s[j] <='9')){
                str += s[j];
                j++;
            }
            
            //cout<<"string is"<<str<<endl;
            int num = stoi(str);
            arr[s[i] - 'a'] += num;
            cout<<"number is "<<num<<" and index is "<<s[i] - 'a'<<endl;;
            i = j;
            
            //cout<<"i is "<<i<<endl;
        }
    }
    string res = "";
    for(int i = 0;i<26;i++){
        if(arr[i] != 0){
            cout<<"char is "<<char(int('a')+ i)<<endl;
            res += char(int('a') + i);
            res += to_string(arr[i]);
        }
    }
    return res;
    
    
}
int main(){
    string s = "21";
    string ans = solve(s);
    cout<<ans<<endl;
    return 0;
}