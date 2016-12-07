#include<stdio.h>
#include<string.h>
int n;
int ans[21];
int vis[21];
int isPrim[38]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};

void DFS(int cur)
{
	if(cur==n && isPrim[ans[0]+ans[n-1]])
	{
		int i=0;
		for(i=0;i<n;i++)
			printf("%d ",ans[i]);
		printf("\n");	
	}
	else
	{
		int j=2;
		for(j=2;j<=n;j++)
		{
			if(!vis[j] && isPrim[j+ans[cur-1]])
			{
				vis[j]=1;
				ans[cur]=j;
				DFS(cur+1);
				vis[j]=0;
			}
		}
	}
}

int main()
{
	int counts=0;
	while(scanf("%d",&n) && n)
	{
		printf("Case %d:\n",++counts);
		
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(ans));
		ans[0]=1;
		
		if(n==1)
		{
			printf("1\n");
		}
		else if(n!=1 && n%2==0)
		{
			DFS(1);
		}
		else
		{
			printf("No Answer\n");
		}
	}
	return 0;
}
 
 
/*
 素数环
时间限制：1000 ms  |  内存限制：65535 KB
难度：2
描述
有一个整数n，把从1到n的数字无重复的排列成环，且使每相邻两个数（包括首尾）的和都为素数，称为素数环。

为了简便起见，我们规定每个素数环都从1开始。例如，下图就是6的一个素数环。



输入
有多组测试数据，每组输入一个n(0<n<20)，n=0表示输入结束。
输出
每组第一行输出对应的Case序号，从1开始。
如果存在满足题意叙述的素数环，从小到大输出。
否则输出No Answer。
样例输入
6
8
3
0
样例输出
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4
Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
Case 3:
No Answer
来源
hdu改编
上传者
ACM_丁国强*/