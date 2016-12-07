#include <stdio.h>  
#include <string.h>
int count=0;
void match(char *a,char *b)
{
	if(*a=='\0')
	{
		count++;
		return ;
	}
	else if(*a==*b)
	{
		match((a+1),(b+1));
	}
	else
	{
		return ;
	}
}

int main()  
{  
    int n;  
    char a[200],b[1200];  
    scanf("%d",&n);  
    while(n--)  
    {  
        count=0;  
        int i=0,len=0;
        scanf("%s%s",a,b);  
        len=strlen(b);
        for(i=0;i<len;i++)
        	match(a,b+i);
        printf("%d\n",count);  
    }  
    return 0;  
}  