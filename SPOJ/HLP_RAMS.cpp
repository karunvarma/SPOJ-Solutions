#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,i,j,k,e,o;
		
		cin>>n;
		
		k=0;
		i=n;
		while(i)
		{
			k++;
			i=i/2;
		}
		
		o=1;
		for(i=0;i<k;i++)
		{
			if(((n>>i)&1)==1)
			{
			     o=o*2;
			} 
		}
		e=n+1-o;
		cout<<e<<" "<<o<<endl;
	}
}
