#include<bits/stdc++.h>
using namespace std;
#define mx 100000007

int scan()
{
	char r;
	bool start=false;
	int ret=0;
	while(true)
	{
		r=getchar_unlocked();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
		{
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start)
		{
			break;
		}
		if(start)ret*=10;
		start=true;
		ret+=r-'0';
	}
	
	return ret;

}

int dp[1010][1024],a[1010],b[1010],chk[1010];

int main()
{
	int t,u,n,m,i,j,ans;
	memset(chk,0,sizeof(chk));
	t=scan();
	for(u=1;u<=t;u++)
	{
		ans=0;
		n=scan();
		m=scan();
		
		for(i=1;i<=n;i++)
		a[i]=scan();
		
		for(i=1;i<=m;i++)
		{
			b[i]=scan();
			chk[b[i]]=1;
		}
		
		dp[1][0]=1;
		
		for(i=1;i<1024;i++)
		dp[1][i]=0;
		
		for(i=1;i<=n;i++)
		{
			for(j=0;j<1024;j++)
			{
				dp[i+1][j]=dp[i][j]+dp[i][j^a[i]];
				if(dp[i+1][j]>=mx)
				dp[i+1][j]-=mx;
			}
		}
		for(i=0;i<1024;i++)
		{
			if(!chk[i])
			{
				ans+=dp[n+1][i];
				if(ans>=mx)
				ans-=mx;
			}
			chk[i]=0;
		}
		printf("Case %d: %d\n",u,ans);
	}
}
