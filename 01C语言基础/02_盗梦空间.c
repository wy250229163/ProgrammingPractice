#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n,m,temp,level=0,sum=0;
	char words[10];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",words);
			if(strcmp("IN",words)==0)
				level++;
			if(strcmp("STAY",words)==0)
			{
				scanf("%d",&temp);
				sum+=temp*60/(int)pow(20,level);
			}
			if(strcmp("OUT",words)==0)
				level--;		
		}
		printf("%d\n",sum);
		sum=0;	
	}
	return 0;
}
 