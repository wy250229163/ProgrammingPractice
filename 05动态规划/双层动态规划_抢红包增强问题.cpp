#include<cstdio>
#include<cstring>

using namespace std;
int max(int a,int b)
{
    return a>b?a:b ;
}
int main()
{
    int m,n,i,j;
    while(~scanf("%d%d",&m,&n))
    {
        int num[m+4][n+4];
        int dp[m+4];
        int temp;
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        for(i=3;i<m+3;i++) //每一行上边的动态规划
        {
            for(j=3;j<n+3;j++)
            {
                scanf("%d",&temp);
                num[i][j]=max(num[i][j-2],num[i][j-3])+temp;
            }           
        }
        for(i=3;i<m+3;i++) //列方向上的动态规划
        {
            dp[i]=max(dp[i-2],dp[i-3])+max(num[i][n+1],num[i][n+2]);
        }
        printf("%d\n",max(dp[m+1],dp[m+2]));
    }
    return 0;
} 