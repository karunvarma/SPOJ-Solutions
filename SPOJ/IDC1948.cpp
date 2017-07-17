#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}

#define mx 600000000
#define pb(x) push_back(x)

vector<int> p;
bool chk[50000];

void sieve()
{
	memset(chk,true,sizeof(chk));
	
	int i,j;
	
	i=2;j=2;
	p.pb(i);
	while(i*j<=sqrt(mx))
	{
		chk[i*j]=false;
		j++;
	}
	
	i=3;j=2;
	p.pb(i);
	while(i*j<=sqrt(mx))
	{
		chk[i*j]=false;
		j++;
	}
	
	for(i=5;i<=sqrt(mx);i+=6)
	{
		if(chk[i])
		{
			j=2;
			p.pb(i);
			while(i*j<=sqrt(mx))
			{
				chk[i*j]=false;
				j++;
			}
		}
		if(chk[i+2])
		{
			j=2;
			p.pb(i+2);
			while((i+2)*j<=sqrt(mx))
			{
				chk[(i+2)*j]=false;
				j++;
			}
		}
	}
}

int main()
{
	sieve();
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		
		long long l,n=0,m=0,i,j,k;
		cin>>s;
		
		l=s.size();
		
		for(i=0;i<l;i++)
		{
			n=n*10+(s[i]-'0');
			m=m*10+(9)-(s[i]-'0');
		}
		
		n=abs(n-m);
		
		if(n==1)
		{
			cout<<"-1\n";
		}
		else
		{
			  k=0;
		     for(i=0;i<p.size();i++)
			 {
			      if(n%p[i]==0)
				  {
				  	cout<<p[i]<<endl;
				  	k++;
				    break;	  
				  }	
			 }	
			 if(!k)
			 cout<<n<<endl;
		}
	}
}
