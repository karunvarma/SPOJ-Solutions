#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long dp[50],i,t;
	dp[0]=1;
	dp[1]=2;
	
	for(i=2;i<50;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	cin>>t;
	while(t--)
	{
		cin>>i;
		cout<<dp[i]<<endl;
	}
}
