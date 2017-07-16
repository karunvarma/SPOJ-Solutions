#include<bits/stdc++.h>
using namespace std;

long long dp[5001][5001],a[5001],b[5001];

long long dif(long long x,long long y)
{
	if(x>y)
	return x-y;
	else
	return y-x;
}

long long solve(long long n,long long m)
{
	if(n==0)
	{
	    return 0ll;
    }
	if(n>m)
	{
	   return (long long)1000*INT_MAX;
    }
	if(dp[n-1][m-1]!=-1)
	{
		return dp[n-1][m-1];
	}
	long long p,q;
	p=dif(a[n-1],b[m-1])+solve(n-1,m-1);
	q=solve(n,m-1);
	
	dp[n-1][m-1]=min(p,q);
	
	return dp[n-1][m-1];
}

int main()
{
	long long n,m,i,j,k;
	cin>>n>>m;
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(j=0;j<m;j++)
	{
		cin>>b[j];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		dp[i][j]=-1;
	}
	sort(a,a+n);
	sort(b,b+m);
	i=solve(n,m);
	cout<<i<<endl;
}
