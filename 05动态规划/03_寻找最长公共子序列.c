#include<stdio.h>
#include<string.h>

int main()
{
	int N,i,j;
	scanf("%d",&N);
	while(N--)
	{
		char str1[1000],str2[1000];
		scanf("%s%s",str1,str2);
		int len1=strlen(str1),len2=strlen(str2);
		int LCS[len1+1][len2+1];
		memset(LCS,0,sizeof(LCS));
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(str1[i-1]==str2[j-1])
					LCS[i][j]=LCS[i-1][j-1]+1;
				else
					LCS[i][j]= LCS[i-1][j]>LCS[i][j-1]? LCS[i-1][j]:LCS[i][j-1];
			}			
		}
		printf("%d\n",LCS[len1][len2]);
	}
}


/*
�����������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
���ǾͲ�����Ĩ���ˣ����⣬��Ҫ�����ľ���дһ�����򣬵ó�����������С�
tip�������������Ҳ����������Ӵ�(��Ҫ������)��Ӣ����дΪLCS��Longest Common Subsequence�����䶨���ǣ�һ������ S ������ֱ�������������֪���е������У��������з��ϴ�������������ģ��� S ��Ϊ��֪���е�����������С�
����
��һ�и���һ������N(0<N<100)��ʾ������������
������ÿ���������У��ֱ�Ϊ����������ַ�����ÿ���ַ������Ȳ�����1000.
���
ÿ������������һ����������ʾ����������г��ȡ�ÿ����ռһ�С�
��������
2
asdf
adfsd
123abc
abc123abc
�������
3
6*/