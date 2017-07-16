#include<bits/stdc++.h>
using namespace std;
#define mx 10000000

bool prime[10000001];
long long p[10000001],dp[10000001];

void sieve()
{
	memset(prime,true,sizeof(prime));
	
	int i,j;
	i=2,j=2;
	
	while(i*j<=mx)
	{
		prime[i*j]=false;
		p[i*j]=i;
		j++;
	}
	i=3,j=2;
	
	while(i*j<=mx)
	{
		if(prime[i*j])
		{
		  prime[i*j]=false;
		  p[i*j]=i;
		}
		j++;
	}
	
	for(i=5;i*i<=mx;i++)
	{
		if(prime[i])
		{
			j=2;
			while(i*j<=mx)
			{
				if(prime[i*j])
				{
				  prime[i*j]=false;
				  p[i*j]=i;
				}
				j++;
			}
		}
		if(prime[i+2])
		{
			j=2;
			while((i+2)*j<=mx)
			{
				if(prime[(i+2)*j])
				{
				  prime[(i+2)*j]=false;
				  p[(i+2)*j]=i+2;
				}
				j++;
			}
		}
	}
}
void comp()
{
	dp[0]=dp[1]=0;
	for(int i=2;i<=mx;i++)
	{
		if(prime[i])
		dp[i]=dp[i-1]+i;
		else
		dp[i]=dp[i-1]+p[i];
	}
}
int main()
{
	sieve();
	comp();
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		
		cout<<dp[n]<<endl;
	}
}
