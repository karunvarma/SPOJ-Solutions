#include<bits/stdc++.h>
using namespace std;

long long a[101][101],dp[101][101],n,m;

long long  scan()
{
    long long  n=0;
    char ch=getchar_unlocked();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar_unlocked();
    }
 
    while (ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar_unlocked();
    }
 
    return n;
}

long long solve(long long i,long long j)
{
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	if(i==n-2)
	{
		if(j==0)
		return a[i][j]+max(a[i+1][j],a[i+1][j+1]);
		if(j==m-1)
		return a[i][j]+ max(a[i+1][j],a[i+1][j-1]);
		return a[i][j]+max(a[i+1][j-1],max(a[i+1][j],a[i+1][j+1]));
	}
	else
	{
		if(j==0)
		{
			dp[i][j]=a[i][j]+max(solve(i+1,j),solve(i+1,j+1));
			return dp[i][j];
		}
		if(j==m-1)
		{
			dp[i][j]=a[i][j]+max(solve(i+1,j),solve(i+1,j-1));
			return dp[i][j];
		}
		else
		{
			dp[i][j]=a[i][j]+max(solve(i+1,j-1),max(solve(i+1,j),solve(i+1,j+1)));
			return dp[i][j];
		}
	}
}

int main()
{
	long long t;
	t=scan();
	while(t--)
	{
		long long i,j,k,mx=0;
		n=scan();
		m=scan();
			
		for(i=0;i<n;i++)
		{
		     for(j=0;j<m;j++)
		     {
		     	a[i][j]=scan();
		     	dp[i][j]=-1;
			 }
		}
		
		for(i=0;i<m;i++)
		{
			mx=max(mx,solve(0,i));
		}
		printf("%lld\n",mx);
	}
}
