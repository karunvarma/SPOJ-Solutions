#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[200001];
		cin>>a;
		long long i,j,k,l=strlen(a),ind[26];
		long long dp[200001];
		
		for(i=0;i<26;i++)
		ind[i]=-1;
		
		dp[l]=1;
		for(i=l-1;i>=0;i--)
		{
			if(ind[a[i]-'A']==-1)
			{
			  dp[i]=(dp[i+1]*2)%mod;
			  ind[a[i]-'A']=i;
			}
			else
			{
				dp[i]=(dp[i+1]*2-dp[ind[a[i]-'A']+1]);
				dp[i]=(dp[i]+mod)%mod;
				ind[a[i]-'A']=i;
			}
		}
		cout<<dp[0]<<endl;
	}
}
