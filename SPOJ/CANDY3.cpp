#include<iostream>
using namespace std;
int main()
{
	long long  t;
	cin>>t;
	while(t--)
	{
		long long n,i,k;
		long long j=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>k;
			j+=k;
			j=j%n;
		}
		
		if(j%n==0)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
}
