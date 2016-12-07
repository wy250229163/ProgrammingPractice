#include<stdio.h>
#include<queue>

typedef struct node
{
	int state[3];
	int cur;
}cupNode;

/**********************╤сап ******************************/ 




/*********************************************************/ 


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
	
}

int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d",&cupCapacity[0],&cupCapacity[1],&cupCapacity[2]);
		scanf("%d%d%d",&cupEndstate[0],&cupEndstate[1],&cupCapacity[2]);
		printf("%d\n",BFS());
	}
	return 0;
}

 