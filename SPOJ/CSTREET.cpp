#include<bits/stdc++.h>
using namespace std;
int scan()
{
    int n=0;
    char ch=getchar_unlocked();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar_unlocked();
    }
 
    while (ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar_unlocked();
    }
 
    return n;
}

int main()
{
	int t;
	t=scan();
	while(t--)
	{
		int p,n,m,i,j,k,l;
		p=scan();
		n=scan();
		m=scan();
        
        vector<pair<int,int> > g[n+1];
		pair<int,int> x;
		
		while(m--)
		{
		    i=scan();
		    j=scan();
		    k=scan();
			g[i].push_back(make_pair(-k,j));	
			g[j].push_back(make_pair(-k,i));
		}

        bool vis[n+1];
        for(i=1;i<=n;i++)
        vis[i]=false;
        
        priority_queue<pair<int,int> > q;
        l=0;
        q.push(make_pair(0,1));
        
        while(!q.empty())
        {
        	x=q.top();
        	q.pop();
        	if(vis[x.second])
        	continue;
        	
			l+=-x.first;
        	vis[x.second]=true;
        	
        	for(i=0;i<g[x.second].size();i++)
        	{
        		if(!vis[g[x.second][i].second])
        		q.push(g[x.second][i]);
			}
		}
        cout<<l*p<<endl;
	}
}








/*int pa[1001],rank[1001];

int find(int i)
{
	if(i==pa[i])
	return i;
	return find(pa[i]);
}

void uni(int i,int j)
{
	int pi=find(i),pj=find(j);
	
	if(rank[pi]<rank[pj])
	{
		pa[pi]=pj;
		rank[pj]++;
	}
	else if(rank[pi]>rank[pj])
	{
		pa[pj]=pi;
		rank[pi]++;
	}
	else
	{
		pa[pj]=pi;
		rank[pi]++;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int p,n,m,i,j,k,l,c,sum=0;
		cin>>p;
		cin>>n;
		cin>>m;
		
		for(i=1;i<=n;i++)
		{
			pa[i]=i;
			rank[i]=0;
		}
		
		vector< pair<int,pair<int,int> > > v;
		
		for(i=0;i<m;i++)
		{
			cin>>l>>j>>k;
			v.push_back(make_pair(k,make_pair(l,j)));
		}

		sort(v.begin(),v.begin()+m);
		
		for(i=0;i<m;i++)
		{
			j=(v[i].second).first;
			k=(v[i].second).second;
			c=v[i].first;
			
			if(find(j)==find(k))
			continue;
			
			sum+=c;
			
			uni(j,k);
		}

		cout<<sum*p<<endl;
	}
}
*/
