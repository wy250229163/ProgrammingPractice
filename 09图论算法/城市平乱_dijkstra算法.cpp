#include<cstdio>
#include<iostream>

using namespace std;

#define MAX_VERTEX_NUM 1001
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
		G.verNode[i].data=i;
		G.verNode[i].Known=0;
		G.verNode[i].dist=Infinity;
		G.verNode[i].path=-1;
		G.verNode[i].firstedge=NULL;
	}
	for(k=1;k<=e;k++)
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

void Dijkstra(Graph &G,int n,int start) //��Ȩ·�����Dijkstra�㷨 
{
	VerNode V;
    EdgeNode *w;
    int i,j,temp_num,temp_dist;
    G.verNode[start].dist=0;
    
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

int main()
{
	int i,T,N,M,P,Q;
	cin>>T;
	while(T--)
	{
		Graph G;
		cin>>N>>M>>P>>Q;
		int army_city[N+1];
		for(i=1;i<=N;++i)
			cin>>army_city[i];
		CreateDAG(G,M,P); //����ͼ�Ķ�������������
		Dijkstra(G,M,Q); //�����������Լ������
		int min_dis=Infinity;
		for(i=1;i<=N;++i)
			if(G.verNode[army_city[i]].dist<min_dis)
				min_dis=G.verNode[army_city[i]].dist;
		cout<<min_dis<<endl;
	} 
}

/*
����ƽ��
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
�Ͻ���ͳ����N�����ӣ���N�����ӷֱ�פ����N����ͬ�ĳ��С�

��������N������ά����M�����е��ΰ�����M�����зֱ��Ŵ�1��M��

���ڣ�С����ʦ�����Ͻ�������K�ų��з����˱��ң��Ͻ����Ӹ������Ӷ���ǲ��һ���ֶ������·ȥ�����ҳ���ƽ�ҡ�

������֪��������������֮���·�о������ʱ�䣬����Ϊ�Ͻ��������������ĳ���Ա�������дһ�������������Ͻ�����һ���ֶӵ������ҳ��������ʱ�䡣



ע�⣬��������֮����ܲ�ֻһ��·��

����
��һ������һ������T����ʾ�������ݵ�������(T<20)
ÿ��������ݵĵ�һ�����ĸ�����N,M,P,Q(1<=N<=100,N<=M<=1000,M-1<=P<=100000)����N��ʾ��������M��ʾ��������P��ʾ����֮���·������,Q��ʾ�������ҵĳ��б�š�
����һ����N����������ʾ�������ڳ��еı�š�
��֮���P�У�ÿ����������������a,b,t(1<=a,b<=M,1<=t<=100)����ʾa,b֮���·����о���Ҫ��ʱΪt

���ݱ�֤���ҵĳ����ǿɴ�ġ�
���
����ÿ��������ݣ������һ֧���ӵ������ҳ���ʱ��ʱ�䡣ÿ�����ռһ��
��������
1
3 8 9 8
1 2 3
1 2 1
2 3 2
1 4 2
2 5 3
3 6 2
4 7 1
5 7 3
5 8 2
6 8 2 
�������
4
��Դ
�������ѧ��������ƾ����߼��̡̳���һ�ᡷ�ı�
�ϴ���
���ƴ�
*/