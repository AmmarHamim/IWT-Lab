#include<bits/stdc++.h>
using namespace std;
#define maxSize 5
int qq[maxSize];
int f=-1,r=-1,ct=0;
bool isEmpty()
{
    return ct==0;
}
bool isFull()
{
    return ct==maxSize;
}
void enq(int val)
{
    if(isFull())
    {
        cout<<"overflow"<<endl;
        return;
    }
    if(ct==0)
    {
        f=r=0;
    }
    else r=(r+1)%maxSize;
    qq[r]=val;
    ct++;
}
void deq()
{
    if(isEmpty())
    {
        cout<<"Underflow"<<endl;
        return;
    }
    if(ct==1)
    {
        f=r=-1;
    }
    else f=(f+1)%maxSize;
    ct--;
}
void display()
{
    int i=f;
    while(1)
    {
        cout<<qq[i]<<" ";
        if(i==r)break;
        i=(i+1)%maxSize;
    }
    cout<<endl;
    
}
int sz()
{
    return ct;
}
int main()
{
    if(isEmpty())cout<<"khali"<<endl;
    cout<<sz()<<endl;
    enq(10);
    enq(20);
    enq(30);
    enq(40);
    enq(50);
    enq(50);
    cout<<sz()<<endl;
    display();
    deq();
    deq();
    deq();
    display();
    return 0;
}