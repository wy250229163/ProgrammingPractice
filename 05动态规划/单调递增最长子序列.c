#include<stdio.h>
#include<string.h>

int main(void)
{
	int n,i,j;
	char str[10000];
	int len[10000];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		int max=0;
		int maxlen=1;
		for(i=0;i<strlen(str);i++)
		{
			len[i]=1;
			max=0;
			for(j=i-1;j>=0;j--)
			{
				if(str[j]<str[i] && len[j]>max)
					max=len[j];
			}
			len[i]+=max;
			if(len[i]>maxlen)
				maxlen=len[i];
		}
		printf("%d\n",maxlen);
		
	}
}
 