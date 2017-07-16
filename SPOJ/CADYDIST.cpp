#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	while(n)
	{
		long long a[n],b[n],sum=0,i;
		
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<n;i++)
		cin>>b[i];
		
		sort(a,a+n);
		sort(b,b+n);
		
		for(i=0;i<n;i++)
		sum+=a[i]*b[n-1-i];
		
		cout<<sum<<endl;
		cin>>n;
	}
}
