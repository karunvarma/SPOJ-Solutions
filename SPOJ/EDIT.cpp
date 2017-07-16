#include<bits/stdc++.h>
using namespace std;

int main()
{
	char a[1010];
	while(scanf("%s",a)!=EOF)
	{
		int ans1=0,ans2=0,i,j,k,l=strlen(a);
		
		if(a[0]>='A' && a[0]<='Z')
		k=1;
		else
		k=0;
		
		for(i=1;i<l;i++)
		{
			if(a[i]>='A' && a[i]<='Z')
			j=1;
			else
			j=0;
			
			if(j==k)
			{
				ans1++;
			}
			k=(k+1)%2;
		}
		if(a[0]>='A' && a[0]<='Z')
		k=1;
		else
		k=0;
		
		k=(k+1)%2;
		ans2++;
		
		for(i=1;i<l;i++)
		{
			if(a[i]>='A' && a[i]<='Z')
			j=1;
			else
			j=0;
			
			if(j==k)
			{
				ans2++;
			}
			k=(k+1)%2;
		}
		cout<<min(ans1,ans2)<<endl;
	}
}
