#include<bits/stdc++.h>
using namespace std;

long long int scan()
{
	char r;
	bool start=false,neg=false;
	long long int ret=0;
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
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

long long a[100][100],b[100][100],sca[100]={0},srb[100]={0};

int main()
{
	long long n,i,j,k,q,x,y;
	long long sum=0;
	
	n=scan();
	
	for(i=0;i<n;i++)
	{
		sca[i]=srb[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=scan();
			sca[j]+=a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>b[i][j];
			srb[i]+=b[i][j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		sum+= sca[i]*srb[i];
	}
	
	q=scan();
	char c;
	
	while(q--)
	{
		c=getchar();
		x=scan();
	    y=scan();
		k=scan();
			
		if(c=='A')
		{
			sca[y]=sca[y]-a[x][y]+k;
			sum=sum-a[x][y]*srb[y]+k*srb[y];
			a[x][y]=k;
		}
		else
		{
			srb[x]=srb[x]-b[x][y]+k;
			sum=sum-b[x][y]*sca[x]+k*sca[x];
			b[x][y]=k;
		}
		printf("%lld\n",sum);
	}
}
