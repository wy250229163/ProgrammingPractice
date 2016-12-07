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
void sumPrim(int n)
{
	int a[n];
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(isPrim(a[i]))
			sum+=a[i];
	}
	printf("%d\n",sum);
}
int main()
{
	int n,num;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&num);
		sumPrim(num);
	}
} 
