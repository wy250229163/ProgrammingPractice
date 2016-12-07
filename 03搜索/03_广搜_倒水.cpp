#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

#define EMPTY 0

typedef struct node
{
	int state[3];
	int step;
}cupNode;

int cupCapacity[3],cupEndstate[3];
int isVisited[100][100][100];

int isAchieve(cupNode current)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(current.state[i] != cupEndstate[i])
			return 0;
	}
	return 1;
}

int pourWater(int source,int destination,cupNode* cup)
{
	int waterNeeded=cupCapacity[destination]-cup->state[destination];
	if(waterNeeded <= cup->state[source])
	{
		cup->state[destination]+=waterNeeded;
		cup->state[source]-=waterNeeded;
	}
	else
	{
		cup->state[destination]+=cup->state[source];
		cup->state[source]=0;
	}
}

int BFS()
{
	int i,j,k;
	cupNode initial;
	queue<cupNode> cupStatequeue;
	
	memset(isVisited,0,sizeof(isVisited));
	initial.state[0]=cupCapacity[0];
	initial.state[1]=0;
	initial.state[2]=0;
	initial.step=0;
	
	cupStatequeue.push(initial);
	isVisited[initial.state[0]][0][0]=1;
	
	while(!cupStatequeue.empty())
	{
		cupNode tempNode;
		tempNode=cupStatequeue.front();
		cupStatequeue.pop();
		if(isAchieve(tempNode))
			return tempNode.step;
		cupNode newNode;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i!=j && tempNode.state[i]!=EMPTY && tempNode.state[j]<cupCapacity[j])
				{
					cupNode newNode=tempNode;
					pourWater(i,j,&newNode);
					newNode.step=tempNode.step+1;
					if(!isVisited[newNode.state[0]][newNode.state[1]][newNode.state[2]])
					{
						isVisited[newNode.state[0]][newNode.state[1]][newNode.state[2]]=1;
						cupStatequeue.push(newNode);
					}	
				}
			}
		} 
	}
	return -1;	
}

int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d",&cupCapacity[0],&cupCapacity[1],&cupCapacity[2]);
		scanf("%d%d%d",&cupEndstate[0],&cupEndstate[1],&cupEndstate[2]);
		printf("%d\n",BFS());
	}
	return 0;
}


/*
����ˮ�� 
ʱ�����ƣ�1000 ms | �ڴ����ƣ�65535 KB 
�Ѷȣ�4 
���� 
��������ˮ������С��һ������ֻ������ˮ����ˮ��װ���ģ���������Ϊ�ձ��ӡ�����ˮ��֮���໥��ˮ������ˮ��û�б�ʶ��ֻ�ܸ��ݸ�����ˮ����������㡣����Ҫ����д��һ������ʹ�����ʹ��ʼ״̬����Ŀ��״̬�����ٴ����� 
���� 
��һ��һ������N(0 < N < 50)��ʾN��������� 
������ÿ��������������У���һ�и�����������V1 V2 V3 (V1 > V2> V3 V1<100 V3>0)��ʾ����ˮ��������� 
�ڶ��и�����������E1 E2 E3 �����С�ڵ�����Ӧˮ���������ʾ������Ҫ������״̬ 
��� 
ÿ�������Ӧ�����������ٵĵ�ˮ����������ﲻ��Ŀ��״̬���-1 
�������� 
2 
6 3 1 
4 1 1 
9 3 2 
7 1 1 
������� 
3 
-1*/