#include<cstdio>
#include<cstring>
using namespace std;
int num[20],visit[20];
int n,m;
void dfs(int cur)
{
	int i;
	if(cur==m)
	{
		for(i=0;i<m;i++)
			printf("%d",num[i]);
		printf("\n");
		return ;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				visit[i]=1;
				num[cur]=i;
				dfs(cur+1);
				visit[i]=0;
			}
		}
	} 
}

int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(visit,0,sizeof(visit));
		scanf("%d%d",&n,&m);
		dfs(0);
	}
	return 0;
} 
