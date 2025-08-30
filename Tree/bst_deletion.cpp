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

Node* findSucc(Node* root)
{
    while(root && root->left!=nullptr)
    {
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root,int val)
{
    if(root==nullptr)return nullptr;

    if(val<root->data)root->left=deleteNode(root->left,val);
    else if (val>root->data)root->right=deleteNode(root->right,val);

    else
    {
        //node found

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
            // two children

            Node* temp=findSucc(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }

    return root;
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
    // root = insert(root,88);
    inorder(root);
    cout<<endl;
    root=deleteNode(root,6);
    inorder(root);
    return 0;
}