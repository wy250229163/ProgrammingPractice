#include<stdio.h>
int main()
{
	int i,num;
	int a,b,c,m,tempa,tempb;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d",&a,&b);
		tempa=a;
		tempb=b;
		do
		{
			c=a%b;
			a=b;
			b=c;
		}while(c!=0);
		m=tempa*tempb/a;
		printf("%d %d\n",a,m);		
	}
	return 0;
} 
