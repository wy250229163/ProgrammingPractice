#include<stdio.h>

int main()
{
	char a,b,c;
	char i,flag;
	scanf("%d%d%d",&a,&b,&c);
	if(a<3&&b<5&&c<7&&a>=0&&b>=0&&c>=0)
	{
		for(i=10;i<=100;i++)
		{
			if(i%3==a && i%5==b && i%7==c)
			{
				printf("%d",i);
				flag=1;
				break;
			}
		}
		if(flag!=1)
			printf("No answer"); 
	}
	else
	{
		printf("Illegal input!");
	}
	return 0;
}
