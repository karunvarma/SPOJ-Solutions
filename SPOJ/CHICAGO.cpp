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
	int n,m,i,j,k,s=1;
	n=scan();
	m=scan();
	
	while(n)
	{
		vector<pair<int,int> > grp[n+1];
		
		while(m--)
		{
			i=scan();
			j=scan();
			k=scan();
			grp[i].push_back(make_pair(j,k));
			grp[j].push_back(make_pair(i,k));
		}
		
		priority_queue<pair<long double,int> > q;
		long double p[n+1];
		bool visit[n+1];
		
		for(i=1;i<=n;i++)
		{
			p[i]=0.0;
			visit[i]=false;
		}
		p[1]=1;
		q.push(make_pair(1.0,1));
		
		while(!q.empty())
		{
			long double pro=(q.top()).first;
			s=(q.top()).second;
			q.pop();
			if(visit[s])
			continue;
			
			for(i=0;i<grp[s].size();i++)
			{
				if(visit[grp[s][i].first]==false)
				{
				     p[grp[s][i].first]=max(p[grp[s][i].first],(pro*grp[s][i].second)/100.0);
					 q.push(make_pair(p[grp[s][i].first],grp[s][i].first)); 
				}
			}
			visit[s]=true;
		}
		
		printf("%.6Lf percent\n",p[n]*100);
		n=scan();
		if(n==0)
		break;
		m=scan();
	}
}
