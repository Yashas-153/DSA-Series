#include <bits/stdc++.h>
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

void zigzagTraversal(node * root){
    bool reverse= true;
    queue<node> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front(<<" ");
        node * temp = q.front();
        q.pop();
        if(!reverse){
            vector<node> v;
            if(temp->left!= NULL){
                s.push(temp->left);
            }
            if(temp->right != NULL){
                s.push(temp->right);
            }   
        }
        if(temp->left!= NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
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
    root->right->right->right-> = new node(7);

    return 0;
}