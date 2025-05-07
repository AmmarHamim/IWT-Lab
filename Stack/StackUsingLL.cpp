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
    
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};
class Stack{
    public:
    Node* top;
    int count;

    Stack()
    {
        top=nullptr;
        count=0;
    }

    bool isEmpty(){
        return top==nullptr;
    }
    void Push(int val){
        Node* newNode=new Node(val);
        newNode->next=top;
        top=newNode;
        count++;
    }
    void Pop(){
        if(top==nullptr)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
        count--;
    }
    int Peek()
    {
        if(isEmpty())
        {
            cout<<"I am empty"<<endl;
            return -1;
        }
        return top->data;
    }
    int Size()
    {
        return count;
    }

    void display(){
        if(isEmpty())
        {
            cout<<"I am empty"<<endl;
            return;
        }
        
        Node* temp=top;
        cout<<"Stack ele: ";
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main()
{
    fast_io;

    Stack st;
    if(st.isEmpty())cout<<"I am Virgin"<<endl;
    // cout<<st.top->data<<endl;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);

    cout<<"Size: "<<st.Size()<<endl;
    cout<<"Top Data: "<<st.top->data<<endl;
    // st.Push(60);
    cout<<"Peek ele: "<<st.Peek()<<endl;
    cout<<"Size: "<<st.Size()<<endl;
    st.display();

    st.Pop();
    cout<<"Size: "<<st.Size()<<endl;
    st.display();
    cout<<"Peek ele: "<<st.Peek()<<endl;

    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    cout<<"Size: "<<st.Size()<<endl;
    cout<<"Peek ele: "<<st.Peek()<<endl;

    return 0;
}