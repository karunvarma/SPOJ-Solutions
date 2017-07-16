#include<bits/stdc++.h>
using namespace std;
#define mx 202

long long dp[mx][mx][mx],a[mx],n;

long long solve(long long bi,long long wi,long long i)
{
	if(i==n)
	return 0;
	
	if(dp[bi][wi][i]!=-1)
	return dp[bi][wi][i];
	
	long long p,q,r;
	p=r=q=INT_MAX;
	if(a[i]>a[bi])
	p=solve(i,wi,i+1);
	if(a[i]<a[wi])
	q=solve(bi,i,i+1);
	r=1+solve(bi,wi,i+1);
	
	dp[bi][wi][i]=min(p,min(q,r));
	return dp[bi][wi][i];
}

int main()
{
	a[mx-2]=INT_MAX;
	a[mx-1]=-INT_MAX;
	
	cin>>n;
	while(n!=-1)
	{
		int i,j,k;
		
		memset(dp,-1,sizeof(dp));
		
		for(i=0;i<n;i++)
		cin>>a[i];
		
		i=solve(mx-1,mx-2,0);
		cout<<i<<endl;
		cin>>n;
	}
}
