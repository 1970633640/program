#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <queue>
using namespace std;
typedef struct node
{
    char value;
    node* lchild;node * rchild;
}node;

struct Node2
{
    char value;
    Node2 *lchild, *rchild;
    bool isThreaded;
};

void populateQueue(Node2 *root, std::queue <Node2 *> *q)
{
    if (root == NULL) return;
    if (root->lchild)
        populateQueue(root->lchild, q);
    q->push(root);
    if (root->rchild)
        populateQueue(root->rchild, q);
}

void createThreadedUtil(Node2 *root, std::queue <Node2 *> *q)
{
    if (root == NULL) return;
    if (root->lchild)
        createThreadedUtil(root->lchild, q);
    q->pop();
    if (root->rchild)
        createThreadedUtil(root->rchild, q);
    else
    {
        root->rchild = q->front();
        root->isThreaded = true;
    }
}

void createThreaded(Node2 *root)
{
    std::queue <Node2 *> q;
    populateQueue(root, &q);
    createThreadedUtil(root, &q);
}

Node2 *leftMost(Node2 *root)
{
    while (root != NULL && root->lchild != NULL)
        root = root->lchild;
    return root;
}

void inOrder(Node2 *root)
{
    if (root == NULL) return;
    Node2 *cur = leftMost(root);
    while (cur != NULL)
    {
        cout << cur->value << " ";
        if (cur->isThreaded)
            cur = cur->rchild;
        else
            cur = leftMost(cur->rchild);
    }
}

Node2 *newNode2(int value)
{
    Node2 *temp = new Node2;
    temp->lchild = temp->rchild = NULL;
    temp->value = value;
    return temp;
}


void s_posorder(node * root)
{
    stack <node*> stack1,stack2;
    node * p;
    stack1.push(root);
    while(!stack1.empty())
    {
        p=stack1.top();
        stack1.pop();
        stack2.push(p);
        if(p->lchild!=NULL)stack1.push(p->lchild);
        if(p->rchild!=NULL)stack1.push(p->rchild);
    }
    while(!stack2.empty())
    {
        printf("%c",stack2.top()->value);
        stack2.pop();
    }
}

node * create_binary_tree(string a,string b)
{if(b=="")return NULL;
node * p =new node;
for(int i=0;i<a.length();++i)
{
    int c=b.find(a[i]);
    if(c!=string::npos)
    {
        p->value=a[i];
        p->lchild=create_binary_tree(a,b.substr(0,c));
        p->rchild=create_binary_tree(a,b.substr(c+1));
        break;
    }
}
return p;
}

Node2 * copy(node * t)
{
    if(t==NULL)return NULL;
    else
    {
        Node2 * p=new Node2;
        p->value=t->value;
        p->lchild=copy(t->lchild);
        p->rchild=copy(t->rchild);
        return p;
    }
}

int main()
{
   string a,b;
   cin>>a>>b;
   node * t=create_binary_tree(a,b);
   s_posorder(t);
   Node2 * t0=copy(t);
   createThreaded(t0);
    return 0;
}
