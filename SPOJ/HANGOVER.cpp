#include<bits/stdc++.h>
using namespace std;
int main()
{
	long double n,sum;
	cin>>n;
	while(n>0)
	{
		int i;
		sum=0;
		for(i=1;n>sum;i++)
		{
			sum=sum+(1.0)/(i+1);
		}
		cout<<i-1<<" card(s)"<<endl;
		cin>>n;
	}
}
