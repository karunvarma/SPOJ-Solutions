#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		map<int,int> m;
		
		int n,i,j,k,l;
		cin>>n;
		
		while(n--)
		{
			cin>>i>>j;
			m[i]=1;
			m[j]=-1;
		}
		k=0,l=0;
		for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
		{
			 l+=(*it).second;
			 if(l>k)
			 k=l;
		}
		cout<<k<<endl;
	}
}
