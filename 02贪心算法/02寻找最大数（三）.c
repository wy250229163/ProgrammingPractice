#include<stdio.h>
#include<string.h>
int main()
{
	int k;
	char a[25];
	while(scanf("%s%d",a,&k)!=EOF)
	{
		int l,i,j,t;
		l=strlen(a);
		char temp;
		for(i=0;i<l&&k!=0;i++)
		{
			t=i; 
			temp=a[i];
			for(j=i+1;j<=i+k&&j<l;j++)
			{	
				if(a[j]>temp)
				{
					t=j;
					temp=a[j];		
				}
			}
			for(j=t;j>i;j--)
			{
				a[j]=a[j-1];
				k--;				
			}
			a[i]=temp;				
		}
		printf("%s\n",a);
	}
	return 0;
}
 
//描述
//给出一个整数N，每次可以移动2个相邻数位上的数字，最多移动K次，得到一个新的整数。
//
//求这个新的整数的最大值是多少。
//
//输入
//多组测试数据。
//每组测试数据占一行，每行有两个数N和K (1?≤?N≤?10^18; 0?≤?K?≤?100).
//输出
//每组测试数据的输出占一行，输出移动后得到的新的整数的最大值。
//样例输入
//1990 1
//100 0
//9090000078001234 6
//样例输出
//9190
//100
//9907000008001234