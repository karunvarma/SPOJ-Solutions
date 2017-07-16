#include<bits/stdc++.h>
using namespace std;

long long a[100010][3],dp[100010][3];

int main()
{
	long long n,i,j,k=0;
	cin>>n;
	while(n)
	{
		k++;
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				cin>>a[i][j];
				dp[i][j]=INT_MAX;
			}
		}
		dp[0][1]=a[0][1];
		dp[0][2]=a[0][1]+a[0][2];
		
		for(i=1;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				if(j==0)
				dp[i][j]=min(dp[i][j],a[i][j]+min(dp[i-1][0],dp[i-1][1]));
				else if(j==1)
				dp[i][j]=min(dp[i][j],a[i][j]+min(dp[i-1][0],min(dp[i-1][1],min(dp[i-1][2],dp[i][0]))));
				else
				dp[i][j]=min(dp[i][j],a[i][j]+min(dp[i-1][1],min(dp[i-1][2],dp[i][1])));
			}
		}
		cout<<k<<". "<<dp[n-1][1]<<endl;
		cin>>n;
	}
}
