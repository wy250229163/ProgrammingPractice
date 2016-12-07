#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#include <sstream>

using namespace std;

string add(string s1,string s2)
{
	string s;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int len1=s1.size();
	int len2=s2.size();
	int minlen,maxlen;
	minlen=len1<len2?len1:len2;
	maxlen=len1>len2?len1:len2;
	int i=0,cmp=0;
	for(i=0;i<minlen;i++)
	{
		cmp=cmp+(s1[i]-'0')+(s2[i]-'0');
		s+=(cmp%10+'0');
		cmp/=10;	
	}
	if(minlen==maxlen && i==minlen && cmp!=0)
		s+=cmp+'0';
	while(i<maxlen)
	{
		if(len1>len2)
		{
			cmp=cmp+(s1[i]-'0');
			s+=(cmp%10+'0');
			cmp/=10;
		}
		else
		{
			cmp=cmp+(s2[i]-'0');
			s+=(cmp%10+'0');
			cmp/=10;
		}
		i++;
		if(i==maxlen && cmp!=0)
			s+=(cmp+'0');
	}
	reverse(s.begin(),s.end());
	return s;
} 

int main(void)
{
	int i;
	string s1,s2,s3,s;
	while(1)
	{
		getline(cin,s);
		if(s=="-1") break;
		istringstream cut(s);
		cut>>s1>>s2>>s3;
		for(i=1;i<=97;i++)
		{
			s=add(s1,s2);
			s=add(s,s3);
			s1=s2;
			s2=s3;
			s3=s;
		}
		cout<<s<<endl;
	}
}