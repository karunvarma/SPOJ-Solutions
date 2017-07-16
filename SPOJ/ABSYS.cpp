#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		char a[20],b[20],c[20],d,e;
		int n1,n2,n3;
		cin>>a;
		cin>>d;
		cin>>b;
		cin>>e;
		cin>>c;
		
		for(i=0;i<strlen(a);i++)
		{
		  if(a[i]=='m')
		  {
			n2=0,i=0;
			while(b[i]<='9' && b[i]>='0')
			{
				n2=n2*10+(b[i]-'0');
				i++;
			}
			n3=0,i=0;
			while(c[i]>='0' && c[i]<='9')
			{
				n3=n3*10+(c[i]-'0');
				i++;
			}
			n1=n3-n2;
			goto hell;
		  }
	    }
	    for(i=0;i<strlen(b);i++)
		{
		  if(b[i]=='m')
		  {
			n1=0,i=0;
			while(a[i]<='9' && a[i]>='0')
			{
				n1=n1*10+(a[i]-'0');
				i++;
			}
			n3=0,i=0;
			while(c[i]>='0' && c[i]<='9')
			{
				n3=n3*10+(c[i]-'0');
				i++;
			}
			n2=n3-n1;
		    goto hell;	
		  }
	    }
	    for(i=0;i<strlen(c);i++)
	    {
		
		   if(c[i]=='m')
		  {
			n2=0,i=0;
			while(b[i]<='9' && b[i]>='0')
			{
				n2=n2*10+(b[i]-'0');
				i++;
			}
			n1=0,i=0;
			while(a[i]>='0' && a[i]<='9')
			{
				n1=n1*10+(a[i]-'0');
				i++;
			}
			n3=n1+n2;
			goto hell;
		  }
	    }
	    hell:
		cout<<n1<<" + "<<n2<<" = "<<n3<<endl;
	}
}
