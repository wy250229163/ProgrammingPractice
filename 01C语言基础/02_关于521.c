#include<stdio.h>
#include<string.h>
int main()
{
	int start,end,i,j=0,k=10;
	int count1,count2;
	char w[7]={0};
	int a[1000000]={0};
	for(i=100;i<1000000;i++)
	{
		sprintf(w,"%d",i);
		if(strstr(w,"5")!=NULL && strstr(w,"2")!=NULL && strstr(w,"1")!=NULL)
		{
			a[i]++;
			if(strstr(w,"521")!=NULL)
			{
				a[i]++;
			}
		}		
	}
	while(scanf("%d%d",&start,&end)!=EOF)
	{
		count1=0;
		count2=0;
	 	for(i=start;i<=end;i++)
		{
			if(a[i]==1)
				count1++;
			if(a[i]==2)
			{
				count1++;
				count2++;
			}
		}
		j++;
		printf("Case %d:%d %d\n",j,count1,count2);
	}
	return 0;
}

