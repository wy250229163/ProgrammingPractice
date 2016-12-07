#include<iostream>
#include<stack>
#include<vector>
#include<list>

using namespace std;

vector<list<int>>Adj;
vector<int>inDegree;
stack<int>stk;

void CreateGraph()
{
	int n,m,v1,v2;
	cin>>n>>m;
	Adj.assign(n,list<int>());
	inDegree.assign(n,0);
	while(m--)
	{
		cin>>v1>>v2;
		Adj[v1].push_back(v2);
		inDegree[v2]++;
	}
	for(int i=0;i<n;i++)
		if(inDegree[i]==0)
			stk.push(i);
}

void topsort()
{
	int v,counter=0;
	while(!stk.empty())
	{
		v=stk.top();stk.pop();
		counter++;
		for(auto it=Adj[v].begin();it!=Adj[v].end();it++)
		{
			inDegree[*it]--;
			if(inDegree[*it]==0)
				stk.push(*it);
		}
	}
	if(counter!=inDegree.size())
		cout<<"Graph has a cycle!"<<endl;
	for(auto item:vec)
		cout<<item<<" ";
	cout<<endl;
}

int main()
{
	CreateGraph();
	topsort();
}