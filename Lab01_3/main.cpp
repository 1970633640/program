#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int nixudui;
void combine (int ans[],int left,int mid,int  right,int before[])  //合并
{
    int l=left,l2=mid+1,count=0;
    while(l<=mid && l2<=right)  //两边合并
    {
        if (ans[l]<=ans[l2])
        {
            before[count]=ans[l];
            l++;
            count++;
        }
        else
        {
            before[count]=ans[l2];
            l2++;
            count++;
            nixudui+=mid-l+1;   //左边一堆大于等于a[l]的数字都比a[l2]大，类似1到2有（2-1+1）个数字
        }
    }
    while(l<=mid)  //剩下的肯定是已经排好的
    {
        before[count]=ans[l];
        l++;
        count++;
    }
    while(l2<=right)   //剩下的肯定是已经排好的
    {
        before[count]=ans[l2];
        l2++;
        count++;

    }
    int i;
    for(i=0; i<count; i++)ans[left + i] = before[i];

}

void separate (int ans[],int left,int  right,int after[])  //拆
{
    if (left!=right)
    {
        int mid=(left+right)/2;
        separate(ans,left,mid,after);   //递归左边
        separate(ans,mid+1,right,after);  //递归右边
        combine(ans,left,mid,right,after);  //两边合并

    }
}
int main()  //归并排序
{
    nixudui=0;
    freopen ("data.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int temp,key,x,i,j;
    cin>>x;
    int   *ans=new   int[x];
    int   *after=new   int[x];
    for(i=0; i<x; i++)
    {
        cin>>key;
        ans[i]=key;
    }
    separate(ans,0,x-1,after);
   cout<<nixudui;
    delete []ans;
    delete []after;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
