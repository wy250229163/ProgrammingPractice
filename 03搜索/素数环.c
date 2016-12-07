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
 ������
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�2
����
��һ������n���Ѵ�1��n���������ظ������гɻ�����ʹÿ������������������β���ĺͶ�Ϊ��������Ϊ��������

Ϊ�˼����������ǹ涨ÿ������������1��ʼ�����磬��ͼ����6��һ����������



����
�ж���������ݣ�ÿ������һ��n(0<n<20)��n=0��ʾ���������
���
ÿ���һ�������Ӧ��Case��ţ���1��ʼ��
�������������������������������С���������
�������No Answer��
��������
6
8
3
0
�������
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
��Դ
hdu�ı�
�ϴ���
ACM_����ǿ*/