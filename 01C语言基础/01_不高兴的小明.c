#include<stdio.h>
int main()
{
	int num=0;
	int a,b;
	int i,j,max,day;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		max=8;
		day=0;
		for(j=1;j<=7;j++)
		{
			scanf("%d%d",&a,&b);
			if((a+b)>8 && (a+b)>max)
			{
				max=a+b;
			 	day=j;
			}
		}
	printf("%d\n",day);
	}
	return 0;
}
