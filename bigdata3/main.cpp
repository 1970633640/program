#include <iostream>
#include <stdio.h>
#include <cstring>
#include<windows.h>
#include <fstream>

using namespace std;
string query[30]; //允许最大关键词=30
char cquery[30][15]; //char版查询词
int querysum=-1; //从零开始
#define filesum 101710//元素总数钦定0~101710
const int MAXN = 20000;//钦定文件最大20000字节
//#define filesum 1000
int ans[30][filesum];
char fname[48];//小文件名字
typedef struct node
{
  //  char astr[15];
    int times;
    int filenum;
}node;
int ansfindsum;
int len;//小文件长度
node ansnode[30][30000];
int cmp(const void * a,const void * b)
{
    if(   (*(node *)b).times != (*(node *)a).times )
        return  (*(node *)b).times - (*(node *)a).times;
    else return  (*(node *)a).filenum-(*(node *)b).filenum;
}


int main()
{
    ifstream qin;
    qin.open("query_task3.txt");
    string x;

    while(qin>>x)
    {
        query[++querysum]=x;
        strcpy(cquery[querysum],query[querysum].c_str());
    }
//cout<<"all-1="<<querysum;
    memset(ans,0,sizeof(ans));
    FILE* fin;
//char* buf=new char[MAXN];//文件所有字符
    char com[30];
    for(int i=0; i<=filesum; ++i)
    {
        if(i%10000==0)printf("%d\n",i);
        sprintf(fname,"D:\\program\\bigdata\\processed\\report%d.xml",i);
        //  printf("%s\n",fname);
        fin=fopen(fname,"rb");
        if(fin==NULL) printf("NULL\n");




        while(!feof(fin))
        {
            fscanf(fin,"%s",com);
            for(int j=0; j<=querysum; ++j) //j=0-29
                if( strcmp( com,cquery[j] )==0 )
                {
                    ++ans[j][i];
                }
        }

fclose(fin);
    }
int sum2;
    ofstream fout;
    fout.open("Task3.txt");
    int i,j;
    for(i=0; i<=querysum; ++i)
    {sum2=-1;
        for( j=0; j<=filesum; ++j)
            if(ans[i][j]){ansnode[i][++sum2].times=ans[i][j];ansnode[i][sum2].filenum=j;  }
            qsort(ansnode[i],sum2+1,sizeof(ansnode[i][0]),cmp);
            int sum1=0;
            for(int k=0;k<=sum2;++k)
                fout<<i+1<<" report" <<ansnode[i][k].filenum<<".xml "<<++sum1<<" "<<query[i]<<endl;
    }
    fout.close();
//delete []buf;
    return 0;
}
