#include<stdio.h>
#include<string.h>

int maxValue; 
int len=0; 	//用来存数据的个数 

int countNum(char* a,int start,int end) //此函数将数字字符串段转为数字 
{
	int result=0;
	int i=0,m=0;
	int j=start-end;
	int pownum;
	for(i=0;i<=(end-start);i++)
	{
		pownum=1;
		for(m=0;m<i;m++)
			pownum*=10;
		result+=(a[end-i]-'0') * pownum;
		j--;
	}
	return result;
}
int coverTonum(char* a,int* num)  //此函数从字符串中提取所有数字 
{
	int i=0,k=0;
	int tempi=-1; //存储找到一个逗号时的索引值
	while(*(a+i)!='\0')
	{
		if(*(a+i)==',')
		{
			num[k]=countNum(a,tempi+1,i-1);
			tempi=i;
			k++;
		}
		i++;	
	}	
	num[k]=countNum(a,tempi+1,i-1);  //最后一个逗号右边应该还有一个数 
	return k+1;
}

void DFS(int* num,int* vis,int n,int value)
{
	int i;
	if(value>maxValue)
		maxValue=value;
	if(n>len)
		return ;
	else
	{
		vis[n]=1;
		if(vis[0]==1 && vis[len-1]==1)
			return ;
		DFS(num,vis,n+2,value+num[n]);
		vis[n]=0;
		DFS(num,vis,n+1,value); 
	}
}

int main()
{
	int N,i;
	scanf("%d",&N);
	while(N--)
	{
		char a[100];
		int num[100];
		int vis[100];
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		scanf("%s",a);
		len=coverTonum(a,num);
		DFS(num,vis,0,0);
		printf("maxValue : %d\n",maxValue);
	}
}
