#include<stdio.h>
int main()
{
	int num,i;
	int n,m,x,y;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d",&n,&m);
		if(m%2!=0)
		{
			printf("No answer\n");		
		}
		else
		{
			y=m/2-n;
			x=n-y;
			if(x<0 || y<0)
			{
				printf("No answer\n");	
			}
			else
			{
				printf("%d %d\n",x,y);
			}	
		}	
	}
	return 0;
} 
