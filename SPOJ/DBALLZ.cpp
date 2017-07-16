#include<bits/stdc++.h>
using namespace std;

long dp[800001],e[1001],tim[1001],l;
long scan()
{
    long n=0;
    char ch=getchar();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar();
    }
 
    while (ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
 
    return n;
}

long solve(long en)
{
	if(en<=0)
	return 0;
	
	if(dp[en]!=-1)
	return dp[en];
	
	dp[en]=0;
	for(long i=0;i<l;i++)
	{
		if(en-e[i]>=0)
		dp[en]=max(dp[en],tim[i]+solve(en-e[i]));
	}
	return dp[en];
}

int main()
{
	int t;
	t=scan();
	while(t--)
	{
		long en,i,j,k;
		en=scan();
		l=scan();
		
		for(i=0;i<=en;i++)
		dp[i]=-1;
		for(i=0;i<l;i++)
		e[i]=scan();
		for(i=0;i<l;i++)
	    tim[i]=scan();
		
		i=solve(en);
		printf("%ld\n",i);
	}
}
