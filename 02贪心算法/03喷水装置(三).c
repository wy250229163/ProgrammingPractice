#include<stdio.h>
#include<math.h>
struct Node
{
	double left;
	double right;
}N[10000];

void sort(struct Node* A,int N)  //左端点由小到大排序 
{
	int j,p;
	struct Node temp;
	for(p=1;p<N;p++)
	{
		temp=A[p];
		for(j=p;j>0&&A[j-1].left>temp.left;j--)
			A[j]=A[j-1];
		A[j]=temp;
	}
} 

int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int i,j,n,w,h,x,r;
		int num=-1;
		int total=0;
		int maxp=0,tempmax=0;
		scanf("%d%d%d",&n,&w,&h);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&r);
			if(2*r<h)
				continue;
			else
				num++;
			N[num].left=(double)x-sqrt(r*r-h*h/4);
			N[num].right=(double)x+sqrt(r*r-h*h/4);
		}
		sort(N,num+1); //按区间左端点由小到大排序 
		for(i=0;i<num+1;i++)
		{
			if(N[i].left<=maxp)  //此条语句配合64行，就可以判断两区间是否有间隔了 
			{
				tempmax=N[i].right;
				while(N[i].left<=maxp)
				{
					if(N[i].right>tempmax)
						tempmax=N[i].right;
					i++;
					if(i==num+1)
						break;	
				}
				maxp=tempmax;
				total++;
				i--;
			}
			if(maxp>=w)
				break;				
		}
		if(maxp>=w)	
			printf("%d\n",total);
		else
			printf("%d\n",0);
	}
	return 0;
}
 
 
 
// 描述
//有一块草坪，横向长w,纵向长为h,在它的橫向中心线上不同位置处装有n(n<=10000)个点状的喷水装置，每个喷水装置i喷水的效果是让以它为中心半径为Ri的圆都被润湿。请在给出的喷水装置中选择尽量少的喷水装置，把整个草坪全部润湿。
//输入
//第一行输入一个正整数N表示共有n次测试数据。
//每一组测试数据的第一行有三个整数n,w,h，n表示共有n个喷水装置，w表示草坪的横向长度，h表示草坪的纵向长度。
//随后的n行，都有两个整数xi和ri,xi表示第i个喷水装置的的横坐标（最左边为0），ri表示该喷水装置能覆盖的圆的半径。
//输出
//每组测试数据输出一个正整数，表示共需要多少个喷水装置，每个输出单独占一行。
//如果不存在一种能够把整个草坪湿润的方案，请输出0。
//样例输入
//2
//2 8 6
//1 1
//4 5
//2 10 6
//4 5
//6 5
//样例输出
//1
//2