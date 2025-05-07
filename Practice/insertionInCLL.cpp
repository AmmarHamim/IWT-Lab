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
    Node(int val,Node* ptr)
    {
        data=val;
        next=ptr;
    }
};
void displayCLL(Node* tail)
{
    if(tail==nullptr)return ;
    Node* temp=tail->next;
    while(1)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==tail->next)break;
    }
}
Node* insertFront(Node* tail,int val)
{
    Node* newNode= new Node(val);
    if(tail==nullptr)
    {
        newNode->next=newNode;
        return newNode;
    }
    newNode->next=tail->next;
    tail->next=newNode;
    return tail;
}
Node* insertEnd(Node* tail,int val)
{
    Node* newNode= new Node(val);
    if(tail==nullptr)
    {
        newNode->next=newNode;
        return newNode;
    }
    Node* head=tail->next;
    newNode->next=head;
    tail->next=newNode;
    tail=newNode;
    return tail;
}
Node* insertAtPos(Node* tail, int val,int k)
{
    Node* newNode=new Node(val);
    if(tail==NULL)
    {
        if(k==1)
        {
            newNode->next=newNode;
            return newNode;
        }
        else 
        {
            cout<<"Invalid"<<endl;
        }
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
int main()
{
    Node* first=new Node(4);
    Node* sec=new Node(5);
    Node* thir=new Node(6);
    Node* four=new Node(7);
    first->next=sec;
    sec->next=thir;
    thir->next=four;
    four->next=first;
    Node* tail=four;
    displayCLL(tail);
    cout<<endl;
    // int val=100;
    // tail=insertFront(tail,val);
    // displayCLL(tail);
    int val=100;
    // tail=insertEnd(tail,val);
    // displayCLL(tail);
    int k=3;
    tail=insertAtPos(tail,val,k);
    displayCLL(tail);
}