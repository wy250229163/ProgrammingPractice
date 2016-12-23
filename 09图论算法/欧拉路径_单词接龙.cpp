#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
#define MAX_VERTEX_NUM 27

int UnDirecCounter; //统计无向图的顶点个数，用于判定无向图是否是连通的
int DirecCounter; //统计有向图顶点个数 
int Visit[MAX_VERTEX_NUM]; //标记顶点是否被访问过 
 
void Init_Globalpara(void)
{
	UnDirecCounter=0;
	memset(Visit,0,sizeof(Visit));
}

typedef struct EdgeNode
{
	int adjVertex;
	int isDirecEdge; //标记此边是否为有向边 
	EdgeNode *nextEdgeNode;
}EdgeNode;

typedef struct VerNode
{
	int data;
	int inDegree;
	int outDegree;
	EdgeNode *firstedge;
}VerNode;

typedef struct Graph
{
	VerNode verNode[MAX_VERTEX_NUM];
	int vertex_num,edge_num;
}Graph;

void CreateDAG(Graph &G,int n) 
{
	int k;
	char word[10];
	char i,j;
	G.edge_num=n;
	EdgeNode *p;
	
	for(k=1;k<=26;k++) //初始化头结点
	{
		G.verNode[k].data=k;
		G.verNode[k].inDegree=0;
		G.verNode[k].outDegree=0;
		G.verNode[k].firstedge=NULL;		
	}
	
	for(k=1;k<=n;k++) //同时创建有向图及无向图 
	{
		cin>>word;
		i=word[0]; //首字母 
		j=word[strlen(word)-1]; //尾字母
		
		
		if(!Visit[i-'a'+1]) //计算无向图顶点个数 
		{
			Visit[i-'a'+1]=1;
			UnDirecCounter++; 
		}
		if(!Visit[j-'a'+1]) 
		{
			Visit[j-'a'+1]=1;
			UnDirecCounter++; 
		}
		
		G.verNode[j-'a'+1].inDegree++; //更新入度及出度 
		G.verNode[i-'a'+1].outDegree++;
		
		p=new EdgeNode;
		p->isDirecEdge=1; //有向边，用来标志有向图 
		p->adjVertex=(j-'a'+1);
		p->nextEdgeNode=G.verNode[i-'a'+1].firstedge;
		G.verNode[i-'a'+1].firstedge=p; 
		
		p=new EdgeNode;
		p->isDirecEdge=0; //无向边 
		p->adjVertex=(i-'a'+1);
		p->nextEdgeNode=G.verNode[j-'a'+1].firstedge;
		G.verNode[j-'a'+1].firstedge=p;
	}
}

int isWordList(Graph &G)
{
	//首先判断有向图的基图是否为弱连通的 
	int isConnected=0;
	VerNode V;
	EdgeNode *w;
	queue<VerNode> Q;
	int start=1;
	int tempCount=0;
	while(!Visit[start]) start++; //寻找图的一个起点 
	memset(Visit,0,sizeof(Visit)); //清空Visit，以便DFS时记录
	Q.push(G.verNode[start]);
	Visit[start]=1;
	while(!Q.empty())
	{
		V=Q.front();Q.pop();
		tempCount++;
		w=V.firstedge;
		while(w)
		{
			if(!Visit[w->adjVertex])
			{
				Q.push(G.verNode[w->adjVertex]);
				Visit[G.verNode[w->adjVertex].data]=1;
			}
			w=w->nextEdgeNode;
		}
	}
	if(tempCount==UnDirecCounter) //遍历到的顶点数等于图的顶点数，则为连通的 
		isConnected=1;	
		
	//然后寻找欧拉路径或者欧拉回路 
	int hasEuler=1;
	int startNum=0; //统计起点及终点个数 
	int endNum=0;
	for(int v=1;v<=26;v++)
	{
		if((G.verNode[v].outDegree-G.verNode[v].inDegree)==1)
			startNum++;
		if((G.verNode[v].inDegree-G.verNode[v].outDegree)==1)
			endNum++;
		if(abs(G.verNode[v].inDegree-G.verNode[v].outDegree)>1)
	 	{
	 		hasEuler=0;
		 	break;	
	 	}
	}
	int isEulerPath=(startNum==1 && endNum==1); //包含欧拉路径
	int isEulerCircuit=(startNum==0 && endNum==0); //包含欧拉回路 
	if((!isEulerPath)&&(!isEulerCircuit))
		hasEuler=0;
 
	if(hasEuler&&isConnected)
		return 1;
	else
		return 0; 
}

int main()
{
	int n;
	cin>>n;
	Graph G;
	Init_Globalpara();
	CreateDAG(G,n);
	if(isWordList(G))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl; 
}

/*****
拉姆刚开始学习英文单词，对单词排序很感兴趣。如果给拉姆一组单词，他能够迅速确定是否可以将这些单词排列在一个列表中，使得该列表中任何单词的首字母与前一单词的尾字母相同。你能编写一个程序来帮助拉姆进行判断吗？

输入描述：
输入包含多组测试数据。对于每组测试数据，第一行为一个正整数n，代表有n个单词。然后有n个字符串，代表n个单词。保证：2<=n<=200，每个单词长度大于1且小于等于10，且所有单词都是由小写字母组成。
输出描述：
对于每组数据，输出"Yes"或"No"

输入例子1:
3
abc
cdefg
ghijkl
输出：
Yes

输入例子2：
4
abc
cdef
fghijk
xyz
输出：
No

输入例子3：
3
aba
cdc
efe
输出：
No

输入例子4: 
4
abc
cde
cfg
ghc
输出：
YES 
*****/

