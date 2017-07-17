#include<bits/stdc++.h>
using namespace std;

string s;
long long dp[25],l;

long long solve(long long i)
{
	if(i>=l)
	return 1;
	
	else if(dp[i]!=-1)
	return dp[i];
	
	if(s[i]=='1')
	{
		if(i+1<l)
		{
		     dp[i]=solve(i+1);
			 dp[i]+=solve(i+2);  	
		}
		else
		{
			 dp[i]=solve(i+1);
		}
	}
	else if(s[i]=='2')
	{
		if(i+1<l)
		{
			dp[i]=solve(i+1);
			if(s[i+1]=='0')
			dp[i]+=solve(i+2);
		}
		else
		{
			dp[i]=solve(i+1);
		}
	}
	else
	dp[i]=solve(i+1);
	
	return dp[i];
}

int main()
{
	for(int i=0;i<25;i++)
	{
		dp[i]=-1;
	}
	
	cin>>s;
	l=s.size();
	
	cout<<solve(0)<<endl;
	
}
