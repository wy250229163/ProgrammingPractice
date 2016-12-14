#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

#define MAX_VERTEX_NUM 100
#define Vertextype int
#define Infinity 0xffff
#define NotAVertex -1

typedef struct EdgeNode
{
	int adjVertex;
	int weight; //�ڽ�Ȩ�� 
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
	for(k=1;k<=e;k++)  //����ͼ�������ڽӱ�Ҫ�������� 
	{
		EdgeNode *p;
		cin>>i>>j>>w;
		
		p=new EdgeNode;
		p->adjVertex=j;
		p->weight=w;
		p->nextEdgeNode=G.verNode[i].firstedge;
		G.verNode[i].firstedge=p;
		
		p=new EdgeNode;
		p->adjVertex=i;
		p->weight=w;
		p->nextEdgeNode=G.verNode[j].firstedge;
		G.verNode[j].firstedge=p;
	}
}

void Prim(Graph &G,int n,int start) //����С������Prim�㷨 
{
	VerNode V;
    EdgeNode *w;
    int i,j,temp_num,temp_dist;
    G.verNode[start].dist=0;
    G.verNode[start].path=0;
 	for(i=1;i<=n;++i) //n��������� 
 	{
 		temp_dist=Infinity;
	 	temp_num=0;
	    for(j=1;j<=n;++j) //��Ѱ��δ֪����̶���
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
		    	G.verNode[w->adjVertex].dist = min(G.verNode[w->adjVertex].dist,w->weight);
		    	if(G.verNode[w->adjVertex].dist == w->weight) //˵��Ȩֵ�����£���ô��Ҫ����·����� 
    				G.verNode[w->adjVertex].path=G.verNode[temp_num].data;	    			
		    }
    		w=w->nextEdgeNode;
    	}
	}
}

int PrintMST(Graph &G,int n) //��ӡ��С������ 
{
	for(int i=1;i<=n;i++)
		printf("%d <=> %d\n",i,G.verNode[i].path);
}

int main()
{
    Graph G;
    CreateDAG(G,7,12); //����ͼ�Ķ�������������
    Prim(G,7,1); //�����������Լ������
    PrintMST(G,7); //��������������ӡ��С������ 
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
4 5 7
4 6 8
4 7 4
5 7 6
7 6 1

�����
1 <=> 0
2 <=> 1
3 <=> 4
4 <=> 1
5 <=> 7
6 <=> 7
7 <=> 4 
*********************/ 