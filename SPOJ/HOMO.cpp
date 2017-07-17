#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,n,one=0,two=0;
	cin>>t;
	map<long long,int> m;
	
	while(t--)
	{
		char a[10];
		cin>>a;
		
		if(a[0]=='i')
		{
			cin>>n;
			
			if(m.find(n)!=m.end())
			{
				m[n]=m[n]+1;
				if(m[n]==2)
				{
					two++;
					one--;
				}
			}
			else
			{
				m[n]=1;
				one++;
			}
		}
		else
		{
			cin>>n;
			
			if(m.find(n)!=m.end())
			{
				 if(m[n]>2)
				 m[n]=m[n]-1;
				 
				 else if(m[n]==2)
				 {
				 	m[n]=1;
				 	two--;
				 	one++;
				 }
				 else if(m[n]==1)
				 {
				 	one--;
				 	m.erase(n);
				 }
			}
		}
		
		if(one+two<2 && two==0)
		cout<<"neither\n";
		else if(one+two>=2 && two<1)
		cout<<"hetero\n";
		else if(one+two>=2 && two>=1)
		cout<<"both\n";
		else 
		cout<<"homo\n";
	}
}
