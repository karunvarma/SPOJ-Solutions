#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,u=0;
	scanf("%lld",&t);
	while(t--)
	{
		u++;
		cout<<"Scenario #"<<u<<":\n";
		long long n,i,j,k,m,c,acl;
		scanf("%lld",&n);
		scanf("%lld",&m);
		vector< vector<long long> > v(n+1);
		
		while(m--)
		{
			scanf("%lld",&i);
			scanf("%lld",&j);
			v[i].push_back(j);
			v[j].push_back(i);
		}
		
		int colour[n+1];
		bool visit[n+1];
		for(i=1;i<=n;i++)
		{
			colour[i]=0;
			visit[i]=false;
		}
		
		for(k=1;k<=n;k++)
		{
			if(!visit[k])
			{
				colour[k]=1;
				visit[k]=true;
				acl=2;
				queue<long long> q;
				q.push(k);q.push(0);
		
			while(!q.empty())
			{
				if(q.front()==0)
				{
				  acl=(acl)%2+1;
	  		      q.pop();
	  		      q.push(0);
    			}
				c=q.front();
			
				q.pop();
				for(i=0;i<v[c].size();i++)
				{
					if(colour[c]==colour[v[c][i]])
					{
						cout<<"Suspicious bugs found!\n";
						goto hell;
					}
					if(visit[v[c][i]]==false)
					{
						q.push(v[c][i]);
						colour[v[c][i]]=acl;
						visit[v[c][i]]=true;
					}
				}
			}
	    }
		
	   }
	   	cout<<"No suspicious bugs found!\n";
		hell:	;
	}
}
