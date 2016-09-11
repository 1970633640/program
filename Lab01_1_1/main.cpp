#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()  //插入排序升序输出
{
    freopen ("data1m.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int temp,key,x,i,j;
    cin>>x;
    int   *ans=new   int[x];
    for(i=0; i<x; i++)
    {
        cin>>key;
        ans[i]=key;
    }
    for(i=1; i<x; i++)
    {
        if(ans[i]<ans[i-1])   //位置不对
        {
            temp=ans[i];
            j=i;
            ans[j]=ans[j-1];
            while(j>0 && temp<ans[j])
            {
                j--;    //直到找到目标之前每个数字移动一格
                ans[j]=ans[j-1];
            }
            ans[j]=temp;
        }
    }
    for(i=0; i<x; i++)cout<<ans[i]<<endl;
    delete []ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
