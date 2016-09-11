#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#include "HugeInt.h"
int main()  //朴素多项式计算
{
    freopen ("data100.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int i,j,x,key;
    HugeInt ans;
    HugeInt threepow;
    ans=0;
    cin>>x;

    for(i=0; i<x; i++)
    {
        cin>>key;
        threepow=1;
        for(j=0; j<i; j++)threepow=threepow*3;
        threepow=threepow*key;
        ans=ans+threepow;
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
