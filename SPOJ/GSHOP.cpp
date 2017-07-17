#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int i,j,k,n,mx=INT_MAX,sum=0;
		cin>>n>>k;
		
		int a[n];
		
		for(i=0;i<n;i++)
		cin>>a[i];
		
		sort(a,a+n);
		
		for(i=0;i<n;i++)
		{
			if(a[i]>=0)
			break;
		}
		
		j=i;
		
		if(j<=k)
		{
			for(i=0;i<n;i++)
			{
				sum+=abs(a[i]);
				mx=min(mx,abs(a[i]));
			}
			
			if((k-j)%2==1)
			{
				sum-=2*mx;
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(k)
				{
				   sum+=abs(a[i]);
				   k--;
			    }
				else
				sum+=a[i];
				
			}
		}
		cout<<sum<<endl;
	}
}
