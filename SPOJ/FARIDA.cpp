#include<bits/stdc++.h>
using namespace std;

long long dp[100001][2],a[100001],n;

long long solve(long long i,bool p)
{
	if(p && dp[i][1]!=-1)
	return dp[i][1];
	if(!p && dp[i][0]!=-1)
	return dp[i][0];
	
	if(i==n-1 && p)
	return a[i];
	
	if(i==n-2 && p)
	{
		dp[i][1]=max(a[i],a[i+1]);
		return dp[i][1];
	}
	if(i==n-2)
	{
		dp[i][0]=a[i+1];
		return dp[i][0];
	}
	
	if(p==true)
	{
		dp[i][1]=max(a[i]+solve(i+1,false),solve(i+1,true));
		return dp[i][1];
	}
	else
	{
		dp[i][0]=solve(i+1,true);
		return dp[i][0];
	}
}

int main()
{
	long long t,u=0;
	cin>>t;
	while(t--)
	{
		u++;
		long long i;
		cin>>n;
		for(i=0;i<n;i++)
		{
			dp[i][0]=dp[i][1]=-1;
			cin>>a[i];
		}
		if(n==0)
		{
			i=0;
			goto hell;
		}
		
		i=solve(0,true);
		hell:
		cout<<"Case "<<u<<": "<<i<<endl;
	}
}
