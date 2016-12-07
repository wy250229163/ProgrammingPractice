#include<stdio.h>
#include<string.h>
int main()
{
	int ptrI=0,ptrJ=0,counts=0,length1,count1,length2,count2,i;
	char s1[5000];
	char s2[5000];
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		length1=strlen(s1);
		length2=strlen(s2);
		for(i=0;i<length1;i++)
		{
			if(s1[i]=='-') count1++;
			if(s2[i]=='-') count2++;			
		}		
		if(length1!=length2 || count1!=count2)
		{
			printf("%s\n","-1");
			return 0;
		}
		ptrI=0;ptrJ=0;counts=0;count1=0;count2=0; 
		for(;;)
		{
			while(ptrI<length1 && s1[ptrI++]!='-');
			while(ptrJ<length2 && s2[ptrJ++]!='-');
			if(ptrI>ptrJ)
				counts+=(ptrI-ptrJ);
			else
				counts+=(ptrJ-ptrI);
			if(ptrI==length1 && ptrJ==length2)
				break;	
		}
		printf("%d\n",counts);
	}
}
 
 