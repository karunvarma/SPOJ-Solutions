#include<bits/stdc++.h>
using namespace std;

long long power(long long a,long long b,long long m)
{
  	long long x=1,y=a;
  	while(b>0)
	{
    	if(b%2!=0)
		{
    		 x=(x*y)%m;
    	}
    	y=(y*y)%m;
    	b>>=1;
  	}
  	return x;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,p,i,j,k,r;
		cin>>n>>p;
		
		if(n>=p)
		{
			cout<<"0\n";
			continue;
		}
		r=1;
		for(i=p-1;i>n;i--)
		{
			j=power(i,p-2,p);
			r=(r*j)%p;
		}
		cout<<p-r<<endl;
	}
}
