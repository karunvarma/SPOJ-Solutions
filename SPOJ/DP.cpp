#include<bits/stdc++.h>
using namespace std;

vector<long long> v;
long long ans;		
		
void solve(long long a,long long b,int n)
{
	if(n<0)
	{
		if(a>=b && a<ans)
		{
		  ans=a;
		  return;
	    }
	    if(b>a && b<ans)
	    {
	    	ans=b;
	    	return ;
		}
		return ;
	}
	solve(a+2*v[n],b,n-1);
	solve(a,b+2*v[n],n-1);
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		ans=INT_MAX;
		
		long long n,m,i,j,k;
		cin>>n>>m;
		
		char a[n][m];
		bool visit[n][m];
		long long d[n][m];
		
		vector<pair<long long,long long> > h;
		priority_queue<pair<long long,pair<long long,long long> > > q;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
				visit[i][j]=false;
				d[i][j]=INT_MAX;
				
				if(a[i][j]=='$')
				h.push_back(make_pair(i,j));
			    
				if(a[i][j]=='X')
				{
				     d[i][j]=0;
					 q.push(make_pair(0,make_pair(i,j)));	
				}	
			}
		}
		
		if(h.size()==0)
		{
			cout<<"0\n";
			continue;
		}
		
		while(!q.empty())
		{
			long long dis=-(q.top()).first;
			long long x=((q.top()).second).first,y=((q.top()).second).second;
			q.pop();
						
			if(visit[x][y])
			continue;
			
			if(a[x][y]=='$' || a[x][y]=='X')
			{
				 if(x-1>=0 && visit[x-1][y]==false)
				 {
				 	  d[x-1][y]=min(d[x-1][y],dis+2);
				 	  q.push(make_pair(-d[x-1][y],make_pair(x-1,y)));
				 }
				 if(x+1<n && visit[x+1][y]==false)
				 {
				 	  d[x+1][y]=min(d[x+1][y],dis+2);
				 	  q.push(make_pair(-d[x+1][y],make_pair(x+1,y)));
				 }
				 if(y-1>=0 && visit[x][y-1]==false)
				 {
				 	  d[x][y-1]=min(d[x][y-1],dis+2);
				 	  q.push(make_pair(-d[x][y-1],make_pair(x,y-1)));
				 }
				 if(y+1<m && visit[x][y+1]==false)
				 {
				 	  d[x][y+1]=min(d[x][y+1],dis+2);
				 	  q.push(make_pair(-d[x][y+1],make_pair(x,y+1)));
				 }
			}
			else
			{
				if(x-1>=0 && !visit[x-1][y])
				{
					if(a[x-1][y]=='$')
					{
						d[x-1][y]=min(d[x-1][y],dis+2);
				 	    q.push(make_pair(-d[x-1][y],make_pair(x-1,y)));
					}
					else if(a[x-1][y]-a[x][y]==-1 || a[x-1][y]-a[x][y]==1)
					{
						d[x-1][y]=min(d[x-1][y],dis+3);
				 	    q.push(make_pair(-d[x-1][y],make_pair(x-1,y)));
					}
					else if(a[x-1][y]-a[x][y]==0)
					{
						d[x-1][y]=min(d[x-1][y],dis+1);
				 	    q.push(make_pair(-d[x-1][y],make_pair(x-1,y)));
					}
				}
				if(x+1<n && !visit[x+1][y])
				{
					if(a[x+1][y]=='$')
					{
						d[x+1][y]=min(d[x+1][y],dis+2);
				 	    q.push(make_pair(-d[x+1][y],make_pair(x+1,y)));
					}
					else if(a[x+1][y]-a[x][y]==-1 || a[x+1][y]-a[x][y]==1)
					{
						d[x+1][y]=min(d[x+1][y],dis+3);
				 	    q.push(make_pair(-d[x+1][y],make_pair(x+1,y)));
					}
					else if(a[x+1][y]-a[x][y]==0)
					{
						d[x+1][y]=min(d[x+1][y],dis+1);
				 	    q.push(make_pair(-d[x+1][y],make_pair(x+1,y)));
					}
				}
				if(y-1>=0 && !visit[x][y-1])
				{
					if(a[x][y-1]=='$')
					{
						d[x][y-1]=min(d[x][y-1],dis+2);
				 	    q.push(make_pair(-d[x][y-1],make_pair(x,y-1)));
					}
					else if(a[x][y-1]-a[x][y]==-1 || a[x][y-1]-a[x][y]==1)
					{
						d[x][y-1]=min(d[x][y-1],dis+3);
				 	    q.push(make_pair(-d[x][y-1],make_pair(x,y-1)));
					}
					else if(a[x][y-1]-a[x][y]==0)
					{
						d[x][y-1]=min(d[x][y-1],dis+1);
				 	    q.push(make_pair(-d[x][y-1],make_pair(x,y-1)));
					}
				}
				if(y+1<m && !visit[x][y+1])
				{
					if(a[x][y+1]=='$')
					{
						d[x][y+1]=min(d[x][y+1],dis+2);
				 	    q.push(make_pair(-d[x][y+1],make_pair(x,y+1)));
					}
					else if(a[x][y+1]-a[x][y]==-1 || a[x][y+1]-a[x][y]==1)
					{
						d[x][y+1]=min(d[x][y+1],dis+3);
				 	    q.push(make_pair(-d[x][y+1],make_pair(x,y+1)));
					}
					else if(a[x][y+1]-a[x][y]==0)
					{
						d[x][y+1]=min(d[x][y+1],dis+1);
				 	    q.push(make_pair(-d[x][y+1],make_pair(x,y+1)));
					}
				}
			}
			visit[x][y]=true;
		}
		
		for(i=0;i<h.size();i++)
		{
			long long x=h[i].first,y=h[i].second;
			
			if(visit[x][y])
			v.push_back(d[x][y]);
			else
			{
				cout<<"-1\n";
				goto hell;
			}
			
		}
		
		if(v.size()==1)
		{
			cout<<v[0]<<endl;
			goto hell;
		}
		else if(v.size()==2)
		{
			cout<<max(v[0],v[1])<<endl;
			goto hell;
		}
		else
		{
			sort(v.begin(),v.end());
			n=v.size();
			for(i=n-2;i>=0;i--)
			{
				long long temp1=v[n-2],temp2=v[i];
				v[n-2]=temp2,v[i]=temp1;
				
				solve(v[n-1],v[n-2],n-3);
				
				v[n-2]=temp1,v[i]=temp2;
			}
			cout<<ans<<endl;
		}
		hell:;
		v.clear();
	}
}
