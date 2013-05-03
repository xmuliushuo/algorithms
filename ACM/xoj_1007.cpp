// Description
// Calculate a*b
// Input
// Two integer a,b (0<=a,b<=101000)
// Output
// Output a * b
// Sample Input
// 5 7
// Sample Output
// 35

#include<stdio.h>
#include<string.h>

int main()
{
	int an1[1003]={0};      
	int an2[1003]={0};
	int result[2003]={0};
	char szline1[1001],szline2[1001];      
	int i,j,len1,len2,temp;      
	scanf("%s",szline1);      
	scanf("%s",szline2);           
	len1=strlen(szline1);  
	j=0;
	for(i=len1-1;i>=0;i--)      
		an1[j++]=szline1[i]-'0';
	len2=strlen(szline2);
	j=0;
	for(i=len2-1;i>=0;i--)      
		an2[j++]=szline2[i]-'0';
	for(i=0;i<len2;i++)
		for(j=0;j<len1;j++)
			result[j+i]+=an1[j]*an2[i];
	for(i=0;i<2000;i++){
		temp=result[i]%10;
		result[i+1]+=result[i]/10;
		result[i]=temp;
	}
	int tag=0;
	for(i=2002;i>=0;i--){
		if(result[i]!=0){
			tag=i;
			break;
		}
	}
	for(i=tag;i>=0;i--)
		printf("%d",result[i]);
	return 0;
}