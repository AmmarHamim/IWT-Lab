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

    
    public:
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    Node(int val, Node* ptr)
    {
        data=val;
        next=ptr;
    }

};

void PrintCLL(Node* tail)
{
    if(tail==nullptr)return ;
    Node* temp=tail->next;
    while(true)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

        if(temp==tail->next)break;
    }
    cout<<endl;

}

Node* insertAtPosition(Node* tail,int pos,int val)
{
    if(tail==nullptr)
    {
        if(pos==1)
        {
            Node* newNode = new Node(val);
            newNode->next=newNode;

            tail=newNode; // update tail
            return tail;
        }
        else
        {
            cout<<"Invalid Position"<<endl;
            return tail;
        }
    }

    if(pos==1)
    {
        Node* newNode = new Node(val);
        newNode->next=tail->next;
        tail->next=newNode;
        return tail;
    }

    Node* temp=tail->next;

    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;

        if(temp==tail->next)
        {
            cout<<"Invalid Position"<<endl;
            return tail;
        }
    }

    Node* newNode = new Node(val);
    newNode->next=temp->next;
    temp->next=newNode;
    
    if(temp==tail)tail=newNode; // update tail if it is inserted at the end;
    return tail;
}

int main()
{
    fast_io;

    Node* first = new Node(3);
    Node* second = new Node(5);
    Node* third = new Node(9);
    Node* fourth = new Node(9);
    Node* fifth = new Node(2);
    Node* sixth = new Node(1);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=first;

    Node* tail= sixth;

    cout<<"Original Linked list: ";
    PrintCLL(tail);

    cout<<"After Inserting at pos : ";
    int pos=3,val=69;
    tail=insertAtPosition(tail,pos,val);
    PrintCLL(tail);

    return 0;
}