#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	long long s[]={2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921, 1190281};
	while(t--)
	{
		long long a,i,b,c=0,l1,l2;
		cin>>a>>b;
		
		for(i=0;s[i]<=b;i++)
		{
			c=i+1;
		}
		for(i=0;s[i]<a;i++)
		;
		
		c=c-i;
		
		if(b==1)
		c=0;
		cout<<c<<endl;
	}
}
