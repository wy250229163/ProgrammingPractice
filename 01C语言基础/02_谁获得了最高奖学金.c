#include<stdio.h>
struct student
{
	char name[20];
	int avrgrade;
	int classgrade;
	char isLeader;
	char isWest;
	int numpaper;
	int money;
};
int main()
{
	int i,n,num,pnum,sum;
	struct student stu[100];
	scanf("%d",&n);
	while(n--)
	{
		pnum=0; 
		sum=0;
		scanf("%d",&num);
//		stu=(struct student *)malloc(sizeof(struct student)*num);
		for(i=0;i<num;i++)
		{
//			scanf("%s%d%d%c%c%d",&stu[i]->name,&stu[i]->avrgrade,&stu[i]->classgrade,&stu[i]->isLeader,&stu[i]->isWest,&stu[i]->numpaper);
			scanf("%s%d%d",&stu[i].name,&stu[i].avrgrade,&stu[i].classgrade);
			getchar();
			scanf("%c",&stu[i].isLeader);
			getchar();
			scanf("%c%d",&stu[i].isWest,&stu[i].numpaper);
		}
//		printf("%s %d %d %c %c %d",stu[0]->name,stu[0]->avrgrade,stu[0]->classgrade,stu[0]->isLeader,stu[0]->isWest,stu[0]->numpaper);		
//		printf("%s %d %d %c %c %d",stu[0].name,stu[0].avrgrade,stu[0].classgrade,stu[0].isLeader,stu[0].isWest,stu[0].numpaper);
		for(i=0;i<num;i++)
		{
			stu[i].money=0;
			if(stu[i].avrgrade>80&&stu[i].numpaper>=1)
				stu[i].money+=8000;
			if(stu[i].avrgrade>85&&stu[i].classgrade>80)
				stu[i].money+=4000;
			if(stu[i].avrgrade>90)
				stu[i].money+=2000;
			if(stu[i].avrgrade>85&&stu[i].isWest=='Y')
				stu[i].money+=1000;
			if(stu[i].classgrade>80&&stu[i].isLeader=='Y')
				stu[i].money+=850;
			if(stu[i].money>stu[pnum].money)
				pnum=i;
			sum+=stu[i].money;
		}
		printf("%s\n%d\n%d\n",stu[pnum].name,stu[pnum].money,sum);
	}
	return 0;
}
