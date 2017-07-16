#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,i,j,k,sum=0,c=0;
		cin>>n;
		long long a[n];
		
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long s[n];
		
		s[0]=a[0];
		
		for(i=1;i<n;i++)
		{
			s[i]=s[i-1]+a[i];
		}
		for(i=n-1;i>0;i--)
		{
			sum+=i*a[i]-s[i-1];
		}
		cout<<sum<<endl;
		
	}
}
