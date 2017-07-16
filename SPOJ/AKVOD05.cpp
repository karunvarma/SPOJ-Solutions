#include<bits/stdc++.h>
using namespace std;

int a[100001],cnt[100001];

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

struct compare
{
	bool operator()(int& c,int& b)
	{
	   return c>b;
    }
};

int main()
{
	int t;
	t=scan();
	while(t--)
	{
		int n,i,j,k;
		n=scan();
		k=scan();
		
		for(i=0;i<k+1;i++)
		{
			cnt[i]=0;
		}
		for(i=0;i<k;i++)
		{
			a[i]=scan();
			if(a[i]<=k)
			cnt[a[i]]++;
		}
		
		priority_queue<int,vector<int>,compare> q;
		
		for(i=0;i<=k;i++)
		{
			if(!cnt[i])
			{
				q.push(i);
			}
		}
		
		n=n%(k+1);
		
		j=a[0];
		a[0]=a[k]=q.top();
		q.pop();
		
		cnt[a[0]]++;
		
		if(j<=k)
		{
		   cnt[j]--;
		   if(!cnt[j])
		   q.push(j);
	    }
		
		
		for(i=1;i<=n;i++)
		{
			j=a[i];
			 a[i]=q.top();
			 q.pop();
			 
			 cnt[a[i]]++;
			 
			 if(j<=k)
			 {
			    cnt[j]--;
			    if(!cnt[j])
			    q.push(j);
			 }
		}
		
		printf("%d\n",a[n]);
	}
}
