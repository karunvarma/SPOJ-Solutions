#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i,j,dif;
		cin>>n>>k;
		long long a[n];
		
		for(i=0;i<n;i++)
		cin>>a[i];
		
		sort(a,a+n);
		dif=a[n-1]-a[0];
		
		for(i=0;i+k-1<n;i++)
		{
			if(a[i+k-1]-a[i]<dif)
			{
				dif=a[i+k-1]-a[i];
			}
		}
		cout<<dif<<endl;
	}
}
