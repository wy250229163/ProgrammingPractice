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
	VerNode *path;
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
		G.verNode[i].path=NULL;
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

void Unweighted(Graph &G,VerNode &S)
{
	queue<VerNode> Q;
	VerNode V;
	EdgeNode *w;
	Q.push(S);
	while(!Q.empty())
	{
		V=Q.front();Q.pop();
		w=V.firstedge;
		while(w)
		{
			int i; 
		}
	}
} 

int main()
{
	Graph G;
	CreateDAG(G,7,12);
}