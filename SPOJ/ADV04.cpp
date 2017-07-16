#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,i,n,a[25];
	
	a[0]=1;
	for(i=1;i<25;i++)
	a[i]=a[i-1]*2;
	
	cin>>t;
	while(t--)
	{
		i=0;
		cin>>n;
		while(n>a[i])
		{
			i++;
		}
		cout<<i+1<<endl;
	}
}
