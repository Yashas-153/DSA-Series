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

void PathToANode(node* root, int node, vector<int> &arr, int level){
    if(root == NULL){
        return;
    }
    if(root->data == node){
        arr.push_back(root->data);
        for(auto x:arr){
            cout<<x<<"-";
        }
        return;    
    }
    if(arr.size() >  level){
        arr.pop_back();
    }
    arr.push_back(root->data);
    PathToANode(root->left, node, arr, level +1);
    PathToANode(root->right,node,arr,level+1);

}


int main(){
    node * root;
    root = new node(1);
    root->left = new node(2);
    root->right =new node(3);
    root ->left->left = new node(4);
    root ->left ->right = new node(5);
    root -> right -> right = new node(6);
    root->right ->left = new node(7);
    root-> right-> right-> right = new node(8);
    vector<int> arr;
    PathToANode(root, 8,arr, 0);
    return 0;
}