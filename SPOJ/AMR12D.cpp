#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s[200];
		cin>>s;
		int l=strlen(s),i,j,c=0;
		for(i=0;i<l/2;i++)
		{
			if(s[i]==s[l-i-1])
			{
				c++;
			}
		}
		if(c==l/2)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
}
