#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,c,i,j,k,low,high,mid,prev;
		cin>>n>>c;
		long long a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		
		sort(a,a+n);
		
	
		
		low=a[0],high=a[n-1],k=1;
		
		while(low+1<high)
		{
			k=1,prev=a[0];
			mid=(low+high)/2;
			
			for(i=1;i<n;i++)
			{
				if(a[i]-prev>=mid)
				{
					k++;
					prev=a[i];
				}		
			}
			if(k>=c)
			{
				low=mid;
			}
			else
			{
				high=mid-1;
			}
		}
		if(low+1==high)
		{
			k=1,prev=a[0];
			for(i=1;i<n;i++)
			{
				if(a[i]-prev>=high)
				{
					k++;
					prev=a[i];
				}
			}
			if(k>=c)
			{
				cout<<high<<endl;
				goto hell;
			}
		}
		cout<<low<<endl;
		hell:;
	}
}
