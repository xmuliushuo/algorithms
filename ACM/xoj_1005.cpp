// 1005.Complete Permutation 

// Time Limit: 3000 MS         Memory Limit: 65536 K 

// Description
// Generate the complete permutation of  1..N

// Input
// Each input file contains only one non-negative integer N (0< N < 9)

// Output
// Output N! Lines, according to lexicographic order.

// Sample Input
// 3

// Sample Output

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

#include<stdio.h>
int n;
void perm(int m);
int p[10];
int main()
{
	int i;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
		p[i]=i;
	perm(1);
	return 0;
}

void perm(int m)
{
	if(m==n){
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		printf("\n");
	}
	else{
		for(int j=m;j<=n;j++){
			int temp;
			temp=p[m];
			p[m]=p[j];
			if(j>m){
				for(int k=j;k>m;k--)
					p[k]=p[k-1];
				p[m+1]=temp;
			}
			perm(m+1);
			temp=p[m+1];
			if(j>m){
				for(int t=m+1;t<=j;t++)
					p[t]=p[t+1];
				p[j]=temp;
				temp=p[m];
				p[m]=p[j];
				p[j]=temp;
			}
		}
	}
}