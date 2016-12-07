#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n,m;
	int num[200];
	int min;
	int A,B,C;
	int i;
	scanf("%d",&n);
	while(n--)
	{
		memset(num, 0, sizeof(num));
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d%d",&A,&B,&C);
			for(i=B;i<B+C;i++)
				num[i]+=A;
		}
		min=0;
		for(i=0;i<200;i++)
		{
			if(num[i]>min)
				min=num[i];
		}
		printf("%d\n",min);
	}
}
