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
class qu{
    public:
    Node* f;
    Node* r;
    int ct;

    public:
    qu()
    {
        f=r=NULL;
        ct=0;
    }
    bool isEmpty()
    {
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
            cout<<"khaliiiii"<<endl;
            return;
        }
        Node* todelete = f;
        f=f->next;
        delete todelete;
        ct--;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"khali"<<endl;
            return;
        }
        Node* temp=f;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int sz()
    {
        return ct;
    }

};
int main()
{

    qu q;
    if(q.isEmpty())cout<<"khali"<<endl;
    q.enq(10);
    q.enq(20);
    q.enq(30);
    q.enq(40);
    cout<<q.sz()<<endl;
    q.display();
    q.deq();
    q.deq();
    cout<<q.sz()<<endl;
    q.display();

    return 0;
}