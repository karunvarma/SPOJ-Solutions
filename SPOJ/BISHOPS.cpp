#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[200],b[200];
	while(cin>>a)
	{
		if(strlen(a)==1 && a[0]=='1')
		cout<<"1\n";
		
		else
		{
			
			for(int i=0;i<strlen(a);i++)
			{
				b[i]=a[strlen(a)-1-i];
			}
			for(int i=0;i<strlen(a);i++)
			{
				a[i]=b[i];
			}
			
			if(a[0]>'0')
			a[0]=a[0]-1;
			
			else
			{
				int i=1;
				a[0]=a[0]+9;
				while(a[i]=='0' && i<strlen(a))
				{
					a[i]='9';
					i++;
				}
				a[i]--;
			}
			int j=strlen(a);
			for(int i=0;i<j;i++)
			{
				a[i]=(a[i]-'0')*2;
			}
			
			for(int i=0;i<j;i++)
			{
				if(a[i]>9)
				{
					a[i+1]=a[i+1]+a[i]/10;
					a[i]=a[i]%10;
				}
			}
			a[j+1]=0;
			for(int i=0;i<j+1;i++)
			{
				b[i]=a[j-i];
				
			}
			for(int i=0;i<=j;i++)
			{
				a[i]=b[i];
			}
		
			int k=0;
			
			for(int i=0;i<j+1;i++)
			{
				if(a[i]>0 && a[i]<10)
				k++;
				if(k)
				printf("%d",a[i]);
			}
			cout<<endl;
		}
	}
}
