#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
    int data;
    Node* next;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        next=left=right=nullptr;
    }
};

Node* bstinsert(Node* root,int val)
{
    if(root==nullptr)return new Node(val);
    if(val<root->data)root->left=bstinsert(root->left,val);
    if(val>root->data)root->right=bstinsert(root->right,val);
    return root;
}

Node* findmin(Node* root)
{
    while(root and root->left!=nullptr)
    {
        root=root->left;
    }

    return root;
}

Node* bstdelete(Node* root,int val)
{
    if(root==nullptr)return root;
    if(val>root->data)root->right=bstdelete(root->right,val);
    else if(val<root->data)root->left=bstdelete(root->left,val);
    else
    {
        if(root->left==nullptr)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else 
        {
            Node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=bstdelete(root->right,temp->data);
        }
    }
    return root;
}
void inorder(Node* root)
{
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool bstsearch(Node* root,int val)
{
    if(root==nullptr)return false;
    if(val==root->data)return true;
    if(val>root->data)return bstsearch(root->right,val);
    return bstsearch(root->left,val);
}
int main()
{

    int n;cin>>n;
    Node* root=nullptr;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        root=bstinsert(root,x);
    }

    inorder(root);
    cout<<endl;
    root=bstdelete(root,4);
    inorder(root);
    if(bstsearch(root,6))cout<<"yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}