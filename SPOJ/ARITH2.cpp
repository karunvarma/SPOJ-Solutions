#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n1,n2;
		char c;
		cin>>n1;
		while(1)
		{
			cin>>c;
			if(c=='=')
			break;
			cin>>n2;
			if(c=='+')
			n1=n1+n2;
			else if(c=='-')
			n1=n1-n2;
			else if(c=='*')
			n1=n1*n2;
			else if(c=='/')
			n1=n1/n2;
			else if(c=='%')
			n1=n1%n2;
			else if(c=='^')
			n1=pow(n1,n2);
		}
		cout<<n1<<endl;
		
	}
}
