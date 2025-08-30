#include<bits/stdc++.h>
using namespace std;
#define stSize 5
int stackk[stSize];
int top=-1;
bool isFull(){
    return top>=stSize;
}
bool isEmpty(){
    return top==-1;
}
void pushh(int val)
{
    if(isFull())return;

    stackk[++top]=val;
}
void popp()
{
    if(isEmpty())return;

    top--;
}
int sz(){
    return top+1;
}
void display()
{
    if(isEmpty())return;
    for(int i=top;i>=0;i--)
    {
        cout<<stackk[i]<<" ";
    }
    cout<<endl;
}
int main()
{

    if(isEmpty())cout<<"Khali"<<endl;
    pushh(10);
    pushh(20);
    pushh(30);
    pushh(30);
    pushh(30);
    cout<<sz()<<endl;
    display();
    popp();
    popp();
    popp();
    display();
    return 0;
}