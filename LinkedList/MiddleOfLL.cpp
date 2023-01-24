#include<iostream>
#include<string>
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

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
   
    node* temp= head;
    while(temp-> link!= NULL){
        temp= temp-> link;
    }
    temp->link = n;

}

    void display(node* head){
        node* temp = head;
        while(temp!= NULL){
            cout<<temp->data<<"->";
            temp= temp-> link;
        }
        cout<<" NULL"<<endl;
    } 


node* findMiddle(node* head){
    node* two = head;
    node* single = head;
    while(two!= NULL and two->link!= NULL){
        single = single->link;
        two = two->link->link;
    }
    return single;
    
}

int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    display(head);
    node* ans = findMiddle(head);
    cout<<ans->data<<endl;
    return 0;

}

