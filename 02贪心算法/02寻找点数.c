#include<stdio.h>
struct Node
{
	int left;
	int right;
}a[100];

void sort(struct Node* A,int N)
{
	int j,p;
	struct Node temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		for(j=p;j>0&&A[j-1].right>temp.right;j--)
			A[j]=A[j-1];
		A[j]=temp;
	}
} 
int main()
{
	int n,i,j,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].left,&a[i].right);
		sort(a,n);
		for(i=0,j=0;i<n;i++)
		{
			if(a[i].left > a[j].right)
			{
				j=i;
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return ;
}

//找点
//时间限制：2000 ms  |  内存限制：65535 KB
//难度：2
//描述
//上数学课时，老师给了LYH一些闭区间，让他取尽量少的点，使得每个闭区间内至少有一个点。但是这几天LYH太忙了，你们帮帮他吗？
//输入
//多组测试数据。
//每组数据先输入一个N，表示有N个闭区间（N≤100)。
//接下来N行，每行输入两个数a，b(0≤a≤b≤100），表示区间的两个端点。
//输出
//输出一个整数，表示最少需要找几个点。
//样例输入
//4
//1 5
//2 4
//1 4
//2 3
//3
//1 2
//3 4
//5 6
//1
//2 2
//样例输出
//1
//3
//1