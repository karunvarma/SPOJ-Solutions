#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a[1001],i,j,k;
	a[1]=5,a[2]=12;
	
	for(i=3;i<1001;i++)
	{
		a[i]=a[i-1]+a[i-1]-a[i-2]+3;
	}
	cin>>i;
	while(i)
	{
		cout<<a[i]<<endl;
		cin>>i;
	}
}
