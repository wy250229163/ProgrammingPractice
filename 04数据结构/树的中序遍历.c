#include<stdio.h>
#include<string.h>

struct Node
{
	int left;
	int right;
}treeNode[20];

void  LDR(int node) //������� 
{
	if(node==-1)
		return ;
	LDR(treeNode[node].left);
	printf("%d\n",node);
	LDR(treeNode[node].right);
}
 
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;//�ڵ����
		int i;
		int n,l,r;//ÿ���ڵ�
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d%d%d",&n,&l,&r);
			treeNode[n].left=l;
			treeNode[n].right=r;
		}
		int m,d,e;
		scanf("%d",&m);
		while(m--) scanf("%d%d",&d,&e);
		LDR(0);
		printf("\n");
	}
} 
 