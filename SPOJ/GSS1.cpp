#include<bits/stdc++.h>
using namespace std;

int scan()
{
    register int c = getchar_unlocked();
    int x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
    if(c=='-') {neg=1;c=getchar_unlocked();}
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
    
    return x;
}

struct node
{
	int left,right,best,sum;
}tree[200010];

int a[50010];

node merge(node n1,node n2)
{
	node temp;
	
	temp.left=(n1.left>n1.sum+n2.left)?n1.left:n1.sum+n2.left;
	temp.right=n2.right>n2.sum+n1.right?n2.right:n2.sum+n1.right;
	temp.sum=n1.sum+n2.sum;
	temp.best=max(n1.right+n2.left,max(n1.best,n2.best));
	
	return temp;
}

void built(int start,int end,int n)
{
	if(start==end)
	{
		tree[n].best=tree[n].left=tree[n].right=tree[n].sum=a[start];
		return ;
	}
	int mid=(start+end)/2;
	built(start,mid,n*2);
	built(mid+1,end,n*2+1);
	tree[n]=merge(tree[n*2],tree[n*2+1]);
}
node query(int start,int end,int n,int l,int r)
{
	
	if(l<=start && r>=end)
	return tree[n];
	
	int mid=(start+end)/2;
	
	if(r<=mid)
	return query(start,mid,n*2,l,r);
	else if(l>mid)
	return query(mid+1,end,n*2+1,l,r);
	else
	return merge(query(start,mid,n*2,l,r),query(mid+1,end,n*2+1,l,r));
}
int main()
{
	int n,i,j,k,q;
	n=scan();
	
	for(i=1;i<=n;i++)
	a[i]=scan();
	
	built(1,n,1);
	
	q=scan();
	while(q--)
	{
		i=scan();
		j=scan();
		node tem=query(1,n,1,i,j);
		printf("%d\n",tem.best);
	}
}
