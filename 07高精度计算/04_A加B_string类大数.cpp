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
	int n,i=1;
	cin>>n;
	getchar();
	while(n--)
	{
		string s,s1,s2;
		getline(cin,s);
		istringstream cut(s);
		cut>>s1>>s2;
		s=add(s1,s2);
		cout<<"Case "<<i<<":"<<endl;
		cout<<s1<<" + "<<s2<<" = "<<s<<endl; 
		i++;		
	}
} 



//A+B Problem II
//时间限制：3000 ms  |  内存限制：65535 KB
//难度：3
//描述
//I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
//
//A,B must be positive.
//
//输入
//The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.
//输出
//For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation.
//样例输入
//2
//1 2
//112233445566778899 998877665544332211
//样例输出
//Case 1:
//1 + 2 = 3
//Case 2:
//112233445566778899 + 998877665544332211 = 1111111111111111110