#include<bits/stdc++.h>
using namespace std;

int par[10010],rank[10010];

int find(int x)
{
	if(x==par[x])
	return x;
	return find(par[x]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,k,m,n,ans=0;
		char a[20];
		scanf("%d",&n);
		
	//	map<int,string> my;
		vector<pair<int,pair<int,int> > > v;
		
		for(i=1;i<=n;i++)
		{
			 par[i]=i;
			 rank[i]=0;
		     scanf("%s",a);
		//	 my[i]=a;
			 
			 scanf("%d",&m);
			 while(m--)
			 {
			   scanf("%d",&j);
			   scanf("%d",&k);
			   v.push_back(make_pair(k,make_pair(i,j)));
		     }
		}
		
		sort(v.begin(),v.end());
		
		for(i=0;i<v.size();i++)
		{
			 j=find((v[i].second).first);
			 k=find((v[i].second).second);
			 
			 if(j!=k)
			 {
			 	ans+=v[i].first;
			 	if(rank[j]<rank[k])
			 	{
			 		par[j]=k;
				}
				else if(rank[j]>rank[k])
				{
					par[k]=j;
				}
				else
				{
					par[k]=j;
					rank[j]++;
				}
			 }
		}
		printf("%d\n",ans);
	}
}
