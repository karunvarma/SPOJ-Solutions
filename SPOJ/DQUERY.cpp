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

int a[30001],cnt[1000010],ans[200001],block,answer=0;

struct nod 
{
	int l,r,ind;

}node[200001];

bool cmp(nod x,nod y)
{
     if(x.l/block!=y.l/block)
	 {
	       return x.l/block<y.l/block;	
	 }
	 return x.r<y.r;	
}

void add(int i)
{
	cnt[a[i]]++;
	if(cnt[a[i]]==1)
	answer++;
}
void remove(int i)
{
	cnt[a[i]]--;
	if(cnt[a[i]]==0)
	answer--;
}

int main()
{
    int n,m,i,j,k,l,r,currentl,currentr;
	memset(cnt,0,sizeof(cnt));
	
	n=scan();
	block=sqrt(n);
	
	for(i=0;i<n;i++)
	{
	  	a[i]=scan();	
	}
	
	m=scan();
	
	for(i=0;i<m;i++)
	{
	    node[i].l=scan();
		node[i].r=scan();
	    node[i].l--;
	    node[i].r--;
	    node[i].ind=i;		
	}
	sort(node,node+m,cmp);
	
	currentl=currentr=0;
	
	for(i=0;i<m;i++)
	{
		l=node[i].l,r=node[i].r;
		
		while(currentl<l)
		{
			remove(currentl);
			currentl++;
		}
		while(currentl>l)
		{
			add(currentl-1);
			currentl--;
		}
		while(currentr<=r)
		{
			add(currentr);
			currentr++;
		}
		while(currentr>r+1)
		{
			remove(currentr-1);
			currentr--;
		}
		ans[node[i].ind]=answer;
	}
	for(i=0;i<m;i++)
	printf("%d\n",ans[i]);
}
