#include<stdio.h>
int main()
{
	int i=0,j=0;
	short num[100];
	char yesorno[100][5];
	do
	{
		int a,b,c;
		short sum;
		scanf("%d",&num[i]);
		if(num[i]==0||num[i]>=1000||num[i]<100)
			break;
		a=(int)num[i]/100;
		b=(int)num[i]/10%10;
		c=(int)num[i]%10;
		sum=a*a*a+b*b*b+c*c*c;
		if(num[i]==sum)
			sprintf(yesorno[i],"Yes");
		else
			sprintf(yesorno[i],"No");
		i++;
	}while(i<100);
	do
	{
		printf("%s\n",yesorno[j]);
		j++;
	}while(j<i);
	return 0;
}
