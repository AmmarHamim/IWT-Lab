#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define StSize 200
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

int precedence(char c)
{
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+' || c=='-')return 1;
    else return -1;
}

bool isOperand(char c)
{
    return ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'));
}

void infixToPostfix(char infix[],char postfix[])
{
    int k=0;
    for(int i=0;infix[i]!='\0';i++)
    {
        char ch=infix[i];
        if(isOperand(ch))postfix[k++]=ch;

        else if(ch=='(') Push('(');

        else if(ch==')')
        {
            while(!isEmpty() && Peek()!='(')
            {
                postfix[k++]=Peek();
                Pop();
            }
            Pop(); // remove the opening braket
        }

        else
        {
            while(!isEmpty() && precedence(ch)<=precedence(Peek()))
            {
                postfix[k++]= Peek();
                Pop();
            }
            Push(ch);
        }
    }

    while(!isEmpty())
    {
        postfix[k++]=Peek();
        Pop();
    }

    postfix[k]='\0';
}
int main()
{
    fast_io;

    char infixExp[200]="(p+q)*(m-n)";
    char postfix[200];

    infixToPostfix(infixExp,postfix);

    cout<<postfix<<endl;
    return 0;
}