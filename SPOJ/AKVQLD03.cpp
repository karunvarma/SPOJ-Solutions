#include<bits/stdc++.h>
using namespace std;

long long a[1000001],b[4000001],n;

void build(long long start,long long end,long long node)
{
	 if(start==end)
	 {
	 	b[node]=a[start];
	 	return ;
	 }
	 
	 long long mid=(start+end)/2;
	 
	 build(start,mid,node*2);
	 build(mid+1,end,node*2+1);
	 b[node]=b[node*2]+b[node*2+1];
}

long long query(long long start,long long end,long long node,long long l,long long r)
{
	if(l>end || r<start)
	return 0;
	
	else if(l<=start && r>=end)
	return b[node];
	
	long long mid=(start+end)/2;
	return query(start,mid,node*2,l,r)+query(mid+1,end,node*2+1,l,r);
}

void update(long long start,long long end,long long node,long long pos,long long val)
{
	if(start==end)
	{
		b[node]+=val;
		return ;
	}
	
	long long mid=(start+end)/2;
	if(start<=pos && mid>=pos)
	update(start,mid,node*2,pos,val);
	else
	update(mid+1,end,node*2+1,pos,val);
	b[node]=b[node*2]+b[node*2+1];
}

int main()
{
	long long m,i,j,k,l,r;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	a[i]=0;
	
	build(1,n,1);
	
	while(m--)
	{
		char s[10];
		cin>>s;
		
		if(s[0]=='f')
		{
			cin>>l>>r;
			i=query(1,n,1,l,r);
			cout<<i<<endl;
		}
		else
		{
			cin>>i>>j;
			update(1,n,1,i,j);
		}
	}
}
