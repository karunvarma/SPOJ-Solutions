#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[300];
	while(cin>>s)
	{
		char a[300];
		int i,j,k,l=strlen(s);
		bool u=false,c=false,e=true;
		
		for(i=0;i<l;i++)
		{
			if(s[i]>='A' && s[i]<='Z')
			c=true;
			else if(s[i]=='_')
			u=true;
			if(!(s[i]=='_' || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) 
			{
				e=false;
			}
		}
		for(i=0;i<l-1;i++)
		{
			if(s[i]=='_'&& s[i+1]=='_')
			e=false;
		}
		
		if(!e || s[0]=='_' || (s[0]>='A' && s[0]<='Z') || s[l-1]=='_')
		{
			cout<<"Error!\n";
		}
		else if(c && u)
		{
			cout<<"Error!\n";
		}
		else if(c)
		{
			j=0;
			for(i=0;i<l;i++)
			{
				if(s[i]>='A' && s[i]<='Z')
				{
					a[j++]='_';
					a[j++]=s[i]-'A'+'a';
				}
				else
				a[j++]=s[i];
			}
			a[j]=0;
			cout<<a<<endl;
		}
		else if(u)
		{
			j=0;
			for(i=0;i<l;i++)
			{
				if(s[i]=='_')
				{
					i++;
					a[j++]=s[i]-'a'+'A';
				}
				else
			    a[j++]=s[i];
			}
			a[j++]=s[i];
			cout<<a<<endl;
		}
		else
		cout<<s<<endl;
	}
}
