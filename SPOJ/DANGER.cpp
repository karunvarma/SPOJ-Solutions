#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[5];
	cin>>a;
	while(a[0]!='0' || a[1]!='0')
	{
		long long n,c=0,i,j,k;
		n= ((a[0]-48)*10+(a[1]-48))*pow(10,a[3]-48);
		
		k=n;
		while(k>1)
		{
			k=k/2;
			c++;
		}
		n=n-pow(2,c);
		
		cout<<1+(n)*2<<endl;
		cin>>a;
	}
	
 } 
