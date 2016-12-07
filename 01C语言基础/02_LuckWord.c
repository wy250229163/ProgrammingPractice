#include<stdio.h>
#include<math.h>
int isPrim(int n)
{
	int temp,i;
	temp=sqrt(n);
	if(n<=1)
		return 0;
	else if(n==2)
		return 1;
	for(i=2;i<=temp;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
void  isLucky(char *a)
{
	char *p;
	int i=0,timee[26]={0};
	int max,min;
	p=a;
	while(*p)
		timee[(*p++)-'a']++;
	while(timee[i++]==0);
	max=min=timee[i-1];
	for(i=0;i<26;i++)
	{
		if(max<timee[i])
			max=timee[i];
		else if(min>timee[i]&&timee[i]!=0)
			min=timee[i];
	}
	if(isPrim(max-min))
	{
		printf("Lucky Word\n");
		printf("%d\n",max-min);
	}
	else
	{
		printf("No Answer\n");
		printf("%d\n",0);
	}
}
int main()
{
	int n;
	char words[100];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",words);
		isLucky(words);
	}
} 
