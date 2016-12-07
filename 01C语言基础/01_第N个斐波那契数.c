#include<stdio.h>
#include<stdlib.h>
void CreatFibArry(int *a,int start,int end)  
{
	a[0]=a[1]=1;
	if(start<2)  //起始项必须从2开始， 
		start=2;
 	if(end>=start)
 	{
 		CreatFibArry(a,start,end-1);
		a[end]=a[end-1]+a[end-2];
	}
	else
	{
		return ;
	}
} 
int main(void)
{
	int i,num;
	int intI[5];      //存储输入值得个数 
	int Fibonacci[20];	//存储斐波那契数列 
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&intI[i]);
		if(i==0)   //在第一项首先应该初始化生成一个斐波那契数列 
		{
			CreatFibArry(Fibonacci,2,intI[i]);
			printf("%d\n",Fibonacci[intI[i]-1]);				
		}
		else	//从第二项开始，每次均要比较与前一项的大小关系。 
		{
			if(intI[i]<=intI[i-1])   //如果比前一项小，那么我们直接可以读取出数列中的项 
			{
				printf("%d\n",Fibonacci[intI[i]-1]);
			}
			else    //如果要读取的第二项比第一项大，那么先继续生成斐波那契数列，再读取 
			{
				CreatFibArry(Fibonacci,intI[i-1],intI[i]);
				printf("%d\n",Fibonacci[intI[i]-1]);
			}	
		}	
	}
	return 0;
} 
