#include<cstdio>
#include<cstring>

using namespace std;

int main(void)
{
	int n;
	while(scanf("%d",&n)&&n!=-1)
	{
		int num[3005],top[3005];
		int counts=0;
		int i,j;
		num[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]>num[i-1])
			{
				counts++;
			}
		}
		printf("%d\n",counts);
	}
} 