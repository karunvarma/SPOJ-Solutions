#include<bits/stdc++.h>
using namespace std;
int main()
{
	long double n;
	cin>>n;
	while(n)
	{
		long double pie=3.1415926;
		n=(n*n)/(pie*2);
		cout<<fixed<<setprecision(2)<<n<<endl;
		cin>>n;
	}
}
