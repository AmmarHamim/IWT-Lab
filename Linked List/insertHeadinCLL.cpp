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

Node* insertHead(Node* tail,int val)
{
    Node* newNode = new Node(val);
    if(tail==nullptr)
    {
        newNode->next=newNode;
        return newNode;
    }
    newNode->next=tail->next;
    tail->next=newNode;

    return tail;

}

int main()
{
    fast_io;

    Node* first = new Node(3);
    Node* second = new Node(5);
    Node* third = new Node(9);

    first->next=second;
    second->next=third;
    third->next=first; // for being circular

    Node* tail= third;

    cout<<"Original Linked list: ";
    PrintCLL(tail);

    cout<<"After Inserting Head: ";
    tail=insertHead(tail,10);
    PrintCLL(tail);

    return 0;
}