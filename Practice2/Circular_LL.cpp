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

void PrintCLL(Node* tail)
{
    if(tail==NULL)return ;
    Node* head=tail->next;
    Node* temp=head;
    while(1)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==head)break;
    }
}

Node* insertAtPos(Node* tail,int val,int k)
{
    Node* newNode=new Node(val);
    if(tail==NULL)
    {
        if(k==1)
        {
            newNode->next=newNode;
            return newNode;
        }
        else return NULL;
    }
    if(k==1)
    {
        newNode->next=tail->next;
        tail->next=newNode;
        return tail;
    }
    Node* temp=tail->next;
    int ct=0;
    while(1)
    {
        ct++;
        if(ct==k-1)break;
        temp=temp->next;
        if(temp==tail->next)
        {
            cout<<"Invalid"<<endl;
            return tail;
        }
    }
        newNode->next=temp->next;
        temp->next=newNode;
        if(temp==tail)tail=newNode;
        return tail;
}
Node* deleteAtPos(Node* tail,int k)
{
    if(tail==NULL)return tail;
    Node* head=tail->next;
    if(head==tail)
    {
        if(k==1)
        {
            delete head;
            return NULL;
        }
        else
        {
            cout<<"Invalid"<<endl;
            return tail;
        }
    }
    if(k==1)
    {
        Node* dlt=tail->next;
        tail->next=dlt->next;
        delete dlt;
        return tail;
    }
    Node* temp=tail->next;
    int ct=0;
    while(1)
    {
        ct++;
        if(ct==k-1)break;
        temp=temp->next;
        if(temp==tail->next || temp->next==tail->next)
        {
            cout<<"Invalid"<<endl;
            return tail;
        }
    }
    Node* todelete=temp->next;
    temp->next=todelete->next;
    if(todelete==tail)tail=temp;
    delete todelete;
    return tail;
}
Node* insertHead(Node* tail,int val)
{
    Node* newNode=new Node(val);
    if(tail==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    newNode->next=tail->next;
    tail->next=newNode;
    return tail;
}
Node* insertTail(Node* tail,int val)
{
    Node* newNode=new Node(val);
    if(tail==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    newNode->next=tail->next;
    tail->next=newNode;
    tail=newNode;
    return tail;
}
Node* deleteTail(Node* tail)
{
    if(tail==NULL)return NULL;
    Node* temp=tail->next;
    if(temp==tail)
    {
        delete temp;
        return NULL;
    }
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    Node* todelete=temp->next;
    temp->next=tail->next;
    tail=temp;
    delete todelete;
    return tail;
}
Node* deleteHead(Node* tail)
{
    if(tail==NULL)return NULL;
    Node* temp=tail->next;
    if(temp==tail)
    {
        delete temp;
        return NULL;
    }
    Node* todelete=tail->next;
    tail->next=todelete->next;
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

    //  tail=insertAtPos(tail,1000,4);
    // tail=deleteAtPos(tail,2);
    // tail=insertHead(tail,1000);
    // tail=insertTail(tail,1000);
    // tail=deleteTail(tail);
    tail=deleteHead(tail);
     PrintCLL(tail);
    return 0;
}