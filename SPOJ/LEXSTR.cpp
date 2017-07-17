#include<bits/stdc++.h>
using namespace std;

char s[100011];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,n,m,x;
		cin>>s;
		
		n=strlen(s);
		cin>>m;
		
		vector<int> v[n];
		bool use[n];
		
		for(i=0;i<n;i++)
		use[i]=false;
		
		while(m--)
		{
			cin>>i>>j;
			v[i].push_back(j);
			v[j].push_back(i);
			use[i]=use[j]=true;
		}
		
		queue<int> q;
		bool visit[n];
		
		for(i=0;i<n;i++)
		visit[i]=false;
		
		priority_queue<int> p,st;
		
        for(j=0;j<n;j++)
        {
		    if(use[j] && !visit[j])
		    {
		     	visit[j]=true;
		     	q.push(j);
		     	st.push(j);
		     	p.push(s[j]);
			}
        	while(!q.empty())
        	{
        		x=q.front();
        		q.pop();
        	
        		for(i=0;i<v[x].size();i++)
        		{
        			if(visit[v[x][i]]==false)
        			{
        				q.push(v[x][i]);
        				visit[v[x][i]]=true;
        				st.push(v[x][i]);
		     			p.push(s[v[x][i]]);
					}
				}
			}
			while(!st.empty())
			{
				s[st.top()]=p.top();
				st.pop();
				p.pop();
			}
		}
		
		cout<<s<<endl;
	}
}
