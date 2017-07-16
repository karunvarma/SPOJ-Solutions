#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,j,n;
	cin>>n;
	
	while(n!=-1)
	{
		i=0;
		while((i+1)*(i+1)*(i+1)-i*i*i<=n)
		{
			if((i+1)*(i+1)*(i+1)-i*i*i==n)
			{
				cout<<"Y\n";
				goto hell;
			}
			i++;
		}
		cout<<"N\n";
		hell:
		cin>>n;
	}
	
}
