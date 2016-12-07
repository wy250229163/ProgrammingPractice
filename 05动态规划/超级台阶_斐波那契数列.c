#include"stdio.h"
#include"string.h" 

int main(void)
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m,i;
		scanf("%d",&m);
		int step[m+1];
		memset(step,0,sizeof(step));
		step[1]=0;step[2]=1;step[3]=2;
		for(i=4;i<=m;i++)
		{
			step[i]=step[i-1]+step[i-2];
		}
		printf("%d\n",step[m]);
	}
}