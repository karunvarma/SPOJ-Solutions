#include<bits/stdc++.h>
using namespace std;

long double dp[600][2000];

long double solve(long long n,long long k)
{
	if(n>k)
	return 0.0;
	
	if(n==0 && k==0)
	return 1.0;
	
	if(n==0)
	return 0.0;
	
	if(dp[n][k]!=-1.0)
	{
	   return dp[n][k];
    }
	long double ans=0.0;
	
	for(long long i=1;i<7;i++)
	{
		if(k>=i)
		{
			ans+= solve(n-1,k-i);
		}
	}
	ans=ans/6.0;
	dp[n][k]=ans;
	return dp[n][k];
}

int main()
{
	for(long long i=0;i<600;i++)
	{
		for(long long j=0;j<2000;j++)
		{
			dp[i][j]=-1.0;
		}
	}
	
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,k,j;
		long double i;
		cin>>n>>k;
		
		if(n>=600 || k>=2000)
		{
			cout<<"0\n";
			continue;
		}
		i=solve(n,k)*100;
		j=(long long)i;
		cout<<j<<endl;
	}
}
