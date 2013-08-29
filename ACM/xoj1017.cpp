#include<stdio.h>
int N,tile;
int Board[1035][1035];
void TileBoard(int tr,int tc,int dr,int dc,int size);
int main()
{
	int r,c,size=1,i,j;
	scanf("%d",&N);
	scanf("%d%d",&r,&c);
	for(i=1;i<=N;i++)
		size*=2;
	tile=0;
	TileBoard(1,1,r,c,size);
	for(i=1;i<=size;i++){
		for(j=1;j<=size;j++)
			printf("%d ",Board[i][j]);
		printf("\n");
	}
	return 0;
}

void TileBoard(int tr,int tc,int dr,int dc,int size)
{
	int t,s;
	if(size==1) return;
	tile++;
	t=tile;
	s=size/2;
	if(dr<tr+s&&dc<tc+s)
		TileBoard(tr,tc,dr,dc,s);
	else{
		Board[tr+s-1][tc+s-1]=t;
		TileBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	if(dr<tr+s&&dc>=tc+s)
		TileBoard(tr,tc+s,dr,dc,s);
	else{
		Board[tr+s-1][tc+s]=t;
		TileBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	if(dr>=tr+s&&dc<tc+s)
		TileBoard(tr+s,tc,dr,dc,s);
	else{
		Board[tr+s][tc+s-1]=t;
		TileBoard(tr+s,tc,tr+s,tc+s-1,s);
	}
	if(dr>=tr+s&&dc>=tc+s)
		TileBoard(tr+s,tc+s,dr,dc,s);
	else{
		Board[tr+s][tc+s]=t;
		TileBoard(tr+s,tc+s,tr+s,tc+s,s);
	}
}