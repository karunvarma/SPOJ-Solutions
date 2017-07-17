#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,k,l1,l2;
	t=10;
	while(t--)
	{
		char a[300],b[300],d[300],c;
		
		for(i=0;i<300;i++)
		{
			a[i]=b[i]=d[i]=0;
		}
		
		cin>>a;
		cin>>b;
		
		l1=strlen(a),l2=strlen(b);
		
		for(i=0;i<l1/2;i++)
		{
			c=a[i];
			a[i]=a[l1-1-i];
			a[l1-1-i]=c;
		}
		
		for(i=0;i<l2/2;i++)
		{
			c=b[i];
			b[i]=b[l2-1-i];
			b[l2-1-i]=c;
		}
		
		for(i=0;i<l1;i++)
		{
			 a[i]-='0';	
		}
		for(i=0;i<l2;i++)
		{
			b[i]-='0';
		}
		
		for(i=0;i<l1;i++)
		{
			a[i]=a[i]+b[i];
			if(a[i]>9)
			{
				a[i+1]=a[i+1]+a[i]/10;
				a[i]=a[i]%10;
			}
		}
		for(i=0;i<l1;i++)
		{
			if(a[i+1]%2==1)
			{
				a[i+1]--;
				a[i]=a[i]+10;
			}
			a[i]=a[i]/2;
			d[i]=a[i];
		}
		for(i=0;i<l1;i++)
		{
			if(d[i]<b[i])
			{
				d[i+1]--;
				d[i]+=10;
			}
			d[i]=d[i]-b[i];
		}
		k=0;
		for(i=299;i>=0;i--)
		{
			if(a[i]>0 && a[i]<=9)
			k++;
			if(k)
			printf("%d",a[i]);
		}
		cout<<endl;
		k=0;
		for(i=299;i>=0;i--)
		{
			if(d[i]>0 && d[i]<=9)
			k++;
			if(k)
			printf("%d",d[i]);
		}
		cout<<endl;
	}
}
