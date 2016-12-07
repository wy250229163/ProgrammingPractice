#include<stdio.h>
int new_Factoral(int N)
{
	int i=1,sum=1;
	if(N==1)
		return 1;
	else
	{
		while(i<=N)
		{
			sum*=i;
			i+=2;
		}					
	}
	sum+=new_Factoral(N-1);
	return sum;
}
int main()
{
	int i,num,s;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&s);
		printf("%d\n",new_Factoral(s));
	}
} 
