#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define maxSize 10
int q[maxSize];
int front=-1,rear=-1,cnt=0;
bool isEmpty(){
    return cnt==0;
}
bool isFull(){
    return cnt==maxSize;
}
void enqueue(int val){
    if(isFull())
    {
        cout<<"Tham!! r dishna!!"<<endl;
        return;
    }
    if(cnt==0)
    {
        front=rear=0;
    }
    else 
    rear=(rear+1)%maxSize;
    q[rear]=val;
    cnt++;
}
void dequeue(){
    if(isEmpty())
    {
        cout<<"r ki ber krbi!! Already sesh!"<<endl;
        return;
    }
    if(cnt==1)
    {
        rear=front=-1;
    }
    else
    front=(front+1)%maxSize;
    cnt--;
}
void display(){
    if(isEmpty())
    {
        cout<<"khaliii"<<endl;
        return;
    }
    int i=front;
    while(1)
    {
        cout<<q[i]<<" ";
        if(i==rear)break;
        i=(i+1)%maxSize;
    }
}

int Size(){
    return cnt;
}

int main()
{
    fast_io;

    if(isEmpty())cout<<"virgin"<<endl;
    enqueue(10);
    enqueue(20);
    enqueue(45);
    enqueue(20);
    enqueue(33);
    enqueue(20);
    enqueue(33);
    enqueue(78);
    enqueue(45);
    enqueue(66);
    cout<<"Size: "<<Size()<<endl;
    if(isFull())cout<<"Fulll"<<endl;
    display();
    cout<<endl;

    dequeue();
    dequeue();
    dequeue();
    enqueue(29);
    display();
    return 0;
}