#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long  n,i,j,d=0,m,sum=0,max=0;
		
		scanf("%lld",&n);
		scanf("%lld",&m);
		long long a[n];
		
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		
		i=j=0;
		
		while(i<n && j<n)
		{
			sum=sum+a[i];
			i++;
			
			if(sum>m)
			{
				while(sum>m)
				{
					sum=sum-a[j];
					j++;
				}
				if(i-j>d)
				{
					d=i-j;
					max=sum;
				}
				
				if(i-j==d && max>sum)
				max=sum;
			}
			else
			{
				if(i-j>d)
				{
					max=sum;
					d=i-j;
				}
				if(i-j==d && max>sum)
				max=sum;
			}
			
		}
		printf("%lld %lld\n",max,d);
	}
}
