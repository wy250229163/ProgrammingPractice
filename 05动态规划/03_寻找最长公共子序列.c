#include<stdio.h>
#include<string.h>

int main()
{
	int N,i,j;
	scanf("%d",&N);
	while(N--)
	{
		char str1[1000],str2[1000];
		scanf("%s%s",str1,str2);
		int len1=strlen(str1),len2=strlen(str2);
		int LCS[len1+1][len2+1];
		memset(LCS,0,sizeof(LCS));
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(str1[i-1]==str2[j-1])
					LCS[i][j]=LCS[i-1][j-1]+1;
				else
					LCS[i][j]= LCS[i-1][j]>LCS[i][j-1]? LCS[i-1][j]:LCS[i][j-1];
			}			
		}
		printf("%d\n",LCS[len1][len2]);
	}
}


/*
最长公共子序列
时间限制：3000 ms  |  内存限制：65535 KB
难度：3
描述
咱们就不拐弯抹角了，如题，需要你做的就是写一个程序，得出最长公共子序列。
tip：最长公共子序列也称作最长公共子串(不要求连续)，英文缩写为LCS（Longest Common Subsequence）。其定义是，一个序列 S ，如果分别是两个或多个已知序列的子序列，且是所有符合此条件序列中最长的，则 S 称为已知序列的最长公共子序列。
输入
第一行给出一个整数N(0<N<100)表示待测数据组数
接下来每组数据两行，分别为待测的两组字符串。每个字符串长度不大于1000.
输出
每组测试数据输出一个整数，表示最长公共子序列长度。每组结果占一行。
样例输入
2
asdf
adfsd
123abc
abc123abc
样例输出
3
6*/