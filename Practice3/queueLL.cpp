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

    Node (int val)
    {
        data=val;
        next=nullptr;
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
        f=NULL;
        r=NULL;
        ct=0;
    }
    bool isEmpty()
    {
        return ct==0;
    }
    void enq(int val)
    {
        Node* newNode=new Node(val);
        if(ct==0)
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
            return;
        }
        Node* temp=f;
        f=f->next;
        delete temp;
        ct--;
    }
    void display()
    {
        if(isEmpty())return;
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
    fast_io;

    Queue q;
    q.enq(10);
    q.enq(10);
    q.enq(10);
    q.deq();
    q.display();
    return 0;
}