#include<bits/stdc++.h>
using namespace std;
long long scan()
{
    long long n=0;
    char ch=getchar_unlocked();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar_unlocked();
    }
 
    while (ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar_unlocked();
    }
 
    return n;
}
int main()
{
	long long t;
	t=scan();
	while(t--)
	{
		long long p,q,s,d,n,a,i;
		p=scan();
		q=scan();
		s=scan();
		
		n=(s*2)/(p+q);
		d=(q-p)/(n-5);
		a=p-2*d;
		
		printf("%lld\n",n);
		printf("%lld",a);
		for(i=1;i<n;i++)
		printf(" %lld",a+i*d);
		printf("\n");
	}
}
