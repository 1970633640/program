#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void swap(a,b)
{
    int temp=a;
    a=b;
    b=temp;
}

void quicksort(ans[],left,right)
{
    int l=left,r=right,key=ans[left];
    int m=left;









}
int main()
{
    freopen ("data1w.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int i,x,key;
    cin>>x;
    int   *ans=new   int[x];
    for(i=0; i<x; i++)
    {
        cin>>key;
        ans[i]=key;
    }

    delete []ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
