#include<bits/stdc++.h>
using namespace std;

bool visit[101][101];
long long dis[101][101],n,m;
char a[101][101];

long long bfs(pair<long long,long long> p)
{
	long long d=1;
	queue<pair<long long,long long> > q;
	q.push(p);
	visit[p.first][p.second]=true;
	
	while(!q.empty())
	{
		long long x=(q.front()).first,y=(q.front()).second;
		q.pop();
		
		d=max(d,dis[x][y]);
		
		if(x+1<n && y+1<m)
		{
			if(a[x+1][y+1]==a[x][y]+1 && !visit[x+1][y+1])
			{
				dis[x+1][y+1]=dis[x][y]+1;
				q.push(make_pair(x+1,y+1));
				visit[x+1][y+1]=true;
			}
		}
		if(x-1>=0 && y-1>=0)
		{
			if(a[x-1][y-1]==a[x][y]+1 && !visit[x-1][y-1])
			{
				dis[x-1][y-1]=dis[x][y]+1;
				q.push(make_pair(x-1,y-1));
				visit[x-1][y-1]=true;
			}
		}
		if(x-1>=0 && y+1<m)
		{
			if(a[x-1][y+1]==a[x][y]+1 && !visit[x-1][y+1])
			{
				dis[x-1][y+1]=dis[x][y]+1;
				q.push(make_pair(x-1,y+1));
				visit[x-1][y+1]=true;
			}
		}
		if(x+1<n && y-1>=0)
		{
			if(a[x+1][y-1]==a[x][y]+1 && !visit[x+1][y-1])
			{
				dis[x+1][y-1]=dis[x][y]+1;
				q.push(make_pair(x+1,y-1));
				visit[x+1][y-1]=true;
			}
		}
		if(x+1<n)
		{
			if(a[x+1][y]==a[x][y]+1 && !visit[x+1][y])
			{
				dis[x+1][y]=dis[x][y]+1;
				q.push(make_pair(x+1,y));
				visit[x+1][y]=true;
			}
		}
		if(x-1>=0)
		{
			if(a[x-1][y]==a[x][y]+1 && !visit[x-1][y])
			{
				dis[x-1][y]=dis[x][y]+1;
				q.push(make_pair(x-1,y));
				visit[x-1][y]=true;
			}
		}
		if(y+1<m)
		{
			if(a[x][y+1]==a[x][y]+1 && !visit[x][y+1])
			{
				dis[x][y+1]=dis[x][y]+1;
				q.push(make_pair(x,y+1));
				visit[x][y+1]=true;
			}
		}
		if(y-1>=0)
		{
			if(a[x][y-1]==a[x][y]+1 && !visit[x][y-1])
			{
				dis[x][y-1]=dis[x][y]+1;
				q.push(make_pair(x,y-1));
				visit[x][y-1]=true;
			}
		}
	}
	return d;
}

int main()
{
	long long ans=0,i,j,t=0;
	cin>>n>>m;
	
	vector <pair<long long,long long> > v;
	
	while(n && m)
	{
		t++;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
				visit[i][j]=false;
				dis[i][j]=1;
				
				if(a[i][j]=='A')
				v.push_back(make_pair(i,j));
				
			}
		}
		
		ans=0;
		
		for(i=0;i<v.size();i++)
		{
			 j=bfs(v[i]);
			 ans=max(ans,j);
		}
		
		cout<<"Case "<<t<<": "<<ans<<endl;
        cin>>n>>m;
        v.clear();
	}
}
