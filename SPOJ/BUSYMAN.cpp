#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,i,j,k,c=1,t;
		cin>>n;
		
		vector <pair <long long, long long> > a;
		
		for(k=0;k<n;k++)
		{
			cin>>i>>j;
			a.push_back(make_pair(j,i));
		}
		sort(a.begin(),a.end());
		t=(a[0]).first;
		
		for(i=1;i<n;i++)
		{
		    if(t<=(a[i]).second)
			{
				c++;
				t=a[i].first;
			}	
		}
		cout<<c<<endl;
	}
}
