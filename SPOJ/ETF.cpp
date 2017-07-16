#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,i,j,c;
		cin>>n;
		c=n;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				c=c-c/i;
			}
			while(n%i==0)
			{
				n=n/i;
			}
		}
		if(n>1)
		c=c-c/n;
		cout<<c<<endl;
	}
}
