#include<stdio.h>   
#include<string.h>   
#define M 1000   
int main()   
{   
   int an1[M+3];   
   int an2[M+3];   
   char szline1[M+3],szline2[M+3];   
   int i,j,len1,len2;   
   scanf("%s",szline1);   
   scanf("%s",szline2);   
   memset(an1,0,sizeof(an1));   
   memset(an2,0,sizeof(an2));   
   len1=strlen(szline1);   
   j=0;   
   for(i=len1-1;i>=0;i--)   
      an1[j++]=szline1[i]-'0';   
   len2=strlen(szline2);   
   j=0;   
   for(i=len2-1;i>=0;i--)   
      an2[j++]=szline2[i]-'0';   
   for(i=0;i<M;i++)   
   {   
      an1[i]=an1[i]+an2[i];   
      if(an1[i]>9)   
      {   
         an1[i]-=10;   
         an1[i+1]++;   
       }   
    }   
    j=0;   
    for(i=M;i>=0;i--)   
    {   
       if(j)   
          printf("%d",an1[i]);   
       else if(an1[i])   
       {   
          printf("%d",an1[i]);   
          j=1;   
       }   
    }     
    return 0;   
}