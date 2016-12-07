#include<stdio.h>
void numSmoke(int num,int k,int *sum)
{
	int t,p;
	t=num/k;
	p=num%k;
	*sum+=t;
	if((t+p)>=k)
		numSmoke(t+p,k,sum);
	else
		return ;

}
int main()
{
	int n,sum=0;
	int cignum,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&cignum,&k);
		sum=cignum;
		numSmoke(cignum,k,&sum);
		printf("%d\n",sum); 
	}
} 
