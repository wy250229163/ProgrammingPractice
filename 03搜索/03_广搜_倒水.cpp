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
三个水杯 
时间限制：1000 ms | 内存限制：65535 KB 
难度：4 
描述 
给出三个水杯，大小不一，并且只有最大的水杯的水是装满的，其余两个为空杯子。三个水杯之间相互倒水，并且水杯没有标识，只能根据给出的水杯体积来计算。现在要求你写出一个程序，使其输出使初始状态到达目标状态的最少次数。 
输入 
第一行一个整数N(0 < N < 50)表示N组测试数据 
接下来每组测试数据有两行，第一行给出三个整数V1 V2 V3 (V1 > V2> V3 V1<100 V3>0)表示三个水杯的体积。 
第二行给出三个整数E1 E2 E3 （体积小于等于相应水杯体积）表示我们需要的最终状态 
输出 
每行输出相应测试数据最少的倒水次数。如果达不到目标状态输出-1 
样例输入 
2 
6 3 1 
4 1 1 
9 3 2 
7 1 1 
样例输出 
3 
-1*/