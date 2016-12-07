#include<stdio.h>
#include<string.h>

int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int n;
		scanf("%d",&n);
		int i;
		int A[n];
		int tempMax[n+1];
		int isAllNegativeflag=0;
		memset(A,0,sizeof(A));
		memset(tempMax,0,sizeof(tempMax));
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		for(i=0;i<n;i++)
			if(A[i]>0)
				break;
		if(i==n)
			isAllNegativeflag=1;
		int max;
		if(!isAllNegativeflag)
		{
			for(i=1;i<=n;i++)
			{
				if(A[i-1]+tempMax[i-1] < 0)
					tempMax[i]=0;
				else
					tempMax[i]= A[i-1]+tempMax[i-1];
			}
			max=tempMax[1];
			for(i=1;i<=n;i++)
				if(max<tempMax[i])
					max=tempMax[i];
			printf("%d\n",max);			
		}
		else
		{
			max=A[0];
			for(i=0;i<n;i++)
			{
				if(max<A[i])
					max=A[i];
			}
			printf("%d\n",max);
		}
	}
} 