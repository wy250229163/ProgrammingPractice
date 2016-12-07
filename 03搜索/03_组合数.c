#include<stdio.h>
#include<string.h>
int ans[11];
int N,R;
void DFS(int n,int cur)
{
	int i,j;
	if(cur==R)
	{
		for(i=0;i<R;i++)
			printf("%d",ans[i]);
		printf("\n");
	}
	else
	{
		for(j=n;j>0;j--)
		{
			ans[cur]=j;
			DFS(--n,cur+1);
		}
	}
}

int main()
{
	while(scanf("%d %d",&N,&R)!=EOF)
	{		
		memset(ans,0,sizeof(ans));
		DFS(N,0);
	}
	
}