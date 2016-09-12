#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#include "HugeInt.h"
int main()  //朴素多项式计算
{
    freopen ("data100.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int i,x;
    HugeInt ans=0;
HugeInt key;
    ans=0;
    cin>>x;
i=x-1;
  while(i>=0)
    {
        cin>>key;
ans=3*ans;
ans=key+ans;
i--;
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
