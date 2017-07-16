#include<bits/stdc++.h>
using namespace std;

long long dp[100][4];

long long solve(long long n,long long i)
{
	if(n==1)
	return 1;
	
	if(dp[n][i]!=-1)
	return dp[n][i];
	
	if(i==1)
	{
		dp[n][1]=solve(n-1,1)+solve(n-1,2);
	}
	if(i==2)
	{
		dp[n][2]=solve(n-1,1)+solve(n-1,2)+solve(n-1,3);
	}
	if(i==3)
	{
		dp[n][3]=solve(n-1,2)+solve(n-1,3);
	}
	return dp[n][i];
}

int main()
{
	long long n,i,j,k;
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=3;j++)
		{
		    dp[i][j]=-1;	
		}
	}
	
	i=solve(n,1)+solve(n,2)+solve(n,3);
	cout<<i<<endl;
}
