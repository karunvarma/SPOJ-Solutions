#include<bits/stdc++.h>
using namespace std;
#define mx 100000000

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

struct order
{
	long long start,end;
}
ob[100001];

bool comp(order p,order q)
{
	if(p.start<q.start)
	return true;
	if(p.start==q.start)
	return p.end<q.end;
	return false;
}

long long dp[100001],n;

long long index(long long low, long long value, long long n) {
    long long high = n - 1;
    long long result = n;
    while (low <= high)
	{
        long long mid = (low + high)/2;
        if (ob[mid].start >= value) 
		{
            high = mid - 1;
            result = mid;
        } 
		else
            low = mid + 1;
    }
    return result;
}

long long solve(long long i)
{
	if(i>=n)
	return 1;
	
	if(dp[i]!=-1)
	return dp[i];
	
	long long y=0,j;
	
	j=index(i+1,ob[i].end,n);

    dp[i]=(solve(i+1)+solve(j))%mx;
	
	return dp[i];
}

int main()
{
	while(1)
	{
		long long i,j,k,c;
		n=scan();
		if(n==-1)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			j=scan();
			k=scan();
			ob[i].start=j;
			ob[i].end=k;
			dp[i]=-1;
		}
		
		sort(ob,ob+n,comp);
		
		i=solve(0);
		i=(i-1+mx)%mx;
		printf("%08lld\n",i);
	}
}
