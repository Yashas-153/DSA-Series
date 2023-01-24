#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    queue<int> q1;
    int top;
    Stack(){
        top = -1;
    }
    void push(int value){
        int s = q1.size();
        q1.push(value);
        for(int i =0;i<s;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int ele = q1.front();
        q1.pop();
        return  ele;
    }

    int Size(){
        return q1.size();
    }

    int Top(){
        return q1.front();
    }
};


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(4);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    cout<<s.Size()<<endl;
    return 0;
}