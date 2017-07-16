#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[20];
		long long i=1,j,k=1,b=0,chk=0;
	
		cin>>a;
		
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]!='.')
			{
				b=b*10+(a[i]-'0');
				if(chk)
				k=k*10;
			}
			else
			chk++;
		}
		j=gcd(b,k);
		k=k/j;
		cout<<k<<endl;
	}
}
