#include<bits/stdc++.h>
using namespace std;

class Stack{
    public :
    int top;
    int size;
    int *arr;

    Stack(){
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    void push(int ele){
        top++;
        arr[top] = ele;
    }

    int pop(){
        int ele = arr[top];
        top--;
        return ele;
    }

    int top(){
        return arr[top];
    }

    int size(){
        return top + 1;
    }

};





int main(){
    Stack s;
    s.push(5);
    s.push(6);
    cout<<s.top()<<endl;
    cout<<s.pop();
    cout<<s.top();
    return 0;

}