#include<stdio.h>
#define mx 1000000007

long long scan()
{
    long long n=0;
    char ch=getchar_unlocked();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar_unlocked();
    }
 
    while (ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar_unlocked();
    }
 
    return n;
}

long long t[400004],lazy[400004],gp[100010],sum[100010];

void build(long long start,long long end,long long node)
{
	if(start==end)
	{
		t[node]=lazy[node]=0;
	    return ;
	}
	long long mid=(start+end)/2;
	build(start,mid,node*2);
	build(mid+1,end,node*2+1);
	t[node]=lazy[node]=0;
}

void update(long long start,long long end,long node,long long s,long long l,long long r)
{
	 long long mid=(start+end)/2;
	 
	 if(lazy[node]!=0)
	 {
	 	t[node]+= (lazy[node]*sum[end+1-start]);
	 	t[node]%=mx;
	 	
	 	if(start!=end)
	 	{
	 	    lazy[node*2]+=lazy[node];
	 	    lazy[node*2]%=mx;
			lazy[node*2+1]+=lazy[node]*gp[mid+1-start];
			lazy[node*2+1]%=mx; 	
		}
		lazy[node]=0;
	 }
	 
	 
	 if(start>r || l>end)
	 return;
	 
	 if(l<=start && r>=end)
	 {
	 	  t[node]+= s*(sum[end+1-l]-sum[start-l]+mx);
		  t[node]%=mx;
	 	 
	 	  if(end!=start)
	 	  {
	          lazy[node*2]+=s*(gp[start-l]);
	          lazy[node*2]%=mx;
	          lazy[node*2+1]+=s*(gp[mid+1-l]);
	          lazy[node*2+1]%=mx;
		  }
	 	  return ;
	 }
	 update(start,mid,node*2,s,l,r);
	 update(mid+1,end,node*2+1,s,l,r);
	 t[node]=t[node*2]+t[node*2+1];
	 t[node]%=mx;
}

long long query(long long start,long long end,long long node,long long l,long long r)
{
	long long mid=(start+end)/2,p,q;
	
	if(start>r || end<l)
	return 0;
	
	if(lazy[node]!=0)
	{
	 	t[node]+= (lazy[node]*sum[end+1-start]);
	 	t[node]%=mx;
	 	
	 	if(start!=end)
	 	{
	 	    lazy[node*2]+=lazy[node];
	 	    lazy[node*2]%=mx;
			lazy[node*2+1]+=lazy[node]*gp[mid+1-start];
			lazy[node*2+1]%=mx; 	
		}
		lazy[node]=0;
	}
	 
	if(l<=start && r>=end)
	return t[node];
	
	p=query(start,mid,node*2,l,r);
	q=query(mid+1,end,node*2+1,l,r);
	return (p+q)%mx;
	 
}

void up(long long start,long long end,long long node,long p)
{
	long long mid=(start+end)/2;
	 
	 if(lazy[node]!=0)
	 {
	 	t[node]+= (lazy[node]*sum[end+1-start]);
	 	t[node]%=mx;
	 	if(start!=end)
	 	{
	 	    lazy[node*2]+=lazy[node];
	 	    lazy[node*2]%=mx;
			lazy[node*2+1]+=lazy[node]*gp[mid+1-start]; 	
		    lazy[node*2+1]%=mx;
		}
		lazy[node]=0;
	 }
	 
	 if(start>p || end<p)
	 return ;
	 
	 if(start==p && end==p)
	 {
	 	t[node]=0;
	 	return ;
	 }
	 
	 up(start,mid,node*2,p);
	 up(mid+1,end,node*2+1,p);
	 
	 t[node]=(t[node*2]+t[node*2+1])%mx;
}

int main()
{
	long long n,r,q,i,j,k,s,l;
	n=scan();
	r=scan();
	q=scan();
	
	gp[0]=1,sum[0]=0,sum[1]=1;
	for(i=1;i<=n;i++)
	{
		gp[i]=(gp[i-1]*r)%mx;
		sum[i+1]=(sum[i]+gp[i])%mx;
	}
	
	build(1,n,1);
	
	while(q--)
	{
		k=scan();
		
		if(k==0)
		{
		     s=scan();
			 l=scan();
			 r=scan();
			 update(1,n,1,s,l,r);	
		}
		else if(k==1)
		{
			l=scan();
			r=scan();
			printf("%lld\n",query(1,n,1,l,r));
		}
		else
		{
			l=scan();
			up(1,n,1,l);
		}
	}
}
