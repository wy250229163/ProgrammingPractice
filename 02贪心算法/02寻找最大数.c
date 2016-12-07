#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char n[100];
		int m,i,j,max=0,maxj=-1;
		scanf("%s%d",n,&m);
		for(i=0;i<(strlen(n)-m);i++)
		{
			max=0;
			for(j=maxj+1;j<=(m+i);j++)
			{
				if(n[j]>max)
				{
					max=n[j];
					maxj=j;
				}
			}
			printf("%c",n[maxj]);
		}
		printf("\n");
	}
}