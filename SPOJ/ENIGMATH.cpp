#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long b,a,x,y,i;
		cin>>a>>b;
		i=gcd(a,b);
		x=b/i;
		y=a/i;
		cout<<x<<" "<<y<<endl;
	}
}
