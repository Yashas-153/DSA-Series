    #include<bits/stdc++.h>
    using namespace std;

    int countNumSub(string s, int k){
        int i=0;
        int count =0;
        vector<string> substrngs;
        while(i<s.length() -k){
            unordered_set<char> set;
            count = 0;
            int j = i;
            while(count <= k){
                if(set.find(s[j]) == set.end()){
                    count++;
                    set.insert(s[j]);
                }
                j++;
            }
            substrngs.push_back(s.substr(i,j));
            cout<<s.substr(i,j);
            i++;
        }
        return substrngs.size();
    }
    int main(){
        string s = "abc";
        int res = countNumSub(s,2);
        cout<<res<<endl;
    }