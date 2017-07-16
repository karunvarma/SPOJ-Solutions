#include<bits/stdc++.h>
using namespace std;

long long a[1000001];

void solve(long long n)
{
      if(a[n/2]+a[n/3]+a[n/4]>n)
      a[n]=a[n/2]+a[n/3]+a[n/4];
      else
      a[n]=n;
}
long long uttar(long long n)
{
	if(n<=1000000)
	return a[n];
	else
	{
		long long j=uttar(n/2)+uttar(n/3)+uttar(n/4);
		if(j>n)
		return j;
		else 
		return n;
	}
}

int main()
{
	a[1]=1;
	a[2]=2;
	a[3]=3;
	a[4]=4;
	for(long long i=5;i<1000001;i++)
	{
		solve(i);
	}
	long long n;
	while(cin>>n)
	{	 
	     if(n<=1000000)
		 cout<<a[n]<<endl;
		 else
		 {
		 	  cout<<uttar(n)<<endl;
		 }
	}
}
