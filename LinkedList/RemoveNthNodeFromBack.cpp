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

void RemoveNth(node * head, int k){
    node* fir = head, sec= head;
    for(int i=1;i<k;i++){
        fir = fir->link;
    }
    node* prev = NULL;
    while(fir->link != NULL){
        fir = fir->link;
        prev = sec;
        sec = sec->link;
    }
    if(fir ->link == NULL){
        head = sec->link;
    }else{
        prev->link = sec-link;
    }
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
    RemoveNth(head,4);
    
    return 0;

}