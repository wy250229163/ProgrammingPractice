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


int main()
{
    Graph G;
    int n,v,e;
    cin>>n;
    while(n--)
    {
    	cin>>v>>e;
    	CreateDAG(G,v,e); //����ͼ�Ķ�������������
	    Prim(G,v,1); //�����������Լ������
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
��������
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
������ѧԺҪ�����õ���·���죬����У��Ҫ�����ʦ��Ƴ�һ�ֲ��߷�ʽ���ò��߷�ʽ��Ҫ��������������
1�������е�¥�����ϵ硣
2�����õ��߻�������
����
��һ����һ������n��ʾ��n��������ݡ�(n<5)
ÿ��������ݵĵ�һ������������v,e.
v��ʾѧУ��¥���ܸ���(v<=500)
����e���ÿ������������a,b,c��ʾa��b֮�������������·����Ϊc(c<=100)����������¥�����û��ָ�����ѣ����ʾ������¥ֱ����ͨ��Ҫ����̫����߲�������ͨ��
����1�����v������,���е�i������ʾ�ӵ�i��¥���ߵ���繩����ʩ����Ҫ�ķ��á�( 0<e<v*(v-1)/2 )
��¥�ı�Ŵ�1��ʼ�������ڰ�ȫ���⣬ֻ��ѡ��һ��¥���ӵ���繩���豸��
���ݱ�֤���ٴ���һ�ַ�������Ҫ��
���
ÿ������������һ��������,��ʾ��������У��Ҫ�����·����С���ѡ�
��������
1
4 6
1 2 10
2 3 10
3 1 10
1 4 1
2 4 1
3 4 1
1 3 5 6
�������
4
��Դ
[���ƴ�]ԭ��
�ϴ���
���ƴ�
*/