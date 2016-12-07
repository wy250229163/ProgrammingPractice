#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string multiply(string s,int x)
{
	reverse(s.begin(),s.end());
	int cmp=0;
	for(int i=0;i<s.size();i++)
	{
		cmp=(s[i]-'0')*x+cmp;
		s[i]=cmp%10+'0';
		cmp/=10;
	}
	while(cmp)
	{
		s+=(cmp%10+'0');
		cmp/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

int main(void)
{
	string s="1";
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		s=multiply(s,i);
	cout<<s<<endl;
} 



/*
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<math.h>

#define mes(x) memset(x, 0, sizeof(x))
typedef long long ll;
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define min(x, y) (x)<(y)?(x):(y)
#define max(x, y) (x)>(y)?(x):(y)
using namespace std;
//n的范围是１～10000
#define MOD 100000000
int main()
{
    int n, i, j, c;
    while( cin >> n)
    {
        ll *fac = new ll[4500]();
        ll sum;
        fac[0] = 1;
        int m = 0;
        for(i = 2; i <= n; ++i)
        {
            c = 0;
            for(j = 0; j <= m; ++j)
            {
                sum = fac[j]*i + c;
                c = sum/MOD;
                fac[j] = sum%MOD;
            }
            if(c>0)
            {
                fac[++m] = c;
            }
        }
        printf("%lld", fac[m]);
        for(int i = m-1; i >= 0; --i)
            printf("%08lld",fac[i]);
//    printf("%08lld", fac[i]);
// 一个空间存８个长度　例如100000008%100000000 = 8 %08ll补全８前面的零
        cout << endl;
        delete [] fac;
    }
    return 0;
}
*/ 

//大数阶乘
//时间限制：3000 ms  |  内存限制：65535 KB
//难度：3
//描述
//我们都知道如何计算一个数的阶乘，可是，如果这个数很大呢，我们该如何去计算它并输出它？
//输入
//输入一个整数m(0<m<=5000)
//输出
//输出m的阶乘，并在输出结束之后输入一个换行符
//样例输入
//50
//样例输出
//30414093201713378043612608166064768844377641568960512000000000000
//来源
//经典题目
//上传者
//张云聪