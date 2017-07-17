#include<bits/stdc++.h>
using namespace std;

long long mul(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
		ans=(ans*a)%10;
		
		a=(a*a)%10;
		b=b/2;
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s[2000];
		cin>>s;
		
		long long a,b;
		a=s[strlen(s)-1]-'0';
		cin>>b;
		a=mul(a,b);
		cout<<a<<endl; 
	}
}
