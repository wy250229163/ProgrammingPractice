#include<stdio.h>
#include<string.h>

int maxValue=0;
int len=0; 	//用来存数据的个数

int max(int a,int b)
{
	if(a <= b)
		return b;
	else
		return a;
}

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

int DP(int* num,int *sum,int start,int end)  //动态规划 复杂度O(N) 
{
	int i;
 	memset(sum,0,sizeof(int));
 	sum[start]=num[start];
 	sum[start+1]=num[start+1];
 	sum[start+2]=num[start]+num[start+2];
 	for(i=(start+3);i<=end;i++)
 		sum[i]=max(sum[i-2],sum[i-3])+num[i];
	maxValue=sum[start];
	for(i=start;i<=end;i++)
		if(sum[i]>maxValue)
			maxValue=sum[i];
	return maxValue;
}

int main()
{
	int N,i,j;
	scanf("%d",&N);
	while(N--)
	{
		char a[100];
		int value[100];
		int sumValue[100];
		memset(value,0,sizeof(int));
		scanf("%s",a);
		len=coverTonum(a,value);

		if(len<=3)
		{
			maxValue=value[0];
			for(i=0;i<len;i++)
				if(value[i]>maxValue)
					maxValue=value[i];
			printf("maxValue : %d\n",maxValue);			
		}
		else
			printf("maxValue : %d\n",max( DP(value,sumValue,0,len-2) , DP(value,sumValue,1,len-1) ));
	} 
}
 
