#include<stdio.h>
#include<string.h>

int vis[1<<20+1];

int main(void)
{
	int D,N;
	while(1)
	{
		scanf("%d%d",&D,&N);
		if(!D && !N) break;
		memset(vis,0,sizeof(vis));
		int i,j,k;
		for(i=1;i<=N;i++)
		{
			k=1;
			for(j=1;j<D;j++)
			{
				vis[k]=!vis[k];
				k = vis[k]?2*k:2*k+1;
			}		
		}
		printf("%d\n",k);
	}
}
 
 /*
 
 */