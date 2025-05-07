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
        // Node* temp = new Node(arr[i]);
        // current->next = temp;
        // current = temp; // current=current->next;

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

int main()
{
    fast_io;

    vector<int>arr{3,5,6,7,3};

    Node* head = ConvertArr2LL(arr);
    PrintLL(head);

    return 0;
}