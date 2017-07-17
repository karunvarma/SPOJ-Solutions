#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	while(n!=-1)
	{
		int i,j,k;
		if(n>m)
		{
			if(m==0)
			cout<<n<<endl;
			else
			{
				cout<<ceil((double)n/(m+1))<<endl;
			}
		}
		else
		{
			if(n==0)
			cout<<m<<endl;
			else
			{
				cout<<ceil((double)m/(n+1))<<endl;
			}
		}
		cin>>n>>m;
	}
}
