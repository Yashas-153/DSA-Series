#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* link;

    node(int val){
        data = val;
        link = NULL;
    }
};
void display(node* head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp= temp-> link;
    }
    cout<<" NULL"<<
    endl;
} 
void insertAthead(node* &head, int val){
    node *n;
    n = new node(val);
    n->link = head;
    head = n;

}

class Stack{
    public:
    int size;
    node* head;
    
    Stack(){
        head = NULL;
    }

    void push(int value){
        if(head == NULL){
            node* n;
            n = new node(value);
            return;
        }
        node* n  = new node(value);
        n->link = head;
        head = n;
    }

    int pop(){
        node* temp = head;
        head = head->link;
        return temp->data;
    }

    int Size(){
        node *temp;
        int n=0;
        while(temp != NULL){
            temp = temp->link;
            n++;
        }
        return n;
    }
};




int main(){
    node* head = NULL;
    insertAthead(head,17);
    insertAthead(head,15);
    insertAthead(head,8);
    insertAthead(head,9);
    insertAthead(head,2);
    display(head);
    return 0;

}