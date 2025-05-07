#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};
class Stack{
    public:
    Node* top;
    int ct;
    public:
    Stack()
    {
        top=NULL;
        ct=0;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
    void Push(int val)
    {
        Node* newNode= new Node(val);
        newNode->next=top;
        top=newNode;
        ct++;
    }
    void Pop()
    {
        if(isEmpty())
        {
            cout<<"nai kisu"<<endl;
            return;
        }
        top=top->next;
        ct--;
    }
    int Size()
    {
        return ct;
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        return top->data;
    }
};
int main()
{

    Stack st;
    if(st.isEmpty())cout<<"Khali"<<endl;
    cout<<st.peek()<<endl;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(300);
    cout<<st.Size()<<endl;
    cout<<st.peek()<<endl;
    st.Pop();
    st.Pop();
    cout<<st.Size()<<endl;
    cout<<st.peek()<<endl;
    return 0;
}