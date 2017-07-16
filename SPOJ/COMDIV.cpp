#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
long long scan()
{
    long long n=0;
    char ch=getchar();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar();
    }
 
    while (ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
 
    return n;
}
int main()
{
	long long t;
	t=scan();
	while(t--)
	{
		long long a,b,i,j,k,c=0;
		a=scan();
		b=scan();
		k=gcd(a,b);
		for(i=1;i*i<k;i++)
		{
			if(k%i==0)
			{
				c=c+2;
			}
		}
		if(i*i==k)
		c++;
		printf("%lld\n",c);
	}
}
