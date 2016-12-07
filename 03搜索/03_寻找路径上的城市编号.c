#include<stdio.h>
#include<stdlib.h>
struct cityNode
{
	int toCity; 
	struct cityNode* nextCity;
};

void DFS(struct cityNode* city , int* lastcityarry ,int s)
{
	struct cityNode* p;
	p=&city[s];
	while(p->nextCity!=NULL)
	{
		p=p->nextCity;
		lastcityarry[p->toCity]=s;
		DFS(city, lastcityarry, p->toCity);
	}
} 

int main()
{
	int M;
	scanf("%d",&M);
	while(M--)
	{
		int N,S;
		int i,j,a,b;
		scanf("%d%d",&N,&S);
		int lastCityNum[N+1];
		struct cityNode cityNum[N+1];
		memset(lastCityNum,0,sizeof(lastCityNum));
		for(i=0;i<=N;i++)
		{
			cityNum[i].toCity=0;
			cityNum[i].nextCity=NULL;
		}
		
		struct cityNode* temp;		
		for(i=1;i<N;i++)
		{
			struct cityNode* p;
			p=(struct cityNode *)malloc(sizeof(struct cityNode));
			scanf("%d%d",&a,&b);
			p->toCity=b;
			p->nextCity=NULL;
			temp=&cityNum[a];
			while(temp->nextCity!=NULL)
				temp=temp->nextCity;
			temp->nextCity=p;
		}
		
		struct cityNode terminal;
		terminal.toCity=0;
		terminal.nextCity=NULL;
		for(i=1;i<=N;i++)
		{
			temp=&cityNum[i];
			while(temp->nextCity!=NULL)
				temp=temp->nextCity;
			temp->nextCity=&terminal;
		}

		DFS(cityNum,lastCityNum,S);
		lastCityNum[S]=-1;
		for(i=1;i<=N;i++)
			printf("%d ",lastCityNum[i]);
		printf("\n");
	}
}
 
 
 
// 吝啬的国度
//时间限制：1000 ms  |  内存限制：65535 KB
//难度：3
//描述
//在一个吝啬的国度里有N个城市，这N个城市间只有N-1条路把这个N个城市连接起来。现在，Tom在第S号城市，他有张该国地图，他想知道如果自己要去参观第T号城市，必须经过的前一个城市是几号城市（假设你不走重复的路）。
//输入
//第一行输入一个整数M表示测试数据共有M(1<=M<=5)组
//每组测试数据的第一行输入一个正整数N(1<=N<=100000)和一个正整数S(1<=S<=100000)，N表示城市的总个数，S表示参观者所在城市的编号
//随后的N-1行，每行有两个正整数a,b(1<=a,b<=N)，表示第a号城市和第b号城市之间有一条路连通。
//输出
//每组测试数据输N个正整数，其中，第i个数表示从S走到i号城市，必须要经过的上一个城市的编号。（其中i=S时，请输出-1）
//样例输入
//1
//10 1
//1 9
//1 8
//8 10
//10 3
//8 6
//1 2
//10 4
//9 5
//3 7
//样例输出
//-1 1 10 10 9 8 3 1 1 8