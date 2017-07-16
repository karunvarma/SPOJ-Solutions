#include<bits/stdc++.h>
using namespace std;

int dis[200][200],n,m;
char a[200][200];

void bfs(pair<int,int> p)
{
	queue<pair<int,int> > q;
	q.push(p);
	while(!q.empty())
	{
		int x=(q.front()).first,y=(q.front()).second;
		q.pop();
		if(dis[x-1][y]>dis[x][y]+1 && x-1>=0)
		{
			dis[x-1][y]=dis[x][y]+1;
			q.push(make_pair(x-1,y));
		}
		if(dis[x+1][y]>dis[x][y]+1 && x+1<n)
		{
			dis[x+1][y]=dis[x][y]+1;
			q.push(make_pair(x+1,y));
		}
		if(dis[x][y-1]>dis[x][y]+1 && y-1>=0)
		{
			dis[x][y-1]=dis[x][y]+1;
			q.push(make_pair(x,y-1));
		}
		if(dis[x][y+1]>dis[x][y]+1 && y+1<m)
		{
			dis[x][y+1]=dis[x][y]+1;
			q.push(make_pair(x,y+1));
		}
	}
}

int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	
	vector<pair<int,int> > v;
	
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			for(j=0;j<m;j++)
			{
				dis[i][j]=INT_MAX;
				
				if(a[i][j]=='1')
				{
					dis[i][j]=0;
					v.push_back(make_pair(i,j));
				}
			}
		}
		for(i=0;i<v.size();i++)
		{
			bfs(v[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%d ",dis[i][j]);
			}
			printf("\n");
		}
		v.clear();
	}
}
