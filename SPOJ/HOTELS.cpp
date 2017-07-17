#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,i,j,k,sum=0,max=0;
	cin>>n>>m;
	
	long long a[n];
	
	for(i=0;i<n;i++)
	cin>>a[i];
	
	i=0,j=0;
	while(i<n && j<n)
	{
		sum=sum+a[i];
		i++;
		
		if(sum>m)
		{
			while(sum>m)
			{
				sum=sum-a[j];
				j++;
			}
			if(sum>max)
			max=sum;
		}
		else
		{
			if(sum>max)
			{
				max=sum;
			}
		}
	}
	cout<<max<<endl;
}
