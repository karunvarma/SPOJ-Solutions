#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	while(n)
	{
		long long i,j,ab[n+1];
		
		for(i=1;i<=n;i++)
		ab[i]=0;
		
		char a[21];
		map<string,vector<long long > > my;
		j=n;
		while(n--)
		{
			cin>>a;
			my[a].push_back(n);
	    }
	    for(map<string,vector<long long> >::iterator it=my.begin();it!=my.end();it++)
	    {
	    	ab[((*it).second).size()]++;
		}
		for(i=1;i<=j;i++)
		{
			cout<<ab[i]<<endl;
		}
		cin>>n>>m;
	}
}
