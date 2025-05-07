#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define StSize 5
int Stack[StSize];
int top=-1;

bool isEmpty(){
    return top==-1;
}
bool isFull(){
    return top>=StSize-1;
}

void Push(int val){
    if(isFull())
    {
        cout<<"The Stack is full"<<endl;
        return;
    }
    Stack[++top]=val;
}
void Pop(){
    if(isEmpty())
    {
        cout<<"The Stack is empty"<<endl;
        return;
    }
    top--;
}
int Peek(){
    if(isEmpty())
    {
        cout<<"The Stack is empty"<<endl;
        return -1;
    }
    return Stack[top];
}
void display(){
    if(isEmpty())
    {
        cout<<"The Stack is empty"<<endl;
        return;
    }

    for(int i=top;i>=0;i--)
    {
        cout<<Stack[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    fast_io;

    if(isEmpty())cout<<"khalii"<<endl;
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);
    Push(60);
    cout<<Peek()<<endl;
    display();
    Pop();
    Pop();
    cout<<Peek()<<endl;
    display();
    return 0;
}