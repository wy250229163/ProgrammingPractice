#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
#define MAX_VERTEX_NUM 27

int UnDirecCounter; //ͳ������ͼ�Ķ�������������ж�����ͼ�Ƿ�����ͨ��
int DirecCounter; //ͳ������ͼ������� 
int Visit[MAX_VERTEX_NUM]; //��Ƕ����Ƿ񱻷��ʹ� 
 
void Init_Globalpara(void)
{
	UnDirecCounter=0;
	memset(Visit,0,sizeof(Visit));
}

typedef struct EdgeNode
{
	int adjVertex;
	int isDirecEdge; //��Ǵ˱��Ƿ�Ϊ����� 
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
	
	for(k=1;k<=26;k++) //��ʼ��ͷ���
	{
		G.verNode[k].data=k;
		G.verNode[k].inDegree=0;
		G.verNode[k].outDegree=0;
		G.verNode[k].firstedge=NULL;		
	}
	
	for(k=1;k<=n;k++) //ͬʱ��������ͼ������ͼ 
	{
		cin>>word;
		i=word[0]; //����ĸ 
		j=word[strlen(word)-1]; //β��ĸ
		
		
		if(!Visit[i-'a'+1]) //��������ͼ������� 
		{
			Visit[i-'a'+1]=1;
			UnDirecCounter++; 
		}
		if(!Visit[j-'a'+1]) 
		{
			Visit[j-'a'+1]=1;
			UnDirecCounter++; 
		}
		
		G.verNode[j-'a'+1].inDegree++; //������ȼ����� 
		G.verNode[i-'a'+1].outDegree++;
		
		p=new EdgeNode;
		p->isDirecEdge=1; //����ߣ�������־����ͼ 
		p->adjVertex=(j-'a'+1);
		p->nextEdgeNode=G.verNode[i-'a'+1].firstedge;
		G.verNode[i-'a'+1].firstedge=p; 
		
		p=new EdgeNode;
		p->isDirecEdge=0; //����� 
		p->adjVertex=(i-'a'+1);
		p->nextEdgeNode=G.verNode[j-'a'+1].firstedge;
		G.verNode[j-'a'+1].firstedge=p;
	}
}

int isWordList(Graph &G)
{
	//�����ж�����ͼ�Ļ�ͼ�Ƿ�Ϊ����ͨ�� 
	int isConnected=0;
	VerNode V;
	EdgeNode *w;
	queue<VerNode> Q;
	int start=1;
	int tempCount=0;
	while(!Visit[start]) start++; //Ѱ��ͼ��һ����� 
	memset(Visit,0,sizeof(Visit)); //���Visit���Ա�DFSʱ��¼
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
	if(tempCount==UnDirecCounter) //�������Ķ���������ͼ�Ķ���������Ϊ��ͨ�� 
		isConnected=1;	
		
	//Ȼ��Ѱ��ŷ��·������ŷ����· 
	int hasEuler=1;
	int startNum=0; //ͳ����㼰�յ���� 
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
	int isEulerPath=(startNum==1 && endNum==1); //����ŷ��·��
	int isEulerCircuit=(startNum==0 && endNum==0); //����ŷ����· 
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
��ķ�տ�ʼѧϰӢ�ĵ��ʣ��Ե�������ܸ���Ȥ���������ķһ�鵥�ʣ����ܹ�Ѹ��ȷ���Ƿ���Խ���Щ����������һ���б��У�ʹ�ø��б����κε��ʵ�����ĸ��ǰһ���ʵ�β��ĸ��ͬ�����ܱ�дһ��������������ķ�����ж���

����������
�����������������ݡ�����ÿ��������ݣ���һ��Ϊһ��������n��������n�����ʡ�Ȼ����n���ַ���������n�����ʡ���֤��2<=n<=200��ÿ�����ʳ��ȴ���1��С�ڵ���10�������е��ʶ�����Сд��ĸ��ɡ�
���������
����ÿ�����ݣ����"Yes"��"No"

��������1:
3
abc
cdefg
ghijkl
�����
Yes

��������2��
4
abc
cdef
fghijk
xyz
�����
No

��������3��
3
aba
cdc
efe
�����
No

��������4: 
4
abc
cde
cfg
ghc
�����
YES 
*****/

