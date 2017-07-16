#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		float n,i,ans=0;
		cin>>n;
		i=n;
		while(i)
		{
			ans+=(n/i);
			i--;
		}
		printf("%.2f\n",ans);
	}
}
