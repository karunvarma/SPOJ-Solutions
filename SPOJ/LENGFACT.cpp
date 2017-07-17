#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long double pi,n,i;
		long long k;
		
		cin>>n;
		pi=3.1415926535897932384626433;
		if(n==0 || n==1 || n==2)
		i=0;
		else
		i= ((log(2*pi*n))/2 + n*( log(n)-1 ))/(log(10.0));
		k=i;
		k++;
		cout<<k<<endl;
	}
}
