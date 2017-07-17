#include<bits/stdc++.h>
using namespace std;

char c[10];

int main()
{
	int n;
	scanf("%d",&n);
	
	while(n)
	{		
		int i,j,k,m=0;
		
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			scanf("%d",&k);
			
		    if(c[0]=='M' && k)
			{
			     while(k%2==0)
				 {
				 	m++;
				 	k=k/2;
				 }	
			}
			else if(c[0]=='M')
			m=16;	
		}
		if(m>=16)
		{
			cout<<"1\n";
		}
	    else
        {
        	k=65536;
            while(m)
			{
				k=k/2;;
				m--;
			} 	
			cout<<k<<endl;
		}
        
		scanf("%d",&n);
	}
}
