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

void topview(node* root){
    queue<pair<root,int>> q;
    map<int,int> mp;
    q.add({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        node * temp = it.first;
        int line = it.second;
        if(mp.find(line)==mp.end()){
            mp[line] = temp->data;
        }
        if(temp->left != NULL){
            q.push(make_pair(temp->left,line-1));
        }
        if(temp->right!= NULL){
            q.push(make_pair(temp->right,line+1))
        }
    }
}
int main(){

    root = new node(1);
    root->left = new node(2);
    root->right =new node(3);
    root ->left->left = new node(4);
    root ->left ->right = new node(5);
    root -> right -> right = new node(6);
    root->right ->left = new node(7);
    root-> right-> right-> right = new node(8);
    topview(root);
    return 0;
}