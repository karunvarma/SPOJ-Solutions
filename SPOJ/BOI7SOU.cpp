#include<bits/stdc++.h>
using namespace std;

long long a[1000000],mx[1000000],mn[1000000],n,m,c,i,k=0;

long long scan()
{
    long long f=0;
    char ch=getchar_unlocked();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar_unlocked();
    }
 
    while (ch>='0'&&ch<='9')
    {
        f=f*10+ch-'0';
        ch=getchar_unlocked();
    }
 
    return f;
}

void fmx()
{
	deque<long long> q;
	for(i=0;i<m;i++)
	{
		while(!q.empty() && a[q.back()]<=a[i])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	mx[i-m]=a[q.front()];
	
	for(;i<n;i++)
	{
		while(!q.empty() && q.front()<=i-m)
		q.pop_front();
		while(!q.empty() && a[q.back()]<=a[i])
		q.pop_back();
		q.push_back(i);
		mx[i-m+1]=a[q.front()];
	}
}
void fmn()
{
	deque<long long> q;
	long long i;
	for(i=0;i<m;i++)
	{
		while(!q.empty() && a[q.back()]>=a[i])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	mn[i-m]=a[q.front()];
	
	for(;i<n;i++)
	{
		while(!q.empty() && q.front()<=i-m)
		q.pop_front();
		while(!q.empty() && a[q.back()]>=a[i])
		q.pop_back();
		q.push_back(i);
		mn[i-m+1]=a[q.front()];
	}
}

int main()
{
	n=scan();
	m=scan();
	c=scan();
	for(i=0;i<n;i++)
	a[i]=scan();
	
	fmx();
	fmn();
	for( i=0;i+m<=n;i++)
	{
	//	cout<<mx[i]<<" "<<mn[i]<<endl;
		if(mx[i]-mn[i]<=c)
		{
			cout<<i+1<<endl;
			k++;
		}
	}
	if(!k)
	cout<<"NONE\n";
}
