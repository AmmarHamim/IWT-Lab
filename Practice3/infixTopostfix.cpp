#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define stSize 200
int st[stSize];
int top=-1;
bool isEmpty()
{
    return top==-1;
}
bool isFull()
{
    return top>=stSize-1;
}
void pushh(int val)
{
    if(isFull())
    {
        cout<<"full"<<endl;
        return;
    }
    st[++top]=val;
}
void popp()
{
    if(isEmpty())
    {
        cout<<"empty"<<endl;
    }
    top--;
}
void display()
{
    if(isEmpty())
    {
        return;
    }
    for(int i=top;i>=0;i--)
    {
        cout<<st[i]<<" ";
    }
    cout<<endl;
}
int peek()
{
    return st[top];
}
int  precedence(char ch)
{
    if(ch=='^')return 3;
    else if(ch=='*' || ch=='/')return 2;
    else if(ch=='+' || ch=='-')return 1;
    else return -1;
}
bool isOperand(char ch)
{
    return ((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0'&&ch<='9'));
}
void infixToPostfix(char infix[],char postfix[])
{
    int k=0;
    for(int i=0;infix[i]!='\0';i++)
    {
        char ch=infix[i];
        if(isOperand(ch))postfix[k++]=ch;
        else if(ch=='(')pushh(ch);
        else if(ch==')')
        {
            while(!isEmpty() && peek()!='(')
            {
                postfix[k++]=peek();
                popp();
            }
            popp();
        }
        else
        {
            while(!isEmpty() && precedence(ch)<=precedence(peek()))
            {
                postfix[k++]=peek();
                popp();
            }
            pushh(ch);
        }
    }
    while(!isEmpty())
    {
        postfix[k++]=peek();
        popp();
    }
    postfix[k]='\0';
}
int main()
{
    fast_io;

    // char infix[200]="c+(a+b)";
        char infix[200]="(p+q)*(m-n)";
    char postfix[200];
    infixToPostfix(infix,postfix);
    cout<<postfix<<endl;
    return 0;
}