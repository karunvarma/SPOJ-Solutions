#include<bits/stdc++.h>
using namespace std;

int power[50],cnt=1;

void init()
{
	power[0]=1;
	while(power[cnt-1]<=2000)
	{
		power[cnt]=power[cnt-1]*2;
		cnt++;
	}
	cnt--;
}

int find(int val)
{
	int l=0,h=cnt,m;
	
	while(l<h)
	{
		m=(l+h)/2;
		
		if(power[m]==val)
		return m;
		
		else if(power[m]<val)
		{
			l=m+1;
		}
		else
		{
			h=m;
		}
	}
	return h;
}

int main()
{
	init();
	int a,b,c,j,k,ans,t,u=0;
	long long i;
	scanf("%d",&t);
	while(t--)
	{
		u++;
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);
		
		ans=find(a)+find(b)+find(c);
		i=(long long)a*b*c;
		i--;
		printf("Case #%d: %lld %d\n",u,i,ans);
	}
	
}
