#include<bits/stdc++.h>
using namespace std;
unordered_map<char, int> roman;


int main(){
    string s = "CCCXCXLVI";
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    int num = 0;
    for(int i=0;i<s.length();i++){
        if(roman[s[i]] <roman[s[i+1]]){
            num += roman[s[i+1]] - roman[s[i]];
            i++;
        }
        else{
            num += roman[s[i]];
        }
    }
    cout<<num<<endl;

} 

