#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,d,i,j,k,ans;
	
	cin>>n>>d;
	
	while(n)
	{
		ans=1;
		for(i=2;i<=n;i++)
		{
			ans=(ans+d-1)%i+1;
		}
		cout<<n<<" "<<d<<" "<<ans<<endl;
		cin>>n>>d;
	}
	
}
