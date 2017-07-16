#include<iostream>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}

int main()
{
	long long a,b,c;
	cin>>a>>b;
	
	while(a)
	{
		c=gcd(a,b);
		a=a/c;
		b=b/c;
		c=a*b;
		cout<<c<<endl;
		
		cin>>a>>b;
	}
	return 0;
}
