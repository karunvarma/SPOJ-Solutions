#include<bits/stdc++.h>
using namespace std;

int dp[101][101],cost[101];

int solve(int n,int k,int c)
{
   
	if((k!=0 && c==n) || (k<0))
	return 999999;
	
	if(k==0)
	return 0;
	
	if(dp[k][c]!=-1)
	return dp[k][c];
	
	dp[k][c]=INT_MAX/100;
    for(int i=0;i<n;i++)
    {
    	if(cost[i]>=0 && k>=i+1)
    	dp[k][c]=min(dp[k][c],cost[i]+solve(n,k-i-1,c+1));
	}
	
	return dp[k][c];
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k,i,j,p,q,r;
		cin>>n;
		cin>>k;
		
		for(i=0;i<k;i++)
		{
			 cin>>cost[i];
		}
		
		for(i=0;i<=100;i++)
		{
			for(j=0;j<=100;j++)
			{
				dp[i][j]=-1;
			}
		}
		
		 
		i=solve(k,k,0);
	
		if(i<999999)
		cout<<i<<endl;
		else
		cout<<"-1\n";
	}
}
