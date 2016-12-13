#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
typedef struct node
{
    node * child[3];
    char value;
} node;

node * T;
int sum;

node * create_tree() //建立三叉树
{
    node * p;
    node * q;
    node * ans;
    bool flag=false;
    stack <node *> ParentStack;
    char x;
    while(scanf("%c",&x) && x!='\n')
    {
        if('A'<=x && x<='Z')
        {

            if(flag==false)
            {
                p=new node;
                ans=p;
                flag=true;
                for(int i=0; i<3; ++i)p->child[i]=NULL;
            }
            p->value=x;

        }
        else if(x=='(')
        {
            for(int i=0; i<3; ++i)if(p->child[i]==NULL)
                {
                    ParentStack.push(p);
                    q=new node;
                    p->child[i]=q;
                    for(int j=0; j<3; ++j)q->child[j]=NULL;
                    p=q;
                    break;
                }
        }
        else if (x==')')
        {
            p=ParentStack.top();
            ParentStack.pop();
        }
        else if(x==',')
        {
            p=ParentStack.top();
            for(int i=0; i<3; ++i)if(p->child[i]==NULL)
                {
                    q=new node;
                    p->child[i]=q;
                    for(int j=0; j<3; ++j)q->child[j]=NULL;
                    p=q;
                    break;
                }
        }
    }
    return ans;
}

void r_preorder(node * root)
{
    printf("%c",root->value);
    for(int i=0; i<3; ++i)
        if(root->child[i]!=NULL)r_preorder(root->child[i]);
}

void s_preorder(node * root)
{
    stack <node *> STACK;
    node * p;
    STACK.push(root);
    while(!STACK.empty())
    {
        p=STACK.top();
        STACK.pop();
        printf("%c",p->value);
        for(int i=2; i>=0; --i)if(p->child[i]!=NULL)STACK.push(p->child[i]);
    }
}
void count2(node * root)
{
    ++sum;
    for(int i=0; i<3; ++i)if(root->child[i]!=NULL)count2(root->child[i]);
}

void count(node * root)
{
    sum=0;
    count2(root);
    printf("%d\n",sum);
}

int main()
{
    T=create_tree();
    r_preorder(T);
    printf("\n");
    s_preorder(T);
    printf("\n");
    count(T);
    return 0;
}
