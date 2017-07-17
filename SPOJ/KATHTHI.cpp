#include<bits/stdc++.h>
using namespace std;

char a[1010][1010];
int dis[1010][1010];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j,k,x,y;
		scanf("%d",&n);
		scanf("%d",&m);
		
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			for(j=0;j<m;j++)
			{
				dis[i][j]=INT_MAX;
			}
		}
		
		deque< pair<int,int> > q;
		dis[0][0]=0;
		q.push_back(make_pair(0,0));
		
		int r[4]={0,-1,0,1};
		int p[4]={1,0,-1,0};
		
		while(!q.empty())
		{
			x=(q.front()).first;
			y=(q.front()).second;
			
			q.pop_front();
			
			for(i=0;i<4;i++)
		    {
		    	  j=x+r[i];
		    	  k=y+p[i];
		    	  
		    	  if(j<n && j>=0 && k<m && k>=0)
		    	  {
		    	  	    if( a[x][y]==a[j][k] && dis[j][k]>dis[x][y] )
		    	  	    {
		    	  	     	dis[j][k]=dis[x][y];
							q.push_front(make_pair(j,k));   	
						}
						else if(a[x][y]!=a[j][k] && dis[j][k]>dis[x][y]+1)
						{
							dis[j][k]=dis[x][y]+1;
							q.push_back(make_pair(j,k));
						}
				  }
			}
		}
		cout<<dis[n-1][m-1]<<endl;
		
	}
}
