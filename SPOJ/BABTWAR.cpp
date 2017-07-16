#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l,b,h;
}
a[100];

bool cmp(node i,node j)
{
	if(i.l*i.b==j.l*j.b)
	return i.l>j.l;
	
	return i.l*i.b>j.l*j.b;
}

int n,dp[100][100];

int solve(int i,int j)
{
	if(i>n)
	return 0;
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	int p=0,q=0;
	
	if(a[i].l<a[j].l && a[i].b<a[j].b)
	p=a[i].h+solve(i+1,i);
	
	q=solve(i+1,j);
	
	dp[i][j]=max(p,q);
	return dp[i][j];
}

int main()
{
	
	cin>>n;
	while(n)
	{
		int i,j,k,l,b,h;
		
	    for(i=0;i<=n*3;i++)
	    {
	    	for(j=0;j<=n*3;j++)
	    	{
	    		dp[i][j]=-1;
			}
		}
		
		a[0].l=a[0].b=10000;
		a[0].h=0;
		
		for(i=0,j=1;i<n;i++)
		{
			cin>>l>>b>>h;
			
			if(l>b)
			{
			   a[j].l=l,a[j].b=b,a[j].h=h;
		    }
			else
			{
			    a[j].l=b,a[j].b=l,a[j].h=h;
		    }
			
			j++;
			if(h>b)
			{
			   a[j].l=h,a[j].b=b,a[j].h=l;
		    }
			else
		    {
			  a[j].l=b,a[j].b=h,a[j].h=l;
		    }
			
			j++;
			if(l>h)
			{
			   a[j].l=l,a[j].b=h,a[j].h=b;
	        }
			else
			{
			   a[j].l=h,a[j].b=l,a[j].h=b;
		    }
		    j++;
		}
		n=n*3;
		sort(a,a+j,cmp);
		
		i=solve(1,0);
		cout<<i<<endl;
		cin>>n;
	}
}
