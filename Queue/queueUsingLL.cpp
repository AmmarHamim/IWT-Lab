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

class Queue{
    Node* front;
    Node* rear;
    int cnt;

    public:
    Queue()
    {
        front=rear=nullptr;
        cnt=0;
    }

    bool isEmpty(){
        return cnt==0;
    }
    void enqueue(int val){
        Node* newNode=new Node(val);
        if(isEmpty())
        {
            front=rear=newNode;
        }
        else
        {
            rear->next=newNode;
            rear=newNode;
        }
        cnt++;
    }
    void dequeue(){
        if(isEmpty())
        {
            cout<<"Empty"<<endl;
            return;
        }
        Node* temp=front;
        front=front->next;
        delete(temp);
        cnt--;
    }

    void display(){
        if(isEmpty())
        {
            cout<<"Empty"<<endl;
            return;
        }
        Node* temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int Size(){
        return cnt;
    }

};
int main()
{
    fast_io;

    Queue qu;
    qu.dequeue();
    qu.enqueue(11);
    qu.enqueue(13);
    qu.enqueue(3);
    qu.enqueue(14);
    qu.enqueue(44);
    qu.enqueue(55);
    cout<<"Size: "<<qu.Size()<<endl;
    qu.display();
    cout<<endl;
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    cout<<"Size: "<<qu.Size()<<endl;
    qu.display();

    return 0;
}