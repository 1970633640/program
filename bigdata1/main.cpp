#include <iostream>
//#include <pthread.h> //多线程相关操作头文件，可移植众多平台
#include <stdio.h>
#include <cstring>
#include<windows.h>
//#include <hash_set>
//#include <array>
#include <fstream>

using namespace std;
string query[30]; //允许最大关键词=30
char cquery[30][15]; //char版查询词
int querysum=-1; //从零开始
#define filesum 101710//元素总数钦定0~101710
const int MAXN = 20000;//钦定文件最大20000字节
//#define filesum 1000
bool ans[30][filesum];
bool ansfind[30];
char fname[48];//小文件名字

int ansfindsum;
int len;//小文件长度
int main()
{
    ifstream qin;
    qin.open("query_task1.txt");
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
        //          fseek (fin , 0 , SEEK_END);
//   len = ftell (fin);
//   rewind (fin);
//fread(buf,1,len,fin);
//buf[len]='\0';
        //  fclose(fin);

        memset(ansfind,0,sizeof(ansfind));
        ansfindsum=-1;

        while(!feof(fin))
        {
            fscanf(fin,"%s",com);
            for(int j=0; j<=querysum; ++j) //j=0-29
                if(!ansfind[j] && strcmp( com,cquery[j] )==0 )
                {
                    ans[j][i]=true;
                    ++ansfindsum;
                    ansfind[j]=true;
                    if(ansfindsum==querysum)goto eee;
                }
        }

eee:
        fclose(fin);
    }

    ofstream fout;
    fout.open("Task1.txt");
    int i,j;
    for(i=0; i<=querysum; ++i)
    {
        string qs=query[i];
        for( j=0; j<=filesum; ++j)
            if(ans[i][j])fout<<i+1<<"  report"<< j <<".xml "<<qs<<endl;
    }
    fout.close();
//delete []buf;
    return 0;
}
