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

};
Node* takeInput(int n)
{
    if(n<=0) return NULL;
    int val;cin>>val;
    Node* newNode = new Node(val);
    Node* head=newNode;
    Node* tail=head;
     for(int i=1;i<n;i++)
     {
         cin>>val;
         tail->next = new Node(val);
         tail=tail->next;
     }
     return head;

}
void PrintLL(Node* head)
{
    Node* temp = head;
    cout<<"Elements : ";
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* removeDup(Node* head)
{
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data == temp->next->data)
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

    int n;
    cout<<"Enter num of nodes: ";
    cin>>n;
    cout<<"Enter Nodes: ";
    Node* head=takeInput(n);
    // PrintLL(head);
    cout<<"Reversed List: ";
    head = removeDup(head);
    PrintLL(head);

    return 0;
}