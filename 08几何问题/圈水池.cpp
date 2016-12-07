#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0xfffffff ;

struct Point{
    int x,y ;
};

Point p[101],s[101] ;
int top ;

int direction(Point p1,Point p2,Point p3)
{
    return (p3.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p3.y-p1.y) ;
}

int dis(Point p1,Point p2)
{
    return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y) ;
} 

int cmp(Point p1,Point p2)//极角排序 
{
    int temp=direction(p[0],p1,p2) ;
    if(temp<0)return 1 ;
    if(temp==0 && dis(p[0],p1)<dis(p[0],p2))return 1 ;
    return 0 ;
}

int xycmp(Point p1,Point p2) //输出时按x、y大小排序 
{
	if(p1.x==p2.x)
	{
		if(p1.y<=p2.y)
			return 1;
		else
			return 0;
	}
	else if(p1.x<p2.x)
		return 1;
	else
		return 0;
}

void Graham(int n)
{
    int pos,minx,miny ;
    minx=miny=INF ;
    for(int i=0 ;i<n ;i++)
        if(p[i].x<minx || (p[i].x==minx && p[i].y<miny))
        {
            minx=p[i].x ;
            miny=p[i].y ;
            pos=i ;
        }
    swap(p[0],p[pos]) ;
    sort(p+1,p+n,cmp) ;
    p[n]=p[0] ;
    s[0]=p[0] ;s[1]=p[1] ;s[2]=p[2] ;
    top=2 ;
    for(int i=3 ;i<=n ;i++)
    {
        while(direction(s[top-1],s[top],p[i])>=0 && top>=2)top-- ;
        s[++top]=p[i] ;
    }
}

int main(void)
{
	int N,i;
	scanf("%d",&N);
	while(N--)
	{
		int m;
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d%d",&p[i].x,&p[i].y); 
		Graham(m);
		sort(s,s+top,xycmp);
		for(i=0;i<top;i++)
			printf("%d %d\n",s[i].x,s[i].y);
	}
	return 0;
}