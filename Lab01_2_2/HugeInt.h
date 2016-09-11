#ifndef HUGEINT_H_INCLUDED
#define HUGEINT_H_INCLUDED
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <string.h>
#include <typeinfo>
#include <strstream>
using namespace std;
class HugeInt
{
private:
    string num;
public:
    HugeInt(string a=""):num(a) {}
    HugeInt(long long int a);
    ~HugeInt() {}
    void operator*=(long int a);
    HugeInt operator*=(HugeInt &a);
    HugeInt operator+=(HugeInt &a);
    HugeInt operator-=(HugeInt &a);
    void in(string &a);
    void print();
    string visit();
    int digit();
};
int judge(const string &a,const string &b);
string add(string &s1,string &s2);
string div(string &s1,string &s2);
string multi(string &s1,string &s2);
string multi(string &s1,string &s2)
{
    int n1=s1.length(),n2=s2.length(),i,j,k,flag;
    int *n;
    k=n1+n2-2;
    n=new int[n1+n2];
    for(i=0; i<n1+n2; i++)
        n[i]=0;
    for(i=0; i<n1; i++)
        for(j=0; j<n2; j++)
            n[k-i-j]+=(s1[i]-'0')*(s2[j]-'0');
    for(i=0,flag=0; i<n1+n2; i++)
    {
        n[i]+=flag;
        flag=n[i]/10;
        n[i]%=10;
    }
    i=n1+n2-1;
    while(n[i]==0) i--;
    if(i<0) return "0";
    string s;
    while(i>=0)
        s+=n[i--]+'0';
    delete []n;
    return s;
}
HugeInt operator*(HugeInt a,HugeInt b)
{
    string s1=a.visit(),s2=b.visit();
    string t,ans;
    int i;
    if(s1[0]!='-'&&s2[0]!='-')
        ans=multi(s1,s2);
    else if(s1[0]=='-'&&s2[0]!='-')
    {
        string tmp;
        for(i=1; i<s1.length(); i++)
            tmp+=s1[i];
        t=multi(tmp,s2);
        ans='-'+t;
    }
    else if(s1[0]!='-'&&s2[0]=='-')
    {
        string tmp;
        for(i=1; i<s2.length(); i++)
            tmp+=s2[i];
        t=multi(tmp,s1);
        ans='-'+t;
    }
    else
    {
        string tmp1,tmp2;
        for(i=1; i<s1.length(); i++)
            tmp1+=s1[i];
        for(i=1; i<s2.length(); i++)
            tmp2+=s2[i];
        ans=multi(tmp1,tmp2);
    }
    HugeInt x(ans);
    return x;
}
void HugeInt::operator*=(long int a)
{
    string s;
    strstream sin;
    sin<<a;
    sin>>s;
    HugeInt x(s);
    *this=(*this)*x;
}
HugeInt operator+(HugeInt &a,HugeInt &b)
{
    string s1=a.visit();
    string s2=b.visit();
    int n1=s1.length(),n2=s2.length(),i;
    string t,ans;
    if(s1[0]!='-'&&s2[0]!='-')
        ans=add(s1,s2);
    else if(s1[0]=='-'&&s2[0]!='-')
    {
        string tmp;
        for(i=1; i<n1; i++)
            tmp+=s1[i];
        if(judge(tmp,s2)==1)
        {
            t=div(tmp,s2);
            ans='-'+t;
        }
        else if(tmp==s2)
            ans="0";
        else
            ans=div(s2,tmp);
    }
    else if(s1[0]!='-'&&s2[0]=='-')
    {
        string tmp;
        for(i=1; i<n2; i++)
            tmp+=s2[i];
        if(judge(s1,tmp))
            ans=div(s1,tmp);
        else if(s1==tmp)
            ans="0";
        else
        {
            t=div(tmp,s1);
            ans='-'+t;
        }
    }
    else
    {
        string tmp1,tmp2;
        for(i=1; i<n1; i++)
            tmp1+=s1[i];
        for(i=1; i<n2; i++)
            tmp2+=s2[i];
        t=add(tmp1,tmp2);
        ans='-'+t;
    }
    HugeInt x(ans);
    return x;
}
HugeInt operator+(HugeInt &a,long long int b)
{
    string s1=a.visit(),s2;
    strstream s;
    s<<b;
    s>>s2;
    HugeInt x(s2);
    HugeInt ans=a+x;
    return ans;
}
HugeInt operator+(HugeInt &a,string s2)
{
    HugeInt x(s2),ans;
    ans=a+x;
    return ans;
}
HugeInt operator*(long long int b,HugeInt &a)
{
    string s2;
    strstream s;
    s<<b;
    s>>s2;
    HugeInt x(s2),ans;
    ans=x*a;
    return ans;
}
HugeInt operator*(HugeInt &a,long int b)
{
    string s2;
    strstream s;
    s<<b;
    s>>s2;
    HugeInt x(s2),ans;
    ans=x*a;
    return ans;
}
HugeInt operator-(HugeInt &a,HugeInt &b)
{
    string s1=a.visit();
    string s2=b.visit();
    int n1=s1.length(),n2=s2.length(),i;
    string t,ans;
    if(s1[0]!='-'&&s2[0]!='-')
    {
        if(judge(s1,s2)==1)
            ans=div(s1,s2);
        else if(s1==s2)
            ans="0";
        else
        {
            t=div(s2,s1);
            ans='-'+t;
        }
    }
    else if(s1[0]=='-'&&s2[0]!='-')
    {
        string tmp;
        for(i=1; i<n1; i++)
            tmp+=s1[i];
        t=add(tmp,s2);
        ans='-'+t;
    }
    else if(s1[0]!='-'&&s2[0]=='-')
    {
        string tmp;
        for(i=1; i<n2; i++)
            tmp+=s2[i];
        ans=add(s1,tmp);
    }
    else
    {
        string tmp1,tmp2;
        for(i=1; i<n1; i++)
            tmp1+=s1[i];
        for(i=1; i<n2; i++)
            tmp2+=s2[i];
        if(judge(tmp1,tmp2)==-1)
            ans=div(tmp2,tmp1);
        else if(tmp1==tmp2)
            ans="0";
        else
        {
            t=div(tmp1,tmp2);
            ans='-'+t;
        }
    }
    HugeInt x(ans);
    return x;
}
int judge(const string &a,const string &b)
{
    int n1=a.length(),n2=b.length(),i;
    if(n1>n2) return 1;
    else if(n1<n2) return -1;
    else
    {
        for(i=0; i<n1; i++)
        {
            if(a[i]==b[i]) continue;
            else if(a[i]<b[i]) return -1;
            else return 1;
        }
    }
    return 0;
}
string add(string &s1,string &s2)
{
    int n1,n2,i,j,t,flag=0;
    string tmp;
    n1=s1.length();
    n2=s2.length();
    for(i=n1-1,j=n2-1,flag=0; i>=0||j>=0; i--,j--)
    {
        t=0;
        if(i>=0)
            t+=s1[i]-'0';
        if(j>=0)
            t+=s2[j]-'0';
        if(t+flag>=10)
        {
            tmp+=t+flag-10+'0';
            flag=1;
        }
        else
        {
            tmp+=t+flag+'0';
            flag=0;
        }
    }
    if(flag>0)
        tmp+='1';
    string tmp2;
    n1=tmp.length();
    for(i=n1-1; i>=0; i--)
        tmp2+=tmp[i];
    return tmp2;
}
string div(string &s1,string &s2)
{
    int n1,n2,i,j,t=0,flag=0;
    string tmp;
    n1=s1.length();
    n2=s2.length();
    for(i=n1-1,j=n2-1; i>=0||j>=0; i--,j--)
    {
        t=0;
        if(i>=0)
            t+=(s1[i]-'0');
        if(j>=0)
            t=t-(s2[j]-'0');
        if(t+flag>=0)
        {
            tmp+=t+flag+'0';
            flag=0;
        }
        else
        {
            tmp+=10+t+flag+'0';
            flag=-1;
        }
    }
    string tmp2;
    n1=tmp.length();
    for(i=n1-1; i>=0; i--)
        tmp2+=tmp[i];
    return tmp2;
}
string HugeInt::visit()
{
    return num;
}
int HugeInt::digit()
{
    if(num[0]!='-')
        return num.length();
    else
        return num.length()-1;
}
void HugeInt::print()
{
    cout<<num<<"("<<digit()<<"digits)";
}
HugeInt::HugeInt(long long int a)
{
    strstream x;
    x<<a;
    x>>num;
}
void HugeInt::in(string &a)
{
    num=a;
}
ostream& operator<<(ostream &s,HugeInt a)
{
    a.print();
    return s;
}
istream& operator>>(istream &s,HugeInt &a)
{
    string b;
    s>>b;
    a.in(b);
    return s;
}
HugeInt operator ""HL(const char* a)
{
    string b=a;
    HugeInt x(b);
    return x;
}
HugeInt operator*(string &s1,string &s2)
{
    HugeInt a(s1),b(s2),ans;
    ans=a*b;
    return ans;
}
#endif // HUGEINT_H_INCLUDED
