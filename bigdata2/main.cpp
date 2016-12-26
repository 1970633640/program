#include <iostream>
//#include <pthread.h> //多线程相关操作头文件，可移植众多平台
#include <stdio.h>
#include <cstring>
#include<windows.h>
//#include <hash_set>
//#include <array>
#include <fstream>

using namespace std;
string query[30][2]; //允许最大关键词=30
char cquery[30][2][15]; //char版查询词
int querysum=-1; //从零开始
#define filesum 101710//元素总数钦定0~101710
const int MAXN = 20000;//钦定文件最大20000字节
//#define filesum 1000
bool ans[30][filesum][2];
bool ansfind[30][2];
char fname[48];//小文件名字

int ansfindsum;
int len;//小文件长度
int main()
{
    ifstream qin;
    qin.open("query_task2.txt");
    string x,x2;
    while(qin>>x)
    {
        query[++querysum][0]=x;
        strcpy(cquery[querysum][0],query[querysum][0].c_str());
        qin>>x2;
        query[querysum][1]=x2;
        strcpy(cquery[querysum][1],query[querysum][1].c_str());
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
        if(fin==NULL) printf("ERROR!\n");


        memset(ansfind,0,sizeof(ansfind));
        ansfindsum=-1;

        while(!feof(fin))
        {
            fscanf(fin,"%s",com);
            for(int j=0; j<=querysum; ++j) //j=0-29
                if(!ansfind[j][0] && strcmp( com,cquery[j][0] )==0 )
                {
                    ans[j][i][0]=true;
                    ++ansfindsum;
                    ansfind[j][0]=true;
                    if(ansfindsum==querysum*2)goto eee;
                }

            for(int j=0; j<=querysum; ++j) //j=0-29
                if(!ansfind[j][1] && strcmp( com,cquery[j][1] )==0 )
                {
                    ans[j][i][1]=true;
                    ++ansfindsum;
                    ansfind[j][1]=true;
                    if(ansfindsum==querysum*2)goto eee;
                }

        }

eee:
        fclose(fin);
    }

    ofstream fout;
    fout.open("Task2.txt");
    int i,j;
    for(i=0; i<=querysum; ++i)
    {
        string qs=query[i][0],qs2=query[i][1];
        for( j=0; j<=filesum; ++j)
            if(ans[i][j][0] && ans[i][j][1] )fout<<i+1<<"  report"<< j <<".xml "<<qs<<" "<<qs2<<endl;
        for( j=0; j<=filesum; ++j)
        {

            if(ans[i][j][0] && !ans[i][j][1] )fout<<i+1<<"  report"<< j <<".xml "<<qs<<endl;
            if(ans[i][j][1] && !ans[i][j][0] )fout<<i+1<<"  report"<< j <<".xml "<<qs2<<endl;
        }
    }


    fout.close();
//delete []buf;
    return 0;
}
