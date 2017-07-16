#include<bits/stdc++.h>
using namespace std;

int a[25],b[25],dp[200][25],n,m;

int solve(int s,int i)
{

	if(s==n && i==m)
	return 1;
	
	if(s>n || i>=m)
	return 0;
	
	
	if(dp[s][i]!=-1)
	{
	   return dp[s][i];
    }
	long long j,sum=0;
	
	for(j=a[i];j<=b[i];j++)
	{
		if(s+j<=n)
		sum+=solve(s+j,i+1);
	}
	dp[s][i]=sum;
	return dp[s][i];
}

int main()
{
	int i,j,k;
	cin>>m>>n;
	
	while(n!=0 && m!=0)
	{
		for(i=0;i<m;i++)
		{
			cin>>a[i]>>b[i];
		}
		
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				dp[i][j]=-1;
			}
		}
		
		j=solve(0,0);
		cout<<j<<endl;
		
        cin>>m>>n;
	}
}
