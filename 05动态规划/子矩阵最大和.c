#include<stdio.h>
#include<string.h>

int num[101][101];

int main(void)
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		int i,j,k;
		memset(num,0,sizeof(num));
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
			{
				scanf("%d",&num[i][j]);	
				num[i][j]+=num[i-1][j];			
			}
		int temp=0;
		int max=num[1][1];
		int tempmax;
		for(i=1;i<=r;i++)
		{
			for(j=i;j<=r;j++)
			{
				tempmax=0;	
				for(k=1;k<=c;k++)
				{
					temp=num[j][k]-num[i-1][k];
					tempmax=(tempmax>=0?tempmax:0)+temp;
					max=tempmax>max?tempmax:max;
				}		
			}
		}
		printf("%d\n",max);
	}
	return 0;
} 
 
 
// 最大和
//时间限制：1000 ms  |  内存限制：65535 KB
//难度：5
//描述
//给定一个由整数组成二维矩阵（r*c），现在需要找出它的一个子矩阵，使得这个子矩阵内的所有元素之和最大，并把这个子矩阵称为最大子矩阵。 
//例子：
//0 -2 -7 0 
//9 2 -6 2 
//-4 1 -4 1 
//-1 8 0 -2 
//其最大子矩阵为：
//
//9 2 
//-4 1 
//-1 8 
//其元素总和为15。 
//
//输入
//第一行输入一个整数n（0<n<=100）,表示有n组测试数据；
//每组测试数据：
//第一行有两个的整数r，c（0<r,c<=100），r、c分别代表矩阵的行和列；
//随后有r行，每行有c个整数；
//输出
//输出矩阵的最大子矩阵的元素之和。
//样例输入
//1
//4 4
//0 -2 -7 0 
//9 2 -6 2 
//-4 1 -4 1 
//-1 8 0 -2 
//样例输出
//15