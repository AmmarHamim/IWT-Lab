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
    if (arr.empty()) return nullptr;
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

Node* insertAtPosition(Node* head, int val, int pos)
{

    if(head==NULL)
    {
        if(pos==1)return new Node(val);
        else
        {
            cout<<"Invalid Position"<<endl;
            return head;
        }
    }
    if(pos==1)
    {
        // Node* newNode=new Node(val);
        // newNode->next=head;
        // return newNode;

        return new Node(val,head);
    }


    Node* temp = head;
    int ct=0;
    while(temp)
    {
        ct++;
        if(ct==pos-1)
        {
            // Node* newNode = new Node(val,temp->next);
            // temp->next = newNode;
            break;
        }
        // ct++;
        temp=temp->next;
    }

    if (!temp) {
        cout << "Invalid Position" << endl;
        return head;
    }
    Node* newNode = new Node(val,temp->next);
    temp->next = newNode;

    return head;
}

int main()
{
    fast_io;

    vector<int>arr{2,9,7,5,11,14};

    Node* head = ConvertArr2LL(arr);

    int val=100;
    int pos=8;
    head = insertAtPosition(head,val,pos);
    PrintLL(head);

    return 0;
}