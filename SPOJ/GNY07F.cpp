#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,u=0;
	cin>>t;
	getchar();
		while(t--)
	{
		u++;
		int n,i,j,k;
		
		string s;
		getline(cin,s);;
		
		k=0,j=0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='[')
			j++;
			else
			j--;
			
			k=max(j,k);
		}
		
		long ans=1;
		while(k--)
		{
			ans=ans*2;
		}
		cout<<u<<" "<<ans<<endl;
	}
}
