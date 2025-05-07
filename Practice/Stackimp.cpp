#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Stsize 5
int st[Stsize];
int top=-1;
bool isEmpty(){
    return top==-1;
}

bool isFull(){
    return top>=Stsize-1;
}
void Push(int val)
{
    if(isFull())
    {
        cout<<"Full"<<endl;
        return;
    }
    st[++top]=val;
}
void Pop()
{
    if(isEmpty())
    {
        cout<<"Khali"<<endl;
        return ;
    }
    top--;
}
void display()
{
    if(isEmpty())
    {
        cout<<"Nothing to show"<<endl;
        return;
    }
    for(int i=top;i>=0;i--)
    {
        cout<<st[i]<<" ";
    }
    cout<<endl;
}
int Size()
{
    return top+1;
}
int peek()
{
    if(isEmpty())
    {
        cout<<"The Stack is empty"<<endl;
        return -1;
    }
    return st[top];
}
int main()
{
    fast_io;

    cout<<Size()<<endl;
    if(isEmpty())cout<<"empty"<<endl;
    Push(10);
    Push(30);
    cout<<Size()<<endl;
    Push(40);
    Push(550);
    Push(5540);
    cout<<Size()<<endl;
    // Push(200);
    display();
    if(isEmpty())cout<<"empty"<<endl;
    cout<<peek()<<endl;
    
    Pop();
    display();
    Pop();
    cout<<peek()<<endl;
    return 0;
}