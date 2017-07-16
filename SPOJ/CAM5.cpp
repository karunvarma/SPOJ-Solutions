#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long n,m,i,j,k,c,count=0;
		scanf("%lld",&n);
		scanf("%lld",&m);
		
		vector<vector<long long> > v(n+1);
		
		while(m--)
		{
			scanf("%lld",&i);
			scanf("%lld",&j);
			i++,j++;
			v[i].push_back(j);
			v[j].push_back(i);
		}
		
		bool visit[n+1];
		for(i=1;i<=n;i++)
		visit[i]=false;
		
		for(k=1;k<=n;k++)
		{
			if(!visit[k])
			{
				count++;
				
				visit[k]=true;
				queue<long long> q;
				q.push(k);
				
				while(!q.empty())
				{
					c=q.front();
					q.pop();
					for(i=0;i<v[c].size();i++)
					{
						if(!visit[v[c][i]])
						{
							q.push(v[c][i]);
							visit[v[c][i]]=true;
						}
					}
				}
			}
		}
		cout<<count<<endl;
	}
}
