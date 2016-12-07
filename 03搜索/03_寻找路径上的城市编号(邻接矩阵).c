#include<stdio.h>
#include<string.h>
int adj[100][100];
void dfs(int (*adjcity)[100],int *citynum,int s,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(i==s)
			continue;
		if(adjcity[s][i])
		{
			citynum[i]=s;
			dfs(adjcity,citynum,i,n);
		}
	}
}

int main()
{
	int M;
	scanf("%d",&M);
	while(M--)
	{
		int N,S;
		int i,j,a,b;
		scanf("%d%d",&N,&S);
		int lastcityNum[N+1];
		memset(adj,0,sizeof(adj));
		memset(lastcityNum,0,sizeof(lastcityNum));
		for(i=0;i<N-1;i++)
		{
			scanf("%d%d",&a,&b);
			adj[a][b]=1;
		}
		dfs(adj,lastcityNum,S,N+1);
		lastcityNum[S]=-1;
		for(i=1;i<N+1;i++)
			printf("%d ",lastcityNum[i]);
		printf("\n");	
	}
}
 
 
 
// ���ĵĹ���
//ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
//�Ѷȣ�3
//����
//��һ�����ĵĹ�������N�����У���N�����м�ֻ��N-1��·�����N�������������������ڣ�Tom�ڵ�S�ų��У������Ÿù���ͼ������֪������Լ�Ҫȥ�ι۵�T�ų��У����뾭����ǰһ�������Ǽ��ų��У������㲻���ظ���·����
//����
//��һ������һ������M��ʾ�������ݹ���M(1<=M<=5)��
//ÿ��������ݵĵ�һ������һ��������N(1<=N<=100000)��һ��������S(1<=S<=100000)��N��ʾ���е��ܸ�����S��ʾ�ι������ڳ��еı��
//����N-1�У�ÿ��������������a,b(1<=a,b<=N)����ʾ��a�ų��к͵�b�ų���֮����һ��·��ͨ��
//���
//ÿ�����������N�������������У���i������ʾ��S�ߵ�i�ų��У�����Ҫ��������һ�����еı�š�������i=Sʱ�������-1��
//��������
//1
//10 1
//1 9
//1 8
//8 10
//10 3
//8 6
//1 2
//10 4
//9 5
//3 7
//�������
//-1 1 10 10 9 8 3 1 1 8