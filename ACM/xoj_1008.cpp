// Input
// Each input file contains only one non-negative integer N (0< N <= 13), the size of the chess.

// Output
// If it's impossible to place these queens, output 0.
 // Otherwise you should output the number of different solutions of placing these queens on the first line.
 // Then output one solution in following format.
 // X Y, (1<= X, Y <= N) , means these is a queen in the row X and columns Y.
 // You could output the queens in any order.
 // If these are more than one solution, any of them will got Accepted.

// Sample Input
// 4
// Sample Output
// 2
 // 1 2
 // 2 4
 // 3 1
 // 4 3


#include<stdio.h>
int x[15];
int abs(int x){
	if(x<0)
		return -x;
	else return x;
}
int place(int k)
{
	int j;
	for(j=1;j<=k-1;j++)
		if(abs(x[k]-x[j])==abs(k-j)||x[k]==x[j])
			return 0;
	return 1;
}
int main()
{
	x[1]=0;
	int y[15];
	int n;
	int k=1;
	int result=0;
	scanf("%d",&n);
	while(k>0){
		while(x[k]<=n-1){
			x[k]++;
			if(place(k)==1)
				if(k==n){
					result++;
					for(int k=1;k<=n;k++)
						y[k]=x[k];
				}
				else{
					k++;
					x[k]=0;
				}
		}
		k--;
	}
	printf("%d\n",result);
	if(result>0){
		for(int i=1;i<=n;i++){
			printf("%d %d\n",i,y[i]);
		}
	}
	return 0;
}