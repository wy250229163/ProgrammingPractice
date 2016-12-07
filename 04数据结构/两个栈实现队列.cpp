#include<iostream>
#include<stack>
using namespace std;
stack<int> A;
stack<int> B;
void Equeue(int k)
{
	A.push(k);
}
int Dqueue()
{
	if(A.empty() && B.empty())
	{
		cerr<<"Error:Empty!"<<endl;	
	}
	else
	{
		if(B.empty())
		{
			while(!A.empty())
			{
				B.push(A.top());
				A.pop();
			}
		}
		int temp=B.top();
		B.pop();
		return temp;		
	}
}
int main()
{
	for(int i=0;i<5;i++)
		Equeue(i);
	for(int j=0;j<5;j++)
		printf("%d ",Dqueue());
}