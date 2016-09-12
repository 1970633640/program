#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#include "HugeInt.h"
int main()  //第二种多项式计算
{
    freopen ("data100.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int j,i,x;
    HugeInt ans=0;
    int * key= new int [x];
    ans=0;
    cin>>x;
    i=x-1;
    for(j=0;j<x;j++)cin>>key[j];
    while(i>=0)
    {

        ans=3 * ans;
        ans=ans + key[i];
        i--;
    }

    cout<<ans;
delete [] key;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
