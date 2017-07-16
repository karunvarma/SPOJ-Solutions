#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,i,j,k,s,x,y,u;
		cin>>n;
		u=n;
		s=1+ceil((double)(-1+(double)sqrt(1+8*n))/2);
		
	    n=(n)-(s-2)*(s-1)/2;
	    
	    if(s%2==1)
	    {
	         x=1,y=s-1;
	         for(i=0;i<n-1;i++)
	         {
	         	x++;
	         	y--;
			 }
	    	 cout<<"TERM "<<u<<" IS "<<x<<"/"<<y<<endl;
		}
		else
		{
			x=s-1,y=1;
			for(i=0;i<n-1;i++)
			{
				x--;
				y++;
			}
			cout<<"TERM "<<u<<" IS "<<x<<"/"<<y<<endl;
		}
	}
}
