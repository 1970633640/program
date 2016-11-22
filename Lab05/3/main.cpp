#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;
typedef struct node
{
    node* left;
    node * right;
    bool IsNumber;
} node;

void build(string x,node * root)
{
    if(x.length()>1)
    {
        if (x[0]=='0')
        {
            if(root->left!=NULL)build(x.substr(1),root->left);
            else
            {
                node*p=new node;
                p->left=NULL;
                p->right=NULL;
                p->IsNumber=false;
                root->left=p;
                build(x.substr(1),root->left);
            }
        }
        else if(x[0]=='1')
        {
            if(root->right!=NULL)build(x.substr(1),root->right);
            else
            {
                node*p=new node;
                p->left=NULL;
                p->right=NULL;
                p->IsNumber=false;
                root->right=p;
                build(x.substr(1),root->right);
            }
        }
        else cout<<"不支持0、1以外的输入！\n";
    }
    else
    {
        if (x[0]=='0')
        {
            if(root->left!=NULL)root->left->IsNumber=true;
            else
            {
                node*p=new node;
                p->left=NULL;
                p->right=NULL;
                p->IsNumber=true;
                root->left=p;
            }
        }
        else if(x[0]=='1')
        {
            if(root->right!=NULL)root->right->IsNumber=true;
            {
                node*p=new node;
                p->left=NULL;
                p->right=NULL;
                p->IsNumber=true;
                root->right=p;
            }
        }
        else cout<<"不支持0、1以外的输入！\n";
    }
}

void print(string x,node* root)
{
    if(root->IsNumber==true)cout<<x<<endl;
    if (root->left!=NULL)print(x+"0",root->left);
    if(root->right!=NULL)print(x+"1",root->right);
}

int main()
{
    string x;
    node * head=new node;
    head->left=NULL;
    head->right=NULL;
    head->IsNumber=false;
    while(cin>>x)build(x,head);
    print("",head);
    return 0;
}
