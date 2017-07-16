#include<bits/stdc++.h>
using namespace std;

long long sum(long long n)
{
	return ((n)*(n+1))/2;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,i,j,k,prev,ans=0;
		cin>>n;
		
		prev=n;
		i=2;
		
		while(prev>n/i)
		{
			ans+= (i-1)*(sum(prev)-sum(n/i));
	//		cout<<prev<<" "<<n/i<<endl;
			prev=n/i;
			i++;
		}
		
	//	cout<<prev<<" "<<n/i<<endl;
		
		while(prev)
		{
			ans+= prev*(n/prev);
		
			prev--;
		}
		ans=ans-sum(n);
		
		cout<<ans<<endl;
	}
}
