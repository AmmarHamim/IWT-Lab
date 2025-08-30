#include<bits/stdc++.h>
using namespace std;
#define qsz 5
int q[qsz];
int front=-1,rear=-1,ct=0;

bool isEmpty(){
    return ct==0;
}
bool isFull(){
    return ct>=qsz;
}
void enqueue(int val)
{
    if(isFull())return;
    if(ct==0)
    {
        front=rear=0;
    }
    else rear=(rear+1)%qsz;

    q[rear]=val;
    ct++;
}
void dequeue()
{
    if(isEmpty())return;
    if(ct==1)
    {
        front=rear=-1;
    }
    else front=(front+1)%qsz;
    ct--;
}

void display()
{
    if(isEmpty())return;

    int i=front;
    while(1)
    {
        cout<<q[i]<<" ";
        if(i==rear)break;
        i=(i+1)%qsz;
    }
    cout<<endl;
}
int sz(){
    return ct;
}
int main()
{

    if(isEmpty())cout<<"nai"<<endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    cout<<sz()<<endl;
    display();
    dequeue();
    dequeue();
    display();
}