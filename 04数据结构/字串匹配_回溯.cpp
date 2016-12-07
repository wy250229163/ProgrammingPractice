#include <cstdio>  
#include <cstring>  
int main()  
{  
    int n,count;  
    char a[200],b[1200];  
    scanf("%d",&n);  
    while(n--)  
    {  
        count=0;  
        int i=0,j=0,len;  
        scanf("%s%s",a,b);  
        len=strlen(b);  
        while(i<=len)  
        {  
            if(a[j]=='\0')  
            {  
                count++;  
                i=i-j+1;   
                j=0;  
            }  
            else if(a[j]==b[i])  
            {  
                i++;  
                j++;  
            }  
            else  
            {  
                i=i-j+1; //关键在于回溯  
                j=0;  
            }  
        }  
        printf("%d\n",count);  
    }  
    return 0;  
}  