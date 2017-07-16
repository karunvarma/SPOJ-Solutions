#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,k,ans=0;
	
	cin>>n;
	
	vector <vector<int> > a(n+1);
	for(i=1;i<n+1;i++)
	{
		    a[i].push_back(1);
	}
	
	
	for(i=2;i<=pow(n,0.5);i++)
	{
		j=2;
  	    while(j*i<=n)
  	   {
	   	   a[j*i].push_back(i);
		   j++;
	   }	
	}
	
	for(i=1;i<n+1;i++)
	{
		for(j=0;a[i][j]<=pow(i,0.5) && j<a[i].size();j++)
		{
			ans++;
		}
		
	}
	cout<<ans<<endl;
}
