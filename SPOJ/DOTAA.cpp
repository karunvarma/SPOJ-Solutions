#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,d,i,j=0,k;
		cin>>n>>m>>d;
		while(n--)
		{
			cin>>i;
			j+=i/d-1;
			if(i%d!=0)
			{
				j++;
			}
		}
		if(j>=m)
		{
			cout<<"YES\n";
		}
		else
		cout<<"NO\n";
	}
}
