#include"stdio.h"
#include"string.h"

int main(void)
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m,i,j,max,maxlen;
		scanf("%d",&m);
		int height[m];
		int sum[m];
		maxlen=1;
		for(i=0;i<m;i++)
		{
			scanf("%d",&height[i]);	
			sum[i]=1;			
			max=0;
			for(j=i-1;j>=0;j--)
			{
				if(height[j] > height[i] && sum[j]>max)
					max=sum[j];
			}
			sum[i]+=max;
			if(sum[i]>maxlen)
				maxlen=sum[i];
		}
		printf("%d\n",maxlen);
	}
	return 0;
} 

