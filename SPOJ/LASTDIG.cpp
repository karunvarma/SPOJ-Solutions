#include<iostream>
using namespace std;

int ans(long long a,long long b)
{
	if(b==0)
	return 1;
	if(b==1)
	return a;
	
	long long i,j,k,t=1;
	k=a;
	
	while(b>=t*2)
    {
  	   t=t*2;
    }
    j=b%t;

	while(t>1)
	{
	    k=k*k;
		k=k%10;
		t=t/2;    	
	}
	k=(k*ans(a,j))%10;		  
	return k;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,i,j,k;
		cin>>a>>b;
	    j=ans(a,b);
	    cout<<j<<endl;
	}
}
