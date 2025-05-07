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

Node* ConvertArr2LL(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* current = head;

    for(int i=1;i<arr.size();i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

void PrintLL(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
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
    Node* prev = nullptr;
    while(temp)
    {
        ct++;
        if(ct==k)
        {
            prev->next=prev->next->next;
            // prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }

    return head;
}

int main()
{
    fast_io;

    vector<int>arr{3,5,10,88,12,99};

    Node* head = ConvertArr2LL(arr);

    int k=2;
    head = removeKthPos(k,head);
    PrintLL(head);

    return 0;
}