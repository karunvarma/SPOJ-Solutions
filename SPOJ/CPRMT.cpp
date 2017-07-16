#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[1001],b[1001];
	int ca[26],cb[26],i,c,j;
	
	while(cin>>a)
	{
		cin>>b;
		for(i=0;i<26;i++)
		{
			ca[i]=cb[i]=0;
		}
		for(i=0;i<strlen(a);i++)
		{
			ca[a[i]-'a']++;
		}
		for(i=0;i<strlen(b);i++)
		{
			cb[b[i]-'a']++;
		}
		for(i=0;i<26;i++)
		{
			c=min(ca[i],cb[i]);
			for(j=0;j<c;j++)
			printf("%c",'a'+i);
		}
		cout<<endl;
		
	}
}
