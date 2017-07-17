#include<bits/stdc++.h>
using namespace std;

int a[1001];

int main()
{
	for(int i=0;i<1001;i++)
	{
		a[i]=0;
	}
	long long n,i,j,k,c=0;
	cin>>n;
	
	if(n<=1000)
	a[n]=1;
	while(1)
	{
		i=n;
		n=0;
		while(i>0)
		{
			n+=(i%10)*(i%10);
			i=i/10;
		}
		c++;
		if(n==1)
		{
			cout<<c<<endl;
			break;
		}
		if(a[n]==1)
		{
			cout<<"-1\n";
			break;
		}
		a[n]=1;
	}
}
