#include<stdio.h>
#include<math.h>

int main()
{
	int n,sum;
	double L,D,R;
	double li;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf",&L,&D,&R);
		li=4*R*R-D*D;
		if(li>0)
		{
			sum=(int)ceil(L/sqrt(li));
			printf("%d\n",sum);
		}	
		else
			printf("%s\n","impossible");
	}
	return 0;
}
 