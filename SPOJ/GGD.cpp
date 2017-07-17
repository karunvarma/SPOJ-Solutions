#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,u=0;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		u++;
		if(n<4)
		cout<<"Case "<<u<<": "<<n-1<<" "<<n<<endl;
		else
		{
			if(n%2==0)
			{
				cout<<"Case "<<u<<": "<<n/2<<" "<<n<<endl;
			}
			else
			{
				cout<<"Case "<<u<<": "<<n/2<<" "<<n-1<<endl;
			}
		}
	}
}
