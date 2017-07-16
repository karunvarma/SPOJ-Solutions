#include<bits/stdc++.h>
using namespace std;

int cost[]={0,1,1,1,1,2,3,5,11};

int main()
{
	int n,i,j,k,p,q,l,ans=0;
	char a[100],b[100];
	cin>>n;
	getchar();
	
	vector<pair<string,int> > v[n];
	map<string,int> m;
	
	for(i=0;i<n;i++)
	{
	   gets(a);
	   l=strlen(a);
	   k=0;
	   
	   for(j=0;j<l;j++)
	   {
	   	   while(a[j]==' ' && j<l)
	   	   j++;
	   	 
	       while(a[j]>=33 && a[j]<=126 && j<l)
		   b[k++]=a[j++];
		   
		   if(a[j]==' ')
		   {
		       b[k]=0;
			   v[i].push_back(make_pair(b,k));
			   m[b]++;
			   k=0;	
		   } 	
       }
       if(a[j-1]!=' ')
       {
       	  b[k]=0;
		  v[i].push_back(make_pair(b,k));
		  m[b]++;
	   }
    }
    
    for(i=0;i<n;i++)
    {
    	k=0;
    	for(j=0;j<v[i].size();j++)
    	{
    		if(m[v[i][j].first]==1)
    		{
    			p=v[i][j].second;
    			if(p>7)
    			p=8;
    			k+=cost[p];
			}
		}
		ans=max(ans,k);
	}
	cout<<ans<<endl;
}
