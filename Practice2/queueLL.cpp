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
        next=NULL;
    }
};
class Queue{
    public:
    Node* f;
    Node* r;
    int ct;
    public:
    Queue()
    {
        f=r=NULL;
        ct=0;
    }
    bool isEmpty(){
        return ct==0;
    }
    void enq(int val)
    {
        Node* newNode=new Node(val);
        if(isEmpty())
        {
            f=r=newNode;
        }
        else
        {
            r->next=newNode;
            r=newNode;
        }
        ct++;

    }

    void deq()
    {
        if(isEmpty())
        {
            cout<<"naii"<<endl;
            return;
        }
        Node* temp=f;
        f=f->next;
        delete temp;
        ct--;
    }
    int sz()
    {
        return ct;
    }

    int peekfront()
    {
        return f->data;
    }
    int peekrear()
    {
        return r->data;
    }
    void display()
    {
        Node* temp=f;
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

    Queue q;
    if(q.isEmpty())cout<<"khali"<<endl;
    q.enq(10);
    q.enq(20);
    q.enq(30);
    q.enq(40);
    q.enq(50);
    cout<<q.sz()<<endl;
    q.display();
    q.deq();
    q.deq();
    cout<<q.sz()<<endl;
    q.display();
    cout<<q.peekfront()<<" "<<q.peekrear()<<endl;
    return 0;
}