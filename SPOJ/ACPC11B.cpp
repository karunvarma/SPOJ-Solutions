#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n1,n2,i,j,k,min=10000000;
		cin>>n1;
		long long a[n1];
		
		for(i=0;i<n1;i++)
		cin>>a[i];
		sort(a,a+n1);
		
		cin>>n2;
		long long b[n2];
		
		for(i=0;i<n2;i++)
		cin>>b[i];
		sort(b,b+n2);
		
		i=0,j=0;
		
		while(i<n1 && j<n2)
		{
			 if(a[i]==b[j])
			 {
			 	 min=0;
			 	 break;
			 }
			 else if(a[i]>b[j])
			 {
			 	k=a[i]-b[j];
			 	if(k<min)
			 	min=k;
			 	j++;
			 }
			 else
			 {
			 	k=b[j]-a[i];
			 	if(k<min)
			 	min=k;
			 	i++;
			 }
		}
		cout<<min<<endl;
	}
}
