#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		char p[101],q[101],ch;
		stack<char>s;
		gets(p);
		gets(q);
		
		int lp=strlen(p),lq=strlen(q),cp[26],ap=0,aq=0,cq[26],c[26],i,j,k,odd=0,zero=0;
		
		memset(cp,0,sizeof(cp));
		memset(cq,0,sizeof(cq));
		
		for(i=0;i<lp;i++)
		{
			if(p[i]>='a' && p[i]<='z')
			{
			  cp[p[i]-'a']++;
			  ap++;
		    }
			else if(p[i]>='A' && p[i]<='Z')
			{
				ap++;
			   cp[p[i]-'A']++;
		    }
		}
		for(i=0;i<lq;i++)
		{
			if( q[i]>='a' &&  q[i]<='z')
			{  
			    aq++;
			    cq[q[i]-'a']++;
			}
			else if( q[i]>='A' && q[i]<='Z')
			{
			   cq[q[i]-'A']++;
			   aq++;
		    }
		}
		for(i=0;i<26;i++)
		{
			c[i]=cp[i]-cq[i];
			
			if( (c[i]<0 && ap>=aq) || (c[i]>0 && aq>=ap) )
			{
				cout<<"NO LUCK\n";
				goto hell;
			}
			else if(c[i]==0)
			{
				zero++;
			}
			else if((c[i]%2==1 && ap>=aq)||((-c[i])%2==1 && aq>=ap))
			{
				odd++;
			}
			if(odd>1)
			{
				cout<<"NO LUCK\n";
				goto hell;
			}
		}
		
		if(zero==26)
		{
			cout<<"YES\n";
			goto hell;
		}
		
		k=0;
		
		for(i=0;i<26;i++)
		{
			c[i]=abs(c[i]);
			for(j=0;j<c[i]/2;j++)
			{
				printf("%c",'a'+i);
				s.push('a'+i);
			}
			if(c[i]%2==1)
			{
				ch='a'+i;
				k=1;
			}
		}
		if(k)
		cout<<ch;
		while(!s.empty())
		{
			cout<<s.top();
			s.pop();
		}
		cout<<endl;
		hell:;			
	}
}
