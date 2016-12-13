#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
typedef struct node
{
    node * child[4];
    char value;
} node;

typedef struct node2
{
    node2* lchild;
    node2* rchild;
    char value;
}node2;

node * T[3];node2 * TT;
int sum;
char x;
node * create_tree() //建立四叉树
{
    node * p;
    node * q;
    node * ans;
    bool flag=false;
    stack <node *> ParentStack;
    while(scanf("%c",&x)  && x!='\n' && x!=' ' )
    {
        if('A'<=x && x<='Z')
        {

            if(flag==false)
            {
                p=new node;
                ans=p;
                flag=true;
                for(int i=0; i<4; ++i)p->child[i]=NULL;
            }
            p->value=x;

        }
        else if(x=='(')
        {
            for(int i=0; i<4; ++i)if(p->child[i]==NULL)
                {
                    ParentStack.push(p);
                    q=new node;
                    p->child[i]=q;
                    for(int j=0; j<4; ++j)q->child[j]=NULL;
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
            for(int i=0; i<4; ++i)if(p->child[i]==NULL)
                {
                    q=new node;
                    p->child[i]=q;
                    for(int j=0; j<4; ++j)q->child[j]=NULL;
                    p=q;
                    break;
                }
        }
    }
    return ans;
}
node2 * beta(node * p ,node * q,node * r,node * s)
{
node2 * t;
if(p==NULL)return NULL;
t=new node2;
t->value=p->value;
t->lchild=beta(p->child[0],p->child[1],p->child[2],p->child[3]);
t->rchild=beta(q,r,s,NULL);
return t;
}

void s_midorder(node2 * root)
{
    stack <node2*> STACK;node2 * p=root;
    while(!STACK.empty() ||p)
    {
while(p!=NULL)
{
    STACK.push(p);
    p=p->lchild;
}
p=STACK.top();STACK.pop();
printf("%c",p->value);
p=p->rchild;
    }
}

void s_posorder(node2 * root)
{
    stack <node2*> stack1,stack2;
    node2 * p;
stack1.push(root);
while(!stack1.empty())
{
    p=stack1.top();stack1.pop();
    stack2.push(p);
    if(p->lchild!=NULL)stack1.push(p->lchild);
     if(p->rchild!=NULL)stack1.push(p->rchild);
}
while(!stack2.empty())
{
    printf("%c",stack2.top()->value);stack2.pop();

}
}


int main()
{
   for(int i=0;i<3;++i)
 {
   T[i]=create_tree();if(x=='\n')break;
   }
    TT=beta(T[0],T[1],T[2],T[3]);

    s_midorder(TT);
    printf("\n");
s_posorder(TT);
    return 0;
}
