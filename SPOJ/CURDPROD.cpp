#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,T,i,j,k,lo,hi,md,mx=0,sum=0;
		cin>>n>>T;
		long long a[n];
		
		for(i=0;i<n;i++)
		{
		   cin>>a[i];
		   mx=max(mx,a[i]);
		}
		lo=0,hi=T*mx;
		
		while(lo<hi)
		{
			md=(lo+hi)/2;
			sum=0;
			
			for(i=0;i<n;i++)
			{
				sum+=md/a[i];
				if(sum>T)
				break;
			}
			if(sum<T)
			{
				lo=md+1;
			}
			else
			{
				hi=md;
			}
		}
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=lo/a[i];
			if(sum>T)
			break;
		}
		if(sum>=T)
		{
			cout<<lo<<endl;
			goto hell;
		}
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=md/a[i];
			if(sum>T)
			break;
		}
		if(sum>=T)
		{
			cout<<md<<endl;
			goto hell;
		}
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=hi/a[i];
			if(sum>T)
			break;
		}
		if(sum>=T)
		{
			cout<<hi<<endl;
			goto hell;
		}
		hell:
			;
	}
}
