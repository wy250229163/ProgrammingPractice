/******
还有特殊情况没考虑到： max(add(1,2),7)
*******/
#include<cstdio>
#include<cstring>
#include<stack> 

using namespace std;
stack<char> oper;
stack<int> num;

void deal_Num(char *s,int start,int end)
{
	int i;
	int a,temp=0,k=1;
	for(i=end;i>=start;i--)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			temp+=(s[i]-'0')*k;
			k*=10;
		}
		if(s[i]==',')
		{
			a=temp;
			temp=0;
			k=1;
		} 
	}
	num.push(temp);
	num.push(a); 
}

int Caculate(char s,int a,int b)
{
	switch(s)
	{
		case 'n':
			return a<b?a:b;
		case 'x':
			return a>b?a:b;
		case 'd':
			return a+b;
	}
}

int main(void)
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		char str[300];
		scanf("%s",&str);
		int len=strlen(str);
		int i,j,k;
		int a,b,c;
		i=j=k=0;
		if(str[0]>'0' && str[0]<'9')
			printf("%s\n",str);
		else
		{
			for(i=0;i<len;i++)
			{
				if(str[i]=='(')
					oper.push(str[i-1]); 
				if(str[i-1]=='(' && str[i]>='0' && str[i]<='9')
					j=i;
				if(str[i]==')' && str[i-1]>='0' && str[i-1]<='9')
					deal_Num(str,j,i-1);
				if(str[i]==')')
				{
					a=num.top();num.pop();
					b=num.top();num.pop(); 
					num.push(Caculate(oper.top(),a,b));
					oper.pop();
				}
			}
			printf("%d\n",num.top());
			num.pop();
		}
	} 
}


//表达式求值
//时间限制：3000 ms  |  内存限制：65535 KB
//难度：3
//描述
//Dr.Kong设计的机器人卡多掌握了加减法运算以后，最近又学会了一些简单的函数求值，比如，它知道函数min(20,23)的值是20 ，add(10,98) 的值是108等等。经过训练，Dr.Kong设计的机器人卡多甚至会计算一种嵌套的更复杂的表达式。
//假设表达式可以简单定义为:
//1. 一个正的十进制数 x 是一个表达式。
//2. 如果 x 和 y 是 表达式，则 函数min(x,y )也是表达式,其值为x,y 中的最小数。
//3. 如果 x 和 y 是 表达式，则 函数max(x,y )也是表达式,其值为x,y 中的最大数。
//4．如果 x 和 y 是 表达式，则 函数add(x,y )也是表达式,其值为x,y 之和。
//例如， 表达式 max(add(1,2),7) 的值为 7。
//请你编写程序，对于给定的一组表达式，帮助 Dr.Kong 算出正确答案，以便校对卡多计算的正误。
//输入
//第一行： N 表示要计算的表达式个数 （1≤ N ≤ 10） 
//接下来有N行， 每行是一个字符串，表示待求值的表达式
//（表达式中不会有多余的空格，每行不超过300个字符，表达式中出现的十进制数都不
//超过1000。）
//输出
//输出有N行，每一行对应一个表达式的值。
//样例输入
//3
//add(1,2) 
//max(1,999) 
//add(min(1,1000),add(100,99)) 
//样例输出
//3
//999
//200