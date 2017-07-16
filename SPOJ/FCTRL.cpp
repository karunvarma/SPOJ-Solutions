#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,i,j,k,ans=0;
		cin>>n;
		j=5;
		while(j<=n)
		{
			ans=ans+n/j;
			j*=5;
		}
		cout<<ans<<endl;
	}
}
