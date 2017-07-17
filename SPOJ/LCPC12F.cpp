#include<bits/stdc++.h>
using namespace std;

int a[100001],c[1001];

int main()
{
	int t,u=0;
	cin>>t;
	while(t--)
	{
		int x,n,i,j,k;
		long long ans=0;
		cin>>x>>n;
		
		u++;
		
		for(i=0;i<=1000;i++)
		c[i]=0;
		
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			c[a[i]]++;
		}
		
		for(i=1;i<=n;i++)
		{
			c[a[i]]--;
			if(x-a[i]>=0 && x-a[i]<=1000)
			ans+=c[x-a[i]];
		}
		cout<<u<<". "<<ans<<endl;
	}
}
