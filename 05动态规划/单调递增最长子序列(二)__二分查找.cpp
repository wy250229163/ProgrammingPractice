//(��)��(һ)����������ڣ�����Դ��������������O(N^2)������������ˡ� (��)����O(NlogN)���㷨������ 

#include<cstdio>
#include<cstring>
using namespace std;

int binarySearch(int* a,int len,int k)
{
	int start,mid,end;
	start=1;
	end=len;
	while(start<=end)
	{
		mid=(start+end)>>1;
		if(k==a[mid])
			return mid;
		if(k>a[mid])
			start=mid+1;
		else
			end=mid-1;
	}
	return start;
}

int main(void)
{
	int n,i,pos,len;
	while(scanf("%d",&n)!=EOF)
	{
		int num[n];
		int dp[n];
		memset(dp,0,sizeof(dp));
		len=1;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		dp[1]=num[0];
		for(i=1;i<n;i++)
		{
			pos=binarySearch(dp,len,num[i]);
			dp[pos]=num[i];
			if(pos>len)
				len=pos;
		}
		printf("%d\n",len);
	}
}
