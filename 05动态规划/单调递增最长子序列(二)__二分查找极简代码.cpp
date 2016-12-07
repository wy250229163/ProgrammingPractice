//(二)与(一)的区别就在于，二针对大数据量的情况，O(N^2)的情况不适用了。 (二)采用O(NlogN)的算法方法、 
#include<cstdio>  
#include<algorithm>  
using namespace std;  
const int MAX=100100;  
int num[MAX],top=0;  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        scanf("%d",&num[0]);  
        top=1;  
        for(int i=1;i!=n;i++)  
        {  
            scanf("%d",&num[i]);  
            int * p=lower_bound(num,num+top,num[i]);  
            if(p-num==top) ++top;  
            *p=num[i];  
        }  
        printf("%d\n",top);  
    }  
      
}   