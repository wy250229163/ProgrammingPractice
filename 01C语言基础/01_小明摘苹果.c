#include<stdio.h>
int main()
{
	int num[10];
	int a,b,n,i;
	scanf("%d",&n);
	while(n--)
	{
		b=0;
		for(i=0;i<10;i++)
			scanf("%d",&num[i]);
		scanf("%d",&a);
		a+=30;
		for(i=0;i<10;i++)
		{
			if(a>=num[i])
			b++;
		}
		printf("%d\n",b);
	}
	return 0;
}