#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k;
	cin>>n;
	map<int,int> my;
	for(i=0;i<n;i++)
	{
		cin>>k;
		my[k]=1;
		cin>>m;
		for(j=0;j<m;j++)
		{
			cin>>k;
			my[k]=1;
		}
	}
	cout<<my.size()-n;
}
