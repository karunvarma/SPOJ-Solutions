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
	char a[200];
	cin>>a;
	while(a[0]!='*')
	{
		
		long long ans=1,i,j;
		
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='Y')
			{
				j=gcd(ans,i+1);
				ans=ans*(i+1)/j;
			}
		}
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='N')
			{
				j=gcd(ans,i+1);
				if(j==i+1)
				{
					ans=-1ll;
					break;
				}
			}
		}
		cout<<ans<<endl;
		cin>>a;
	}
}
