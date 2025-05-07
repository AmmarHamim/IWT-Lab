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

int main()
{
    fast_io;

    Node* first = new Node(4);
    Node* second = new Node(8);
    Node* third = new Node(1);
    Node* fourth = new Node(99);

    cout<<"without linking"<<endl;
    cout<<first->data<<" "<<second->next<<endl;
    cout<<second->data<<" "<<second->next<<endl;

    first->next = second;
    second->next = third;
    third->next= fourth;

    cout<<"Linking the nodes"<<endl;
    cout<<first->data<<" "<<first->next<<endl;
    cout<<second->data<<" "<<second->next<<endl;
    cout<<third->data<<" "<<third->next<<endl;
    cout<<fourth->data<<" "<<fourth->next<<endl;

    return 0;
}