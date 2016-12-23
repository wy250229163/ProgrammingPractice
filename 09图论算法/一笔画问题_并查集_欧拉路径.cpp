#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_VERTEX_NUM 1001
int Parent[MAX_VERTEX_NUM];//并查集
int Degree[MAX_VERTEX_NUM];//记录顶点的度

int Find_parent(int x) //并查集查找根 
{
	if(x==Parent[x])
		return x;
	return Find_parent(Parent[x]);
}
void init(int p) //传入参数为顶点个数 
{
	for(int i=1;i<=p;i++)
	{
		Parent[i]=i;
		Degree[i]=0;
	}
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int P,Q;
		cin>>P>>Q;
	 	init(P);
	 	while(Q--)
	 	{
	 		int A,B;
	 		cin>>A>>B;
	 		Degree[A]++;Degree[B]++;
	 		int flag_A=Find_parent(A);
	 		int flag_B=Find_parent(B);
	 		if(flag_A!=flag_B) //不在同一个集合就合并 
	 			Parent[A]=flag_B;
	 	}
	 	int num_root=0; //记录并查集个数 
		int num_odd_degree=0; //记录度是奇数的顶点个数 
		for(int i=1;i<=P;i++)
		{
			if(Parent[i]==i)
				num_root++;
			if(Degree[i]%2==1)
				num_odd_degree++;
		}
		
		//无向图的欧拉路径问题,首先保证图连通
		//其次奇数度顶点的个数要么没有(欧拉环)，要么两个(欧拉路径) 
		if(num_root==1 && (num_odd_degree==0||num_odd_degree==2))  
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
} 

/****
一笔画问题
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
zyc从小就比较喜欢玩一些小游戏，其中就包括画一笔画，他想请你帮他写一个程序，判断一个图是否能够用一笔画下来。

规定，所有的边都只能画一次，不能重复画。

输入
第一行只有一个正整数N(N<=10)表示测试数据的组数。
每组测试数据的第一行有两个正整数P,Q(P<=1000,Q<=2000)，分别表示这个画中有多少个顶点和多少条连线。（点的编号从1到P）
随后的Q行，每行有两个正整数A,B(0<A,B<P)，表示编号为A和B的两点之间有连线。
输出
如果存在符合条件的连线，则输出"Yes",
如果不存在符合条件的连线，输出"No"。
样例输入
2
4 3
1 2
1 3
1 4
4 5
1 2
2 3
1 3
1 4
3 4
样例输出
No
Yes
****/