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

void printll(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* insertAtPos(Node* head,int val,int k,int n)
{
    n++;
    if(k<=0 or k>n)
    {
        cout<<"invalid"<<endl;
        return head;
    }
    Node* newNode=new Node(val);
    if(head==nullptr)
    {
        if(k==1)return newNode;
        else return head;
    }
    if(k==1)
    {
        newNode->next=head;
        head=newNode;
        return newNode;
    }
    int ct=0;
    Node* temp=head;
    while(temp)
    {
        ct++;
        if(ct==k-1)break;
        temp=temp->next;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
Node* deleteAtPos(Node* head,int k,int n)
{
    if(k<=0 or k>n)
    {
        cout<<"invalid"<<endl;
        return head;
    }
    if(head==nullptr)return head;
    if(k==1)
    {
        Node* toDelete=head;
        head=head->next;
        delete toDelete;
        return head;
    }
    Node* temp=head;
    int ct=0;
    while(temp)
    {
        ct++;
        if(ct==k-1)break;
        temp=temp->next;
    }
    Node* todelete=temp->next;
    temp->next=todelete->next;
    delete todelete;
    return head;
}

int findMid(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=nullptr and fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow->data;
}
void reversell(Node* head)
{
    if(head==nullptr)return;
    reversell(head->next);
    cout<<head->data<<" ";
}
Node* reverselll(Node* head)
{
    Node* prev=nullptr;
    Node* curr=head;
    while(curr)
    {
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* removedupli(Node* head)
{
    Node* temp=head;
    while(temp and temp->next)
    {
        if(temp->data==temp->next->data)
        temp->next=temp->next->next;
        else temp=temp->next;
    }
    return head;
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

    // head=insertAtPos(head,100,6,n);
    // head=deleteAtPos(head,5,n);
    // cout<<findMid(head)<<endl;
    // reversell(head);
    // head=reverselll(head);
    head=removedupli(head);
    printll(head);
}