#include<bits/stdc++.h>
using namespace std;

long long a[20001],tree[100000];

void built(long long start,long long end,long long node)
{
	if(start==end)
	{
		tree[node]=a[start];
		return ;
	}
	long long mid=(start+end)/2;
	built(start,mid,node*2);
	built(mid+1,end,node*2+1);
	
	tree[node]=tree[node*2]&tree[node*2+1];
}
long long query(long long start,long long end,long long node,long long l,long long r)
{
	if(l<=start && r>=end)
	return tree[node];
	
	long long i,j,mid;
	
	mid=(start+end)/2;
	
	if(r<=mid)
	return query(start,mid,node*2,l,r);
	else if(l>mid)
	return query(mid+1,end,node*2+1,l,r);
	else
	i=query(start,mid,node*2,l,r);
	j=query(mid+1,end,node*2+1,l,r);
	i=i&j;
	return i;
}
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,k,i,j,l,r,x,y;
		cin>>n>>k;
		
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		
		built(1,n,1);
		
		if(2*k+1>=n)
		{
			
			j=query(1,n,1,1,n);
			for(i=1;i<=n;i++)
			{
				cout<<j<<" ";
			}
			cout<<endl;
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				if(i-k>=1 && i+k<=n)
				{
					j=query(1,n,1,i-k,i+k);
					cout<<j<<" ";
				}
				else if(i-k<1)
				{
					j=query(1,n,1,i,i+k);
					l=query(1,n,1,1,i);
					r=query(1,n,1,n-(k-i+1)+1,n);
					x=j&l;
					y=x&r;
					cout<<y<<" ";
				}
				else if(i+k>n)
				{
					j=query(1,n,1,i-k,i);
					l=query(1,n,1,i,n);
					r=query(1,n,1,1,(k+1-(n-i+1)));
					x=j&l;
					y=x&r;
					cout<<y<<" ";
				}
			}
			cout<<endl;
		}
		
	}
}
