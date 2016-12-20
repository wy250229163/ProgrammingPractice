#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

#define MAX_VERTEX_NUM 100
#define Vertextype int
#define Infinity 0xffff
#define NotAVertex -1

typedef struct EdgeNode
{
	int adjVertex;
	int weight; //邻接权重 
	EdgeNode *nextEdgeNode;
}EdgeNode;

typedef struct VerNode
{
	int Known;
	Vertextype data;
	int dist;
	int path;
	EdgeNode *firstedge;
}VerNode;

typedef struct Graph
{
	VerNode verNode[MAX_VERTEX_NUM];
	int vertex_num,edge_num;
}Graph;

void CreateDAG(Graph &G,int n,int e)
{
	int i,j,w,k;
	G.vertex_num=n;
	G.edge_num=e;
	for(i=1;i<=n;i++)
	{
		cin>>G.verNode[i].data;
		G.verNode[i].Known=0;
		G.verNode[i].dist=Infinity;
		G.verNode[i].path=-1;
		G.verNode[i].firstedge=NULL;
	}
	for(k=1;k<=e;k++)
	{
		EdgeNode *p;
		p=new EdgeNode;
		cin>>i>>j>>w;
		p->adjVertex=j;
		p->weight=w;
		p->nextEdgeNode=G.verNode[i].firstedge;
		G.verNode[i].firstedge=p;
	}
}

void Dijkstra(Graph &G,int n,int start) //带权路径最短Dijkstra算法 
{
	VerNode V;
    EdgeNode *w;
    int i,j,temp_num,temp_dist;
    G.verNode[start].dist=0;
    
 	for(i=1;i<=n;++i) //n个点待查找 
 	{
 		temp_dist=Infinity;
	 	temp_num=0;
	    for(j=1;j<=n;++j) //先寻找未知的最短顶点
	    {
	    	if(G.verNode[j].Known==0 && G.verNode[j].dist<temp_dist)
    		{
		    	temp_dist=G.verNode[j].dist;
		    	temp_num=j;
		    }
	    }
	    G.verNode[temp_num].Known=1;
	    w=G.verNode[temp_num].firstedge;
	    while(w)
	    {
    		if(G.verNode[w->adjVertex].Known==0)
    		{
		    	if(G.verNode[temp_num].dist+w->weight < G.verNode[w->adjVertex].dist)
		    	{
		    		G.verNode[w->adjVertex].dist = G.verNode[temp_num].dist+w->weight;
	    			G.verNode[w->adjVertex].path=G.verNode[temp_num].data;	    			
	    		}
		    }
    		w=w->nextEdgeNode;
    	}
	}
}

void PrintPath(Graph &G,int n,int end) //打印最短路径信息
{
	if(G.verNode[end].path!=NotAVertex)
	{
		PrintPath(G,n,G.verNode[end].path);
		printf(" => ");
	}
	printf("%d",G.verNode[end].data);
}

int main()
{
    Graph G;
    CreateDAG(G,7,12); //给出图的顶点数及边数量
    Dijkstra(G,7,1); //给出顶点数以及起点编号
    PrintPath(G,7,6); //给出顶点数以及终点编号 
}

/********************

1 2 3 4 5 6 7
1 2 2
1 4 1
2 4 3
2 5 10
3 1 4
3 6 5
4 3 2
4 5 2
4 6 8
4 7 4
5 7 6
7 6 1

*********************/ 