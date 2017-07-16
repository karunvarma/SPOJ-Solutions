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

int main()
{
	int t;
	t=scan();
	while(t--)
	{
		int n,m,i,j,k,x,y,d,b,c,ti;
		n=scan();
		m=scan();
		int a[n+1][m+1],dis[n+1][m+1];
		bool v[n+1][m+1];
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				a[i][j]=scan();
				dis[i][j]=999999;
				v[i][j]=false;
			}
		}
		b=scan();
		c=scan();
		ti=scan();
		
		dis[1][1]=a[1][1];
		
		priority_queue<pair<int,pair<int,int> > > p;
		
		p.push(make_pair(-dis[1][1],make_pair(1,1)));
		
		while(!p.empty())
		{
			 x=((p.top()).second).first;
			 y=((p.top()).second).second;
			 d=-(p.top()).first;
			 
			 p.pop();
			 
			 if(v[x][y])
			 continue;
			 
			 if(x+1<=n && !v[x+1][y])
			 {
			 	 dis[x+1][y]=min(dis[x+1][y],d+a[x+1][y]);
			 	 p.push(make_pair(-dis[x+1][y],make_pair(x+1,y)));
			 }
			 if(x-1>0 && !v[x-1][y])
			 {
			 	 dis[x-1][y]=min(dis[x-1][y],d+a[x-1][y]);
			 	 p.push(make_pair(-dis[x-1][y],make_pair(x-1,y)));
			 }
			 if(y+1<=m && !v[x][y+1])
			 {
			 	 dis[x][y+1]=min(dis[x][y+1],d+a[x][y+1]);
			 	 p.push(make_pair(-dis[x][y+1],make_pair(x,y+1)));
			 }
			 if(y-1>0 && !v[x][y-1])
			 {
			 	 dis[x][y-1]=min(dis[x][y-1],d+a[x][y-1]);
			 	 p.push(make_pair(-dis[x][y-1],make_pair(x,y-1)));
			 }
			 
			 v[x][y]=true;
			 
			 if(x==b && y==c)
			 break;
		}
		
		if(dis[b][c]<=ti)
		{
			cout<<"YES\n"<<ti-dis[b][c]<<endl;
		}
		else
		{
			cout<<"NO\n";
		}
	}
}
