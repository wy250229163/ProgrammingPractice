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
void lenPrim(int n)
{
	int t1,t2;
	t1=t2=n;
	if(isPrim(n))
		printf("%d %d\n",n,0);
	else
	{
		while(!isPrim(--t1));
		while(!isPrim(++t2));
		if((n-t1)<=(t2-n))
			printf("%d %d\n",t1,n-t1);
		else
			printf("%d %d\n",t2,t2-n);
	}
}
int main()
{
	int n,num;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&num);
		lenPrim(num);
	}
	return 0;
} 
