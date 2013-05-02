// Description
// Consider the number triangle shown below. Write a program that calculates
// the highest sum of numbers that can be passed on a route that starts at the
// top and ends somewhere on the base. Each step can go either diagonally down
// to the left or diagonally down to the right.
// 7
// 3 8
// 8 1 0
// 2 7 4 4
// 4 5 2 6 5
// In the sample above, the route from 7 to 3 to 8 to 7 to 5 produces the
// highest sum: 30.
 
// Input
// The first line contains R (1 <= R <= 1000), the number of rows. Each 
// subsequent line contains the integers for that particular row of the
// triangle. All the supplied integers are non-negative and no larger than 100.
// Output
// A single line containing the largest sum using the traversal specified.
// Sample Input
// 5
// 7
// 3 8
// 8 1 0
// 2 7 4 4
// 4 5 2 6 5
// Sample Output
// 30

#include<stdio.h>
int T[1001][1001],a[1001][1001];
int max(int a,int b)
{
	if(a>b)
		return a;
	else return b;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	}
	for(j=1;j<=n;j++)
		T[n][j]=a[n][j];
	for(i=n-1;i>=1;i--)
		for(j=1;j<=i;j++)
			T[i][j]=max(T[i+1][j],T[i+1][j+1])+a[i][j];
	printf("%d",T[1][1]);
	return 0;
}