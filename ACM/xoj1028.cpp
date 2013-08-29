#include <stdio.h>
int m[1001],v[8194],b[1001][8193],rec[1001];
int vs[1001][8193];
int N,M,count;

int PrintItem(int j,int w)
{
     if(j==0||w==0) return 0;
     if(b[j][w]==-1){
		PrintItem(j-1,w-m[j]);
        rec[++count]=j;
       }
     else PrintItem(j-1,w);
}

int main()
{
    int i,mi;
    scanf("%d",&N);
    scanf("%d",&M);
    for(i=1;i<=N;i++)
      scanf("%d",&m[i]);
    for(i=1;i<=N;i++)
      scanf("%d",&v[i]);

    for(mi=0;mi<=m[1]-1;mi++) vs[1][mi]=0;
	if (v[1]>0)////////////
		for(mi=m[1];mi<=M;mi++)
		{
			vs[1][mi]=v[1];
			b[1][mi]=-1;/////////////
		}
    for(i=2;i<=N;i++)
      for(mi=0;mi<=M;mi++)
        if(m[i]>mi){
                    vs[i][mi]=vs[i-1][mi];
                    b[i][mi]=1;
                    }
        else if(vs[i-1][mi]>vs[i-1][mi-m[i]]+v[i]){
             vs[i][mi]=vs[i-1][mi];
             b[i][mi]=1;
             }
        else{
             vs[i][mi]=vs[i-1][mi-m[i]]+v[i];
             b[i][mi]=-1;
             }
    PrintItem(N,M);
    printf("%d\n",count);
    for(i=1;i<=count;i++) printf("%d ",rec[i]);
    return 0;
} 
