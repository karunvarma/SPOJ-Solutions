#include<bits/stdc++.h>
using namespace std;

int scan()
{
	char r;
	bool start=false;
	int ret=0;
	while(true)
	{
		r=getchar_unlocked();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
		{
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start)
		{
			break;
		}
		if(start)ret*=10;
		start=true;
		ret+=r-'0';
	}
	return ret;
}

int gcd(int a,int b)
{
	int c;
	while(b)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}

int main()
{
	int t,i=0;
	t=scan();
	while(t--)
	{
		 i++;
	     int k,a,b,c;
	     a=scan();
		 b=scan();
		 c=scan();
	     
	     k=gcd(a,b);
	     printf("Case %d: ",i);
	     if(c%k==0)
	     {
	     	printf("Yes\n");
		 }
		 else
		 {
		 	printf("No\n");
		 }
	}
}
