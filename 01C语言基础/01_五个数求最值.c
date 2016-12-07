#include<stdio.h>
int main(void)
{
	int a[5],i;
	int min,max;
	scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	min=a[0];
	max=a[0];
	for(i=1;i<5;i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	printf("%d %d",min,max);
} 
