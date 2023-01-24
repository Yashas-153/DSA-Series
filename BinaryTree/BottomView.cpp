#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

//         1
//      2      3
//   4    5  7   6   
//                 8


0,1
1,3
2,6
3,8

vector<int> topview(node* root){
    vector<int> ans;
    queue<pair<node *,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        node * temp = it.first;
        int line = it.second;
        if(mp.find(line)==mp.end()){
            mp[line] = temp->data;
        }
        else{
            mp[line] = temp->data;
        }
        if(temp->left != NULL){
            q.push(make_pair(temp->left,line-1));
        }
        if(temp->right!= NULL){
            q.push(make_pair(temp->right,line+1));
        }
    }
    for(auto it : mp) {
        ans.push_back(it.second); 
    }
    return ans;
}
int main(){
    node* root;
    root = new node(1);
    root->left = new node(2);
    root->right =new node(3);
    root ->left->left = new node(4);
    root ->left ->right = new node(5);
    root -> right -> right = new node(6);
    root->right ->left = new node(7);
    root-> right-> right-> right = new node(8);
    vector<int> ans = topview(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}