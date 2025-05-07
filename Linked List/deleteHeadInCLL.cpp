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

Node* deleteHead(Node* tail)
{
    if(tail==nullptr)
    {
        cout<<"The List is empty"<<endl;
        return nullptr;
    }

    Node* head = tail->next;
    if(head==tail) // one element in the list
    {
        delete head;
        tail=nullptr;
        return tail;
    }

    tail->next=tail->next->next;
    delete head;
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
    // Node* tail= nullptr;

    cout<<"Original Linked list: ";
    PrintCLL(tail);

    cout<<"After deleting head : ";
    tail=deleteHead(tail);
    PrintCLL(tail);

    return 0;
}