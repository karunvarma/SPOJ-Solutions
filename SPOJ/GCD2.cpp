#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char num[300];
		long long a,b,i,j,k,power[300];
		
		cin>>a;
		cin>>num;
		
		if(a==0)
	    {
	    	cout<<num<<endl;
	    	continue;
		}
		
		power[0]=1;
		for(i=1;i<300;i++)
		{
			power[i]=(power[i-1]*10)%a;
		}
		b=0;
		for(i=0;i<strlen(num);i++)
		{
			b+=(num[i]-'0')*power[strlen(num)-i-1];
			b%=a;
		}
		i=gcd(a,b);
		cout<<i<<endl;
	}
}
