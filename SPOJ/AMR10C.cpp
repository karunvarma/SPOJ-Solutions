#include<bits/stdc++.h>
using namespace std;
#define mx 1000001

long long a[1000001];
bool p[1000001];

void seive()
{
	long long i,j;
	i=2,j=2;
	while(i*j<mx)
	{
		a[i*j]=i;
		p[i*j]=false;
		j++;
	}
	i=3,j=2;
	while(i*j<mx)
	{
		a[i*j]=i;
		p[i*j]=false;
		j++;
	}
	for(i=5;i<=sqrt(mx)+2;i+=6)
	{
		if(p[i])
		{
			j=2;
			while(i*j<mx)
			{
				a[i*j]=i;
				p[i*j]=false;
				j++;
			}
		}
		if(p[i+2])
		{
			j=2;
			while((i+2)*j<mx)
			{
				a[(i+2)*j]=i+2;
				p[(i+2)*j]=false;
				j++;
			}
		}
	}
}

int main()
{
	for(long long i=0;i<mx;i++)
	{
		a[i]=0;
		p[i]=true;
	}
	p[1]=true;
	seive();
	
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,i,j,k,c,m=0;
		cin>>n;
		
		if(n==1)
		m=0;
		else if(p[n])
		m=1;
		else
		{
			while(n>1 && p[n]==false)
			{
				j=a[n],c=0;
				while(n>=j && n%j==0)
				{
					c++;
					n=n/j;
				}
				m=max(m,c);
				
				
			}
		}
		cout<<m<<endl;
	}
}
