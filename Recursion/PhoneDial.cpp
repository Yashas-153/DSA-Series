#include<bits/stdc++.h>
using namespace std;

void combinationKeypad(vector<char> key[], vector<int> input, string out, int idx ){

    if(idx == input.size()){
        cout<<out<<" ";
        return;
    }

    int dig = input[idx];

    int len = key[dig].size();


    for(int i =0;i<len;i++){
        combinationKeypad(key,input,out + key[dig][i], idx + 1);
    }

}

int main(){
    vector<char> keypad[]
        = { {},
            {}, // 0 and 1 digit don't have any characters
                // associated
            { 'a', 'b', 'c' },
            { 'd', 'e', 'f' },
            { 'g', 'h', 'i' },
            { 'j', 'k', 'l' },
            { 'm', 'n', 'o' },
            { 'p', 'q', 'r', 's' },
            { 't', 'u', 'v' },
            { 'w', 'x', 'y', 'z' } };
    vector<int> input = {2,3,4};
    string output ="";
    combinationKeypad(keypad,input,output,0);
}