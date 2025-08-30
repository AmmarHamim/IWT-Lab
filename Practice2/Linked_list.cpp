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

    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};

void  PrintLL(Node* head)
{
    cout<<"The LL: ";
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* insertAtPos(Node* head,int val,int k)
{
    Node* newNode=new Node(val);
    if(head==NULL)
    {
        if(k==1)
        {
            return newNode;
        }
        else
        {
            cout<<"Invalid"<<endl;
            return head;
        }
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
    if(temp==NULL || k<0)
    {
        cout<<"Invalid"<<endl;
        return head;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
Node* deleteAtPos(Node* head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    if(k==1)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
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

    if(temp==NULL || k<=0 || temp->next==NULL)
    {
        cout<<"Invalid"<<endl;
        return head;
    }
    Node* toDelete = temp->next;
    temp->next=toDelete->next;
    delete toDelete;
    return head;
}
Node* insertHead(Node* head,int val)
{
    Node* newNode=new Node(val);
    if(head==NULL)return newNode;
    newNode->next=head;
    head=newNode;
    return head;
}
Node* insertTail(Node* head,int val)
{
    Node* newNode=new Node(val);
    if(head==NULL)return newNode;
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
Node* deleteTail(Node* head)
{
    if(head==NULL)return head;
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    Node* todelete=temp->next;
    temp->next=NULL;
    delete todelete;
    return head;
}
Node* deleteHead(Node* head)
{
    if(head==NULL)return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;

}
Node* reverseLL(Node* head)
{
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    Node* prev=NULL;
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
Node* removeDupli(Node* head)
{
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            temp->next=temp->next->next;
        }
        else temp=temp->next;
    }
    return head;

}
int main()
{
    // fast_io;

    // cout<<"Enter Num Of Nodes: ";
    int n;cin>>n;
    int x;cin>>x;
    Node* head= new Node(x);
    Node* tail=head;
    for(int i=1;i<n;i++)
    {
        cin>>x;
        tail->next=new Node(x);
        tail=tail->next;
    }

    // PrintLL(head);

    // head=insertAtPos(head,100,6);
    // PrintLL(head);
    // head=deleteAtPos(head,2);
    // head=insertHead(head,1000);
    // head=insertTail(head,1000);
    // head=deleteTail(head);
    // head=deleteHead(head);
    // head=reverseLL(head);
    head=removeDupli(head);
    PrintLL(head);
    
    return 0;
}