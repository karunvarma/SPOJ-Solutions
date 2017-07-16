#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001],a[2000],b[2000];

int scan()
{
    int n=0;
    char ch=getchar_unlocked();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar_unlocked();
    }
 
    while (ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar_unlocked();
    }
 
    return n;
}

int main()
{
	int d;
	d=scan();
	while(d--)
	{
		int i,j,ans=0,mx,n1,n2;
		
		i=scan();
		j=0;
		while(i)
		{
			a[j++]=i;
			i=scan();
		}
		a[j]=0;
		n1=j;
		
		while(1)
		{
			i=scan();
			j=0;
			
			while(i)
			{
				b[j++]=i;
				i=scan();
			}
			n2=j;
			if(j==0)
			break;
			
			for(i=0;i<=n1;i++)
			dp[i][0]=0;
			for(i=0;i<=n2;i++)
			dp[0][i]=0;
			
			for(i=1;i<=n1;i++)
			{
				for(j=1;j<=n2;j++)
				{
					if(a[i-1]==b[j-1])
					dp[i][j]=1+dp[i-1][j-1];
					else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
			if(ans<dp[n1][n2])
			ans=dp[n1][n2];
		}
		cout<<ans<<endl;
	}
}
