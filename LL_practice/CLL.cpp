#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* next;
    int data;

    public:
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};

void printcll(Node* tail)
{
    Node* temp=tail->next;
    while(1)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==tail->next)break;
    }
}

Node* insertAtPos(Node* tail,int val,int k,int n)
{
    n++;
    if(k<=0 or k>n)
    {
        cout<<"invalid"<<endl;
        n--;
        return tail;
    }
    Node* newNode=new Node(val);
    if(tail==nullptr)return tail;
    if(k==1)
    {
        newNode->next=tail->next;
        tail->next=newNode;
        return tail;
    }
    int ct=0;
    Node* temp=tail->next;
    while(1)
    {
        ct++;
        if(ct==k-1)break;
        temp=temp->next;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    if(temp==tail)tail=newNode;
    return tail;
}
Node* deleteAtPos(Node* tail,int k,int n)
{
    if(k<=0 or k>n)
    {
        cout<<"invalid"<<endl;
        return tail;
    }

    if(tail==nullptr)return tail;
    if(k==1)
    {
        Node* todelete=tail->next;
        tail->next=todelete->next;
        delete todelete;
        return tail;
    }
    int ct=0;Node* temp=tail->next;
    while(1)
    {
        ct++;
        if(ct==k-1)break;
        temp=temp->next;
    }

    Node* todelete=temp->next;
    temp->next=todelete->next;
    if(todelete==tail)tail=temp;
    delete todelete;
    return tail;
}
int main()
{

    int n;cin>>n;
    int x;cin>>x;
    Node* head=new Node(x);
    Node* tail=head;
     for(int i=1;i<n;i++)
     {
         cin>>x;
         tail->next=new Node(x);
         tail=tail->next;
     }

     tail->next=head;

    // tail=insertAtPos(tail,100,5,n);
    tail=deleteAtPos(tail,5,n);
    printcll(tail);

    return 0;
}