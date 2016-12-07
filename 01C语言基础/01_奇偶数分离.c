#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char i,num;
	short startodd;
	short starteven;
	short intI[28];
	scanf("%d",&num);
	if(num<2||num>=30)
	{
		printf("Illegal number!\n");
		exit(1);	
	}

	for(i=0;i<num;i++)
	{
		scanf("%d",&intI[i]);
		if(intI[i]<2||intI[i]>10000)
		{
			printf("Illegal number!\n");
			exit(1);
		}
	}
	printf("\n");
	for(i=0;i<num;i++)
	{
		startodd=1;
		starteven=2;
		do
		{
			printf("%d ",startodd);
			startodd+=2;
		}while(startodd<=intI[i]);
		printf("\n");
		do
		{
			printf("%d ",starteven);
			starteven+=2;
		}while(starteven<=intI[i]);
		printf("\n");
		printf("\n");
	}
	return 0;
}

