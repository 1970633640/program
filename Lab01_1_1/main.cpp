#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()  //²åÈëÅÅÐòÉýÐòÊä³ö
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
        if(ans[i]<ans[i-1])
        {
            temp=ans[i];
            j=i;
            ans[j]=ans[j-1];
            while(j>0 && temp<ans[j])
            {
                j--;
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
