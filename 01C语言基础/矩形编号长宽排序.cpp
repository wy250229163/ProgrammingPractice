#include<cstdio>
#include<algorithm>

using namespace std;

struct retange
{
	int no;
	int length;
	int width;
}rec[1005];

int compareFunc(struct retange p,struct retange q)
{
	if(p.no==q.no)
	{
		if(p.length==q.length)
		{
			return p.width<q.width;
		}
		else
			return p.length<q.length;
	}
	else
		return p.no<q.no;
}
int isEqual(struct retange p,struct retange q)
{
	return (p.no==q.no)&&(p.length==q.length)&&(p.width==q.width);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		int i,temp;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&rec[i].no,&rec[i].length,&rec[i].width);
			if(rec[i].length<rec[i].width)
				temp=rec[i].length;rec[i].length=rec[i].width;rec[i].width=temp;
		}
		sort(rec,rec+m,compareFunc);
		for(i=1;i<m;i++)
		{
			if(i==1)
			{
				if(isEqual(rec[0],rec[1]))
					printf("%d %d %d\n",rec[1].no,rec[1].length,rec[1].width);
				else
				{
					printf("%d %d %d\n",rec[0].no,rec[0].length,rec[0].width);
					printf("%d %d %d\n",rec[1].no,rec[1].length,rec[1].width);
				}
			}
			else
			{
				if(isEqual(rec[i],rec[i-1]))
					continue;
				else
					printf("%d %d %d\n",rec[i].no,rec[i].length,rec[i].width);
			}
		}
	}
	return 0;
}
