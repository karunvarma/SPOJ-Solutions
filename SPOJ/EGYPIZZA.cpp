#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,c=1,i;
	cin>>n;
	char a[4];
	int x=0,y=0,z=0;
	
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a[0]=='1' && a[2]=='4')
		x++;
		else if(a[0]=='1')
		y++;
		else
		z++;
	}
	if(z>=x)
	{
		c=c+x;
		z=z-x;
		x=0;
		c=c+z;
		z=0;
	}
	else if(z<x)
	{
		c=c+z;
		x=x-z;
		z=0;
	}
	
	c=c+y/2+x/4;
	y=y%2;
	x=x%4;
	if(y==1 && x<=2)
	{
		c=c+1;
	}
	else if(y==1 && x>2)
	{
		c=c+2;
	}
	else if(y==0 && x!=0) 
	{
		c=c+1;
	}
	cout<<c<<endl;
}
