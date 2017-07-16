#include<bits/stdc++.h>
using namespace std;

long long a[100001],dp[100001],n;

long long scan()
{
    long long n=0;
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

long long solve(long long i)
{
	long long p,q,r;
	
	if(i>=n)
	return 0;
	
	if(dp[i]!=-1)
	return dp[i];
	
	p=q=r=0;
	if(i+2<n)
	{
		p=a[i]+a[i+1]+a[i+2]+solve(i+6);
	}
	if(i+1<n)
	{
		q=a[i]+a[i+1]+solve(i+4);
	}
	if(i<n)
	{
		r=a[i]+solve(i+2);
	}
	dp[i]=max(p,max(q,r));
	return dp[i];
}

int main()
{
	int t;
	t=scan();
	while(t--)
	{
		long long i,j,k;
		n=scan();
		for(i=0;i<n;i++)
		{
		   a[i]=scan();
		   dp[i]=-1;
	    }
		i=solve(0);
		printf("%lld\n",i);
	}
}
