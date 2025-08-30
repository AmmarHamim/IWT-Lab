#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int val)
    {
        data=val;
        next=NULL;
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
        return ct==0;
    }

    void pushh(int val)
    {
        Node* newNode=new Node(val);
        newNode->next=top;
        top=newNode;
        ct++;

    }
    void popp()
    {
        if(isEmpty())
        {
            cout<<"mt"<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
        ct--;
    }
    int peek()
    {
        return top->data;
    }
    int sz()
    {
        return ct;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"mt"<<endl;
            return;
        }
        Node* temp=top;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main()
{
    fast_io;

    Stack st;
    if(st.isEmpty())cout<<"empty"<<endl;
    st.pushh(10);
    st.pushh(20);
    st.pushh(30);
    cout<<st.sz()<<endl;
    st.display();
    cout<<st.peek()<<endl;
    st.popp();
    st.display();
    cout<<st.peek()<<endl;
    return 0;
}