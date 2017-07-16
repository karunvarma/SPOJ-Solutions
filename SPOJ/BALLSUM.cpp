#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}

long long sum(long long n)
{
	return n*(n+1)/2;
}

int main()
{
	long long n,k;
	scanf("%lld",&n);
	scanf("%lld",&k);
	
	while(n+1)
	{
		long long i,j,ans=0;
	    
	    ans=2*sum((k-1)/2);
	    
	    if(k%2==1)
	    ans=ans-(k-1)/2;
	    
	    i=n*(n-1)/2;
	    
	    if(ans==0)
	    {
	    	printf("0\n");
	    	scanf("%lld",&n);
			scanf("%lld",&k);
	    	continue;
		}
		if(ans==i)
		{
			printf("1\n");
			scanf("%lld",&n);
			scanf("%lld",&k);
			continue;
		}
	    
	    j=gcd(ans,i);
	    ans=ans/j;
	    i=i/j;
	    
	    printf("%lld/%lld\n",ans,i);
	    scanf("%lld",&n);
		scanf("%lld",&k);
	}
}
