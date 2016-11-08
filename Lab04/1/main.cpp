#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
using namespace std;
typedef struct node
{
    string data;
    node* next;
} node;
node *x[475256];
void insertnode(int a,string b)
{
    node * p1;
    p1=x[a];
    if(x[a]->data=="")
    {
        x[a]->data=b;
        x[a]->next=NULL;
    }
    else
    {
        node* p2=new node;
        while(p1->next!=NULL)p1=p1->next;
        p1->next=p2;
        p2->data=b;
        p2->next=NULL;
    }
}

int getascii(char a)
{
    if('a'<=a && a<='z')return (int)(a-'a'+1);
    else return 0;
}

void judge (string a)
{
    int l=a.length();
    int key;
    if(l>=4)key=getascii(a[a.length()-1])+getascii(a[a.length()-2])*26+getascii(a[a.length()-3])*676+getascii(a[a.length()-4])*17576;
    else if(l==3)key=getascii(a[a.length()-1])+getascii(a[a.length()-2])*26+getascii(a[a.length()-3])*676;
    else if(l==2)key=getascii(a[a.length()-1])+getascii(a[a.length()-2])*26;
    else key=getascii(a[a.length()-1]);
    node *p=x[key];
    while(1)
    {
        if(p->data==a) return;
        else if(p->next==NULL)break;
        else p=p->next;
    }
    cout<<a<<endl;
}

string word(string a)
{
    transform(a.begin(), a.end(), a.begin(), (int (*)(int))tolower);
    char ans[20];
    int l=0;
    for(int i=0; i<a.length(); i++)
    {
        if( (a[i]<='z' && a[i]>='a') || (a[i]=='-' && l!=0))
        {
            ans[l]=a[i];
            ++l;
        }
    }
    ans[l]='\0';
    return ans;
}

int main()
{
    fstream file1("dictionary.txt");   // 2~16 characters
    string a;
    for(int i=0; i<=475255; ++i)
    {
        // node *p=(node*)malloc(sizeof(node));   //结构体中含有string类型只能用new不能用malloc
        node*p=new node;
        p->data="";
        p->next=NULL;
        x[i]=p;
    }
    while(getline(file1,a))
    {
        int l=a.length();
        if (l>=4)insertnode(getascii(a[a.length()-1])+getascii(a[a.length()-2])*26+getascii(a[a.length()-3])*676+getascii(a[a.length()-4])*17576,a);
        else if(l==3)insertnode(getascii(a[a.length()-1])+getascii(a[a.length()-2])*26+getascii(a[a.length()-3])*676,a);
        else if(l==2)insertnode(getascii(a[a.length()-1])+getascii(a[a.length()-2])*26,a);
        else continue;
    }
    file1.close();
    ifstream file2 ("paper.txt");
    while(file2>>a)
    {
        judge(word(a));
    }
    file2.close();
    return 0;
}
