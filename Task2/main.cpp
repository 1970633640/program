#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;
const int maxn=2005;
const int mod=195709;
#define len 20
#define filenum 101710
int flag=0;
int num[200000];
int Hash(char *str){
    int ans=0;
    for(int i=0;i<strlen(str);i++){
        ans=((str[i]-'a'?(str[i]-'a'+26):(str[i]-'A'))+ans*3)%mod;
    }
    return ans;
}
FILE *fout;
typedef struct Vec{
    char s[filenum+10][80];
    int size;
    Vec(){
        memset(s,0,sizeof(s));
        size=0;
    }
    void insert(char *str){
        if(size>=1&&strcmp(str,s[size-1])==0){
            return ;
        }
        int n=strlen(str);
        for(int i=0;i<n;i++){
            s[size][i]=str[i];
        }
        size++;
        // printf("%d\n",size);
    }
    void print(){
        for(int i=0;i<size;i++){
            fprintf(fout,"%s\n",s[i]);
        }
    }
}vec;
vec simplename[30];
vec bothname[30];
int main(int argc, char const *argv[])
{
    char s1[len],s2[len],str[len];
    char fname[1000];
    FILE *fin;
    fin=fopen("query_task2.txt","r");
    int i,n,m,cnt;
    int fre=0;
    int linenum=0;
    fscanf(fin,"%d",&linenum);
    cnt=1;
    set<int>con;
    for(int i=1;i<=linenum;i++){
            printf("%d\n",i);
    	fscanf(fin,"%s %s",s1,s2);
    	n=Hash(s1),m=Hash(s2);
//    	printf("%d %d\n",n,m);
    	con.insert(n);
    	con.insert(m);
    	num[n]=cnt++;
    	num[m]=cnt++;
//    	printf("%d %d\n",num[n],num[m]);
    }
    printf("%d\n",con.size());
    fclose(fin);
    char tmp[80];
    int word[60];
    for(int i=0;i<=filenum;i++){
        // if(i%10000==0) printf("%d\n",i);
        sprintf(fname,"D:\\program\\bigdata\\processed\\report%d.xml",i);
        // printf("%s\n",fname);
        fin=fopen(fname,"r");
        cnt=0;
        memset(word,0,sizeof(word));
        memset(tmp,0,sizeof(tmp));
        if(fin==NULL) printf("%d\n",i);
        while(fscanf(fin,"%s",tmp)!=EOF){
        	n=Hash(tmp);
//        	printf("%s %d\n",tmp,n);
        	if(num[n]){
        		// printf("%d %d\n",n,num[n]);
        		word[num[n]]++;
        	}
        }
        for(int i=1;i<=60;i+=2){
        	if(word[i]&&word[i+1]){
        		bothname[i/2].insert(fname);
        	}
        	else if(word[i]||word[i+1]){
        		simplename[i/2].insert(fname);
        	}
        }
        fclose(fin);
    }
    fout=fopen("task2.txt","w");
    for(int i=0;i<30;i++){
        // printf("%d\n",i);
        // fprintf(fout,"%d\n",i);
        bothname[i].print();
        simplename[i].print();
    }
    printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
