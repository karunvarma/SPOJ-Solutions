#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000ll

long long v[1000000],cnt=3;

void init()
{
     v[1]=v[2]=1ll;
	 
	 while(v[cnt-1]<=mx)
	 {
	      v[cnt]=v[cnt-1]+v[cnt-2];
		  cnt++;	
	 }	
	 cnt--;
}

long long index(long long val)
{
	long long l=1,h=cnt,m;
	
	while(l<h)
	{
		m=(l+h)/2;
		
		if(v[m]==val)
		return m+1;
		
		else if(v[m]<val)
		l=m+1;
		
		else
		h=m;
	}
	return h;
}

int main()
{
	init();
	
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long n,i,j,ans=0;
		scanf("%lld",&n);
		
		while(n)
		{
			j=index(n);
			ans=ans+ v[j];
			n=n-v[j-1];
		}
		printf("%lld\n",ans);
	}
}
