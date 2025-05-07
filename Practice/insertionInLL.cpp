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
void displayLL(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* insertHead(Node* head,int val)
{
    Node* newNode=new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return head;
    }
    newNode->next=head;
    head=newNode;
    return head;
}
Node* insertTail(Node* head,int val)
{
    Node* newNode=new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return head;
    }
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
Node* insertAtKthPos(Node* head,int k,int val)
{
    Node* newNode = new Node(val);
    if(head==nullptr)
    {
        if(k==1)return newNode;
        else return nullptr;
    }
    if(k==1)
    {
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node* temp=head;
    int ct=0;
    while(temp)
    {
        ct++;
        if(ct==k-1)
        {
            break;
        }
        temp=temp->next;
    }
    if(!temp || k<0)
    {
        cout<<"Invalid"<<endl;
        return head;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
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
    Node* head = first;
    displayLL(head);
    cout<<endl;
    int val=101;
    // head=insertHead(head,val);
    // displayLL(head);
    // head=insertTail(head,val);
    // displayLL(head);
    int k=3;
    head=insertAtKthPos(head,k,val);
    displayLL(head);
    return 0;
}