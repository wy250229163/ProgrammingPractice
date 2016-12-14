#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

#define MAX_VERTEX_NUM 501
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
	for(k=1;k<=e;k++)  //无向图，所以邻接表要生成两份 
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

void Prim(Graph &G,int n,int start) //求最小生成树Prim算法 
{
	VerNode V;
    EdgeNode *w;
    int i,j,temp_num,temp_dist;
    G.verNode[start].dist=0;
    G.verNode[start].path=0;
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
		    	G.verNode[w->adjVertex].dist = min(G.verNode[w->adjVertex].dist,w->weight);
		    	if(G.verNode[w->adjVertex].dist == w->weight) //说明权值被更新，那么就要更新路径标记 
    				G.verNode[w->adjVertex].path=G.verNode[temp_num].data;	    			
		    }
    		w=w->nextEdgeNode;
    	}
	}
}


int main()
{
    Graph G;
    int n,v,e;
    cin>>n;
    while(n--)
    {
    	cin>>v>>e;
    	CreateDAG(G,v,e); //给出图的顶点数及边数量
	    Prim(G,v,1); //给出顶点数以及起点编号
    	int i,value,temp_min=Infinity,total=0;
    	for(i=1;i<=v;i++)
   		{
		   	cin>>value;
		   	temp_min=min(value,temp_min);
		   	
		   	total+=G.verNode[i].dist;
	    }
	    total+=temp_min;
	    cout<<total<<endl;
    }
}

/*
布线问题
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
南阳理工学院要进行用电线路改造，现在校长要求设计师设计出一种布线方式，该布线方式需要满足以下条件：
1、把所有的楼都供上电。
2、所用电线花费最少
输入
第一行是一个整数n表示有n组测试数据。(n<5)
每组测试数据的第一行是两个整数v,e.
v表示学校里楼的总个数(v<=500)
随后的e行里，每行有三个整数a,b,c表示a与b之间如果建铺设线路花费为c(c<=100)。（哪两栋楼间如果没有指明花费，则表示这两栋楼直接连通需要费用太大或者不可能连通）
随后的1行里，有v个整数,其中第i个数表示从第i号楼接线到外界供电设施所需要的费用。( 0<e<v*(v-1)/2 )
（楼的编号从1开始），由于安全问题，只能选择一个楼连接到外界供电设备。
数据保证至少存在一种方案满足要求。
输出
每组测试数据输出一个正整数,表示铺设满足校长要求的线路的最小花费。
样例输入
1
4 6
1 2 10
2 3 10
3 1 10
1 4 1
2 4 1
3 4 1
1 3 5 6
样例输出
4
来源
[张云聪]原创
上传者
张云聪
*/