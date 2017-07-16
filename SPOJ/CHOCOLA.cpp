#include<bits/stdc++.h>
using namespace std;

int v[1000],h[1000],dp[1001][1001],n,m;

int solve(int i,int j)
{
	if(i>=n && j>=m)
	return 0;
	
	if(i>=n)
	{
		int s=0;
		for(;j<m;j++)
		s+=v[j];
		
		return n*s;
	}
	
	if(j>=m)
	{
		int s=0;
		for(;i<n;i++)
		s+=h[i];
		
		return m*s;
	}
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	dp[i][j]=min(h[i]*j+solve(i+1,j),v[j]*i+solve(i,j+1));
	
	return dp[i][j];
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k;
		cin>>m>>n;
		
	    for(i=1;i<m;i++)
		cin>>v[i];
		for(i=1;i<n;i++)
		cin>>h[i];
		
		sort(v+1,v+m,cmp);
		sort(h+1,h+n,cmp);
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			dp[i][j]=-1;
		}
		
		cout<<solve(1,1)<<endl;	
			
	}
}
