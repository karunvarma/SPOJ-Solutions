#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,k,l,p;
	long long ans=0;
	cin>>n;
	int a[n],b[n*n*n],c[n*n*n],cb=0,cc=0,c1,c2;
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	sort(a,a+n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				b[cb++]=a[i]*a[j]+a[k];
				if(a[i]!=0)
				c[cc++]=a[i]*(a[j]+a[k]);
			}
		}
	}
	
	sort(b,b+cb);
	sort(c,c+cc);
	
	i=j=k=0;	
	while(i<cb && j<cc)
	{
		 if(b[i]==c[j])
		 {
		 	 c1=c2=0;
		 	 k=i;
		 	 while(b[i]==b[k])
		 	 {
		 	 	c1++;
		 	 	k++;
			 }
			 i=k;
			 k=j;
			 while(c[j]==c[k])
			 {
			 	 c2++;
			 	 k++;
			 }
			 j=k;
			 ans+=c1*c2;
		 }
		 else if(b[i]<c[j])
		 i++;
		 else
		 j++;
	}
	cout<<ans<<endl;
}
