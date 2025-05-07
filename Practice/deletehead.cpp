#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
   int data;
   Node *next;
   public:
   Node( int value){
    data=value;
    next=nullptr;
   }
};
void Print(Node *head){
    Node* temp;
    temp=head;
     while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;

     }
}

Node *removeHead(Node *head){
    if(head==nullptr)return nullptr;
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* removeTail(Node* head)
{
    if(head==NULL)return head;
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    Node* toDelete;
    toDelete=temp->next;
    delete toDelete;
    temp->next=NULL;
    
    return head;
}
Node* removeKthPos(int k,Node* head)
{
    if(head==NULL)return head;
    if(k==1)
    {
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }

    int ct=0;
    Node* temp=head;
    // Node* prev = nullptr;
    while(temp)
    {
        ct++;
        if(ct==k-1)
        {
            break;
        }
        // prev=temp;
        temp=temp->next;
    }
    if(!temp || k<0 || !temp->next)cout<<"Invalid"<<endl;
    Node* todelete = temp->next;
    temp->next=todelete->next;
    delete todelete;

    return head;
}
Node* insertHead(Node* head,int val)
{
    Node* newNode = new Node(val);
    if(head==nullptr)
    {
        head=newNode;
        return head;
    }
    newNode->next=head;
    head=newNode;
    return head;
}
int main()
{
    Node *first=new Node(5);
    Node *second=new Node(6);
    Node *third=new Node(7);
    Node *fourth=new Node(8);

    first->next=second;
    second->next=third;
    third->next=fourth;

    Node* head;
    head=first;

    Print(head);
    cout<<endl;
    // head=removeHead(head);
    // Print(head);
    // cout<<endl;

    // head= removeTail(head);
    // Print(head);
    // cout<<endl;
    int k=4;
    head = removeKthPos(k,head);
    Print(head);
    // int val=100;
    // head = insertHead(head,val);
    // Print(head);
    return 0;
}