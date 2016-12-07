#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

#define MAX_VERTEX_NUM 100
#define Vertextype int
#define Infinity 0xffff

typedef struct EdgeNode
{
	int adjVertex;
	EdgeNode *nextEdgeNode;
}EdgeNode;

typedef struct VerNode
{
	Vertextype data;
	int dist;
	Vertextype path;
	EdgeNode *firstedge;
}VerNode;

typedef struct Graph
{
	VerNode verNode[MAX_VERTEX_NUM];
	int vertex_num,edge_num;
}Graph;

void CreateDAG(Graph &G,int n,int e)
{
	int i,j,k;
	G.vertex_num=n;
	G.edge_num=e;
	for(i=1;i<=n;i++)
	{
		cin>>G.verNode[i].data;
		G.verNode[i].dist=Infinity;
		G.verNode[i].path=0;
		G.verNode[i].firstedge=NULL;
	}
	for(k=1;k<=e;k++)
	{
		EdgeNode *p;
		p=new EdgeNode;
		cin>>i>>j;
		p->adjVertex=j;
		p->nextEdgeNode=G.verNode[i].firstedge;
		G.verNode[i].firstedge=p;
	}
}

void Unweighted(Graph &G,int n)
{
	queue<VerNode> Q;
	VerNode V;
	EdgeNode *w;
	G.verNode[n].dist=0;
	Q.push(G.verNode[n]);
	while(!Q.empty())
	{
		V=Q.front();Q.pop();
		w=V.firstedge;
		while(w)
		{
			if(G.verNode[w->adjVertex].dist==Infinity)
			{			
				G.verNode[w->adjVertex].dist=V.dist+1;
				G.verNode[w->adjVertex].path=V.data;
				Q.push(G.verNode[w->adjVertex]);
			}
			w=w->nextEdgeNode;
		}
	}
} 

int main()
{
	int i;
	Graph G;
	CreateDAG(G,7,12);
	Unweighted(G,3);
	for(i=1;i<=7;i++)
		printf("%d ",G.verNode[i].path);
}

/*****²âÊÔÊý¾Ý 
1 2 3 4 5 6 7
3 1
3 6
1 2
1 4
2 4
2 5
4 3
4 5
4 6
4 7
5 7
7 6
*******/