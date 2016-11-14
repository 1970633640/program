#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct node
{
    int value;
    node * left;
    node * right;
} node;
void insertnode(node * x,int t)
{
    while(1)
    {
        if(x->left!=NULL && t<x->value)x=x->left;
        else if(x->right!=NULL && t>=x->value)x=x->right;
        else if  (x->left==NULL && t<x->value)
        {
            node *p=new node;
            p->value=t;
            p->left=NULL;
            p->right=NULL;
            x->left=p;
            return;
        }
        else if  (x->right==NULL && t>=x->value)
        {
            node *p=new node;
            p->value=t;
            p->left=NULL;
            p->right=NULL;
            x->right=p;
            if(t==x->value)cout<<"------"<<t<<endl;
            return;
        }
        else
        {
            cout<<"unknown error!!!!\n";
            break;
        }
    }
}
void print(node * x)
{
    if(x)
    {
        print(x->left);
        printf("%d\n",x->value);
        print(x->right);
    }
}
int main()
{
    freopen("data1m.txt","r",stdin);
    freopen("excited.txt","w",stdout);
    int t,n;
    scanf("%d",&n);
    scanf("%d",&t);
    node * x=new node;
    x->value=t;
    x->left=NULL;
    x->right=NULL;
    for(int i=1; i<n; i++)
    {
        scanf("%d",&t);
        insertnode(x,t);
    }
    print(x);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
