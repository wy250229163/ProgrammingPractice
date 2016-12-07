#include<stdio.h>
#include<string.h>

#define max(a,b) a>b?a:b

char str[1010];
int dp[1010][1010]={0};

int main(void)
{
	int N,i,j,len;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",str);
		len=strlen(str);
		for(i=1;i<=len;i++)
		{
			for(j=1;j<=len;j++)
			{
				if(str[i-1]==str[len-j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",len-dp[i-1][j-1]);
	}
	return 0;
}


//回文字符串
//时间限制：3000 ms  |  内存限制：65535 KB
//难度：4
//描述
//所谓回文字符串，就是一个字符串，从左到右读和从右到左读是完全一样的，比如"aba"。当然，我们给你的问题不会再简单到判断一个字符串是不是回文字符串。现在要求你，给你一个字符串，可在任意位置添加字符，最少再添加几个字符，可以使这个字符串成为回文字符串。
//输入
//第一行给出整数N（0<N<100）
//接下来的N行，每行一个字符串，每个字符串长度不超过1000.
//输出
//每行输出所需添加的最少字符数
//样例输入
//1
//Ab3bd
//样例输出
//2