#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define maxSize 6
int qq[maxSize];
int f=-1,r=-1,ct=0;
bool isFull()
{
    return ct>=maxSize;
}
bool isEmpty()
{
    return ct==0;
}
int sz()
{
    return ct;
}
void enq(int val)
{
    if(isFull())
    {
        cout<<"full"<<endl;
        return;
    }
    if(isEmpty())
    {
        f=r=0;
    }
    else
    {
        r=(r+1)%maxSize;
    }
    qq[r]=val;
    ct++;
}
void deq()
{
    if(isEmpty())
    {
        cout<<"khali"<<endl;
        return;
    }
    if(sz()==1)
    {
        f=r=-1;
    }
    else
    {
        f=(f+1)%maxSize;
    }

    ct--;
}
void display()
{
    if(isEmpty())
    {
        cout<<"nooo"<<endl;
        return ;
    }
    int i=f;
    while(1)
    {
        cout<<qq[i]<<" ";
        if(i==r)break;
        i=(i+1)%maxSize;
    }
    cout<<endl;
}
int main()
{
    fast_io;

    if(isEmpty())cout<<"khali"<<endl;
    enq(10);
    enq(20);
    enq(30);
    enq(40);
    cout<<sz()<<endl;
    display();
    deq();
    deq();
    cout<<sz()<<endl;
    display();

    return 0;
}