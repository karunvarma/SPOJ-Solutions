#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,r,m,i,j,k;
		cin>>n>>r>>m;
		n=m/n;
		
		i=0;
		while(n>=r)
		{
			i++;
			n=n/r;
		}
		cout<<i<<endl;
	}
}
