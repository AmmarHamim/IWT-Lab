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

    Node (int val)
    {
        data=val;
        next=nullptr;
    }
};
Node* inAtPos(Node* tail,int  val,int k)
{
    Node* newNode=new Node(val);
    if(tail==NULL)
    {
        if(k==1)
        {
            newNode->next=newNode;
            return newNode;
        }
        else return NULL;
    }
    if(k==1)
    {
        newNode->next=tail->next;
        tail->next=newNode;
        return tail;
    }
    Node* temp=tail->next;
    int ct=0;
    while(1)
    {
        ct++;
        if(ct==k-1)break;
        temp=temp->next;
        if(temp==tail->next)
        {
            cout<<"invalid"<<endl;
            return tail;
        }
    }
            newNode->next=temp->next;
        temp->next=newNode;
        if(temp==tail)tail=newNode;
        return tail;
}
void PrintCLL(Node* tail)
{
    if(tail==NULL)return ;
    Node* head=tail->next;
    Node* temp=head;
    while(1)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==head)break;
    }
}
int main()
{
    fast_io;

    int n;cin>>n;
    int x;cin>>x;
    Node* head=new Node(x);
    Node* tail=head;
     for(int i=1;i<n;i++)
     {
        cin>>x;
        tail->next=new Node(x);
        tail=tail->next;
     }
     tail->next=head;

     tail=inAtPos(tail,100,7);
     PrintCLL(tail);

    return 0;
}