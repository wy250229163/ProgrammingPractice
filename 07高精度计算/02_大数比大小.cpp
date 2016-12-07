#include<cstdio>
#include<cstring>

using namespace std;

int main(void)
{
	char a[1001],b[1001];
	int flag;
	while(1)
	{
		scanf("%s%s",a,b);
		if(a[0]=='0' && b[0]=='0') break;
		int lena=strlen(a);
		int lenb=strlen(b);
		int pos;
		if(strcmp(a,b)==0)
		{
			flag=2;		
		}
		else
		{
			if(a[0]!='-' && b[0]!='-')
			{
				if(lena>lenb)
					flag=0;	
				else if(lena<lenb)
					flag=1;
				else
				{
					pos=0;
					while(a[pos]==b[pos]) pos++;
					if(a[pos]>b[pos])
						flag=0;
					else
						flag=1;
				} 
			}
			else if(a[0]=='-' && b[0]=='-')
			{
				if(lena>lenb)
					flag=1;	
				else if(lena<lenb)
					flag=0;
				else
				{
					pos=1;
					while(a[pos]==b[pos]) pos++;
					if(a[pos]>b[pos])
						flag=1;
					else
						flag=0;
				}
			}
			else
			{
				if(b[0]=='-')
					flag=0;
				else if(a[0]=='-')
					flag=1;
			}			
		}
		switch(flag)
		{
			case 0:
				printf("a>b\n");
				break;
			case 1:
				printf("a<b\n");
				break;
			case 2:
				printf("a==b\n");
				break;	
		} 
	}
} 




//比大小
//时间限制：3000 ms  |  内存限制：65535 KB
//难度：2
//描述
//给你两个很大的数，你能不能判断出他们两个数的大小呢？
//
//比如123456789123456789要大于-123456
//
//输入
//每组测试数据占一行，输入两个不超过1000位的10进制整数a,b
//数据保证输入的a,b没有前缀的0。
//如果输入0 0表示输入结束。测试数据组数不超过10组
//输出
//如果a>b则输出“a>b”，如果a<b则输出“a<b”,如果相等则输出“a==b”。
//样例输入
//111111111111111111111111111 88888888888888888888
//-1111111111111111111111111  22222222
//0 0
//样例输出
//a>b
//a<b
//上传者
//张云聪