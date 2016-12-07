#include<stdio.h>
#include<string.h>

int height[1000];
int width[1000];

void sortWithArea(int *h,int *w,int len)
{
	int i,j;
	int temp,temph,tempw;
	int area[len];
	for(i=0;i<len;i++)
		area[i]=h[i]*w[i];
	for(i=1;i<len;i++)
	{
		temp=area[i];
		temph=h[i];tempw=w[i];
		for(j=i; j>0 && area[j-1]<temp ;j--)
		{
			area[j]=area[j-1];
			h[j]=h[j-1];
			w[j]=w[j-1];
		}
		area[j]=temp;
		h[j]=temph;
		w[j]=tempw;
	}
}

int main(void)
{
	int N,n;
	int i,j;
	scanf("%d",&N); //数据组数 
	while(N--)
	{
		scanf("%d",&n); //矩形个数 
		int sum[n];
		int max,maxlen=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&height[i],&width[i]);
		sortWithArea(height,width,n);
		for(i=0;i<n;i++)
		{
			max=0;
			sum[i]=1;
			for(j=i-1;j>=0;j--)
			{
				if((((height[j]>height[i])&&(width[j]>width[i])) || ((height[j]>width[i])&&(width[j]>height[i]))) && sum[j]>max)
					max=sum[j];
			}
			sum[i]+=max;
			if(sum[i]>maxlen)
				maxlen=sum[i];
		}
		printf("%d\n",maxlen);
	}
}
 
 
//矩形嵌套 
//时间限制：3000 ms | 内存限制：65535 KB 
//难度：4 
//描述 
//有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成一行，使得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。 
//输入 
//第一行是一个正正数N(0<N<10)，表示测试数据组数， 
//每组测试数据的第一行是一个正正数n，表示该组测试数据中含有矩形的个数(n<=1000) 
//随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽 
//输出 
//每组测试数据都输出一个数，表示最多符合条件的矩形数目，每组输出占一行 
//样例输入 
//1 
//10 
//1 2 
//2 4 
//5 8 
//6 10 
//7 9 
//3 1 
//5 8 
//12 10 
//9 7 
//2 2 
//样例输出 
//5