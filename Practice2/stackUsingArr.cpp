#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define stSize 5
int st[stSize];
int top=-1;
bool isEmpty(){
    return top==-1;
}
bool isFull(){
    return top>= stSize-1;
}
int sz()
{
    return top+1;
}
void pushh(int val)
{
    if(isFull())
    {
        cout<<"Full"<<endl;
        return;
    }

    st[++top]=val;

}
void popp()
{
    if(isEmpty())
    {
        cout<<"khali"<<endl;
        return;
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
    int temp=top;
    while(temp>=0)
    {
        cout<<st[temp]<<" ";
        temp--;
    }
    cout<<endl;
}
int peek()
{
    return st[top];
}
int main()
{
    fast_io;

    if(isEmpty())cout<<"khalii"<<endl;
    if(isFull())cout<<"vora"<<endl;
    pushh(10);
    pushh(20);
    pushh(30);
    cout<<sz()<<endl;
    display();
    cout<<peek()<<endl;
    popp();
     display();
     cout<<sz()<<endl;

    return 0;
}