#include<bits/stdc++.h>
using namespace std;
#define stSize 100
int stackk[stSize];
int top=-1;
bool isFull(){
    return top>=stSize-1;
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
int peek()
{
    if(isEmpty())return 0;
    return stackk[top];
}

bool isOperand(char ch)
{
    return ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&& ch<='9'));
}
int precedence(char ch)
{
    if(ch=='^')return 3;
    else if(ch=='*'||ch=='/')return 2;
    else if(ch=='+'||ch=='-')return 1;
    else return -1;
}

void infixtopostfix(char infix[],char postfix[])
{
    int k=0;

    for(int i=0;infix[i]!='\0';i++)
    {
        char ch=infix[i];

        if(isOperand(ch))postfix[k++]=ch;
        else if(ch=='(')pushh(ch);
        else if(ch==')')
        {
            while(!isEmpty() and peek()!='(')
            {
                postfix[k++]=peek();
                popp();
            }
            popp();
        }

        else
        {
            while(!isEmpty() and precedence(ch)<=precedence(peek()))
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
}
int main()
{
    
    char infix[200]="(p+q)*(m-n)";
    char postfix[200];

    infixtopostfix(infix,postfix);
    cout<<postfix<<endl;
    return 0;
}