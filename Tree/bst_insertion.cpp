#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    public:
        Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root,int val)
{
    if(root==nullptr)return new Node(val);
    if(root->data<val)root->right=insert(root->right,val);
    else root->left=insert(root->left,val);

    return root;
}
void inorder(Node* root)
{
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    fast_io;

    Node* root=nullptr;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;cin>>val;
        root=insert(root,val);
    }
    root = insert(root,88);
    inorder(root);
    return 0;
}