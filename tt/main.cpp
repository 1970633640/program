#include <iostream>
#include <set>
using namespace std;

int main()
{
    string x;
    set <string> t;
    while(cin>>x)t.insert(x);
    cout<<t.size();
    return 0;
}
