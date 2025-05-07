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

Node* deleteAtPosition(Node* tail,int pos)
{
    if(tail==nullptr)
    {
        cout<<"The List is empty"<<endl;
        return tail;
    }

    Node* head=tail->next;
    if(head==tail) //one element
    {
        delete head;
        tail = nullptr;
        return tail;
    }
    Node* temp=tail->next;
    if(pos==1)
    {
        tail->next=temp->next;
        delete temp;
        return tail;
    }

    Node* prev=tail->next;

    for(int i=1;i<pos-1;i++)
    {
        prev=prev->next;

        if(prev==tail->next)
        {
            cout<<"Invalid Position"<<endl;
            return tail;
        }
    }
    if(prev->next==head)
    {
        cout<<"Invalid Position"<<endl;
        return tail;
    }
    Node* toDelete=prev->next;
    prev->next= prev->next->next; // toDelete.next

    if(toDelete==tail)
    {
        tail=prev;
    }
    delete toDelete;
    return tail;

}

int main()
{
    fast_io;

    Node* first = new Node(3);
    Node* second = new Node(5);
    Node* third = new Node(0);
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

    cout<<"After deleting at pos : ";
    int pos=7;
    tail=deleteAtPosition(tail,pos);
    PrintCLL(tail);

    return 0;
}