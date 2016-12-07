#include<cstdio>
#include<iostream>
#include<queue>

#define MAX_VERTEX_NUM 100
#define Vertextype int

using namespace std;

typedef struct EdgeNode
{
	int adjVertex;
	EdgeNode *nextEdgeNode;
}EdgeNode;

typedef struct VerNode
{
	int indeed;
	Vertextype data;
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
		G.verNode[i].firstedge=NULL;
		G.verNode[i].indeed=0;
	}
	for(k=1;k<=e;k++)
	{
		EdgeNode *p;
		p=new EdgeNode;
		cin>>i>>j;
		p->adjVertex=j;
		p->nextEdgeNode=G.verNode[i].firstedge;
		G.verNode[i].firstedge=p;
		G.verNode[j].indeed+=1;
	}
}

void Topsort(Graph &G)
{
	int i;
	queue<VerNode> Q;
	int counter=0;
	VerNode V;
	EdgeNode *w;
	for(i=1;i<=G.vertex_num;i++)
		if(G.verNode[i].indeed==0)
			Q.push(G.verNode[i]);
	cout<<"The topsort is: "; 
	while(!Q.empty())
	{
		V=Q.front();Q.pop();
		cout<<V.data<<" ";
		counter++;
		w=V.firstedge;
		while(w)
		{
			G.verNode[w->adjVertex].indeed--;
			if(G.verNode[w->adjVertex].indeed==0)
				Q.push(G.verNode[w->adjVertex]);
			w=w->nextEdgeNode;
		}
	}
	if(counter<G.vertex_num)
		cout<<"Graph has a cycle!"<<endl;
}

int main(void)
{
	Graph G;
	CreateDAG(G,7,12);
	Topsort(G);
}