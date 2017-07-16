#include<bits/stdc++.h>
using namespace std;

char a[2001],b[2001];
int la,lb,dp[2001][2001];

int solve(int i,int j)
{	
    if(i==-1 && j==-1)
    {
         return 0;
	}
	if(i<0 && j>=0)
	{
		return j+1;
	}
	if(j<0 && i>=0)
	{
		return i+1;
	}
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	if(a[i]==b[j])
	{	
	  dp[i][j]=solve(i-1,j-1);
	  return dp[i][j];
    }
    else
    {
    	dp[i][j]=1+min(solve(i-1,j),min(solve(i,j-1),solve(i-1,j-1)));
    	return dp[i][j];
	}
}

int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cin>>b;
		la=strlen(a);
		lb=strlen(b);
		
		for(i=0;i<la;i++)
		{
			for(j=0;j<lb;j++)
			{
				dp[i][j]=-1;
			}
		}
		
		int ans=solve(la-1,lb-1);
		
		
		cout<<ans<<endl;
	}
}
