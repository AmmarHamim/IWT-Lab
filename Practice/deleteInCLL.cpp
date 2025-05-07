#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};
void displayCLL(Node* tail)
{
    Node* temp=tail->next;
    while(1)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==tail->next)break;
    }
}
Node* deleteHead(Node* tail)
{
    if(tail==nullptr)
    {
        cout<<"The List is empty"<<endl;
        return nullptr;
    }
    Node* head=tail->next;
    if(head==tail)
    {
        delete head;
        return nullptr;
    }
    Node* temp=tail->next;
    tail->next=temp->next;
    delete temp;
    return tail;
}
Node* deleteTail(Node* tail)
{
    if(tail==nullptr)
    {
        cout<<"Empty"<<endl;
        return NULL;
    }
    Node* head=tail->next;
    if(head==tail)
    {
        delete head;
        return nullptr;
    }
    Node* temp=tail->next;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    Node* todelete= temp->next;
    temp->next=todelete->next;
    delete todelete;
    tail= temp;
    return tail;
}

Node* deleteAtPos(Node* tail,int k)
{
    if(tail==nullptr)
    {
        cout<<"empty"<<endl;
        return NULL;
    }
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
        tail->next=head->next;
        delete head;
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
    if(temp->next==tail->next)
    {
        cout<<"Invalid"<<endl;
        return tail;
    }
    Node* todelete=temp->next;
    temp->next=todelete->next;
    delete todelete;
    if(todelete==tail)tail=temp;
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
    // tail=deleteHead(tail);
    // tail=deleteTail(tail);
    int k=4;
    tail=deleteAtPos(tail,k);
    displayCLL(tail);
    cout<<endl;
    return 0;
}