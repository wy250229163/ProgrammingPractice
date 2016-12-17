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
		CreateDAG(G,M,P); //给出图的顶点数及边数量
		Dijkstra(G,M,Q); //给出顶点数以及起点编号
		int min_dis=Infinity;
		for(i=1;i<=N;++i)
			if(G.verNode[army_city[i]].dist<min_dis)
				min_dis=G.verNode[army_city[i]].dist;
		cout<<min_dis<<endl;
	} 
}

/*
城市平乱
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
南将军统领着N个部队，这N个部队分别驻扎在N个不同的城市。

他在用这N个部队维护着M个城市的治安，这M个城市分别编号从1到M。

现在，小工军师告诉南将军，第K号城市发生了暴乱，南将军从各个部队都派遣了一个分队沿最近路去往暴乱城市平乱。

现在已知在任意两个城市之间的路行军所需的时间，你作为南将军麾下最厉害的程序员，请你编写一个程序来告诉南将军第一个分队到达叛乱城市所需的时间。



注意，两个城市之间可能不只一条路。

输入
第一行输入一个整数T，表示测试数据的组数。(T<20)
每组测试数据的第一行是四个整数N,M,P,Q(1<=N<=100,N<=M<=1000,M-1<=P<=100000)其中N表示部队数，M表示城市数，P表示城市之间的路的条数,Q表示发生暴乱的城市编号。
随后的一行是N个整数，表示部队所在城市的编号。
再之后的P行，每行有三个正整数，a,b,t(1<=a,b<=M,1<=t<=100)，表示a,b之间的路如果行军需要用时为t

数据保证暴乱的城市是可达的。
输出
对于每组测试数据，输出第一支部队到达叛乱城市时的时间。每组输出占一行
样例输入
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
样例输出
4
来源
《世界大学生程序设计竞赛高级教程·第一册》改编
上传者
张云聪
*/