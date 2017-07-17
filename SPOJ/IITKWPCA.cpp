#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		char a[10001],b[10001];
		//scanf(" %[^\n]s",a);
		gets(a);
		
		int i,j,k=0,l=strlen(a),c=0;
		map<string,int> m;
		
		for(i=0;i<l;)
		{
			if(a[i]!=' ')
			{
			     b[c++]=a[i];
			     i++;
			     k=1;
		    }
			else if(a[i]==' ' && k)
			{
				b[c]=0;
				c=0;
				m[b]=1;
				while(a[i]==' ' && i<l)
				i++;
				
	            k=0;
			}
			else
			i++;
		}
		if(k)
		{
		  b[c]=0;
		  m[b]=1;
	    }
	     cout<<m.size()<<endl;
	}
}
