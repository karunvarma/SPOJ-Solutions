#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,w,x1,y1,z1,w1,i,j,k,r1,r2,r3,r4,m;
	cin>>x>>y>>z>>w>>x1>>y1>>z1>>w1;
	while(x!=-1)
	{
		r1=ceil((double)x/x1);
		r2=ceil((double)y/y1);
		r3=ceil((double)z/z1);
		r4=ceil((double)w/w1);
		
		m=max(r1,max(r2,max(r3,r4)));
		
		cout<<(x1*m-x)<<" "<<(y1*m-y)<<" "<<(z1*m-z)<<" "<<(w1*m-w)<<endl;
		cin>>x>>y>>z>>w>>x1>>y1>>z1>>w1;
	}
}
