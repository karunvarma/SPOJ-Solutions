#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		if(n%2==0)
		i=(((n/2)%1000007)*((3*n+1)%1000007))%1000007;
		else
		i=(((n)%1000007)*(((3*n+1)/2)%1000007))%1000007;
		cout<<i<<endl;
	}
}
