#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j,k,a[200];
		
		for(i=0;i<200;i++)
		{
			a[i]=0;
		}
		
		cin>>n;
		a[0]=n%10;
		a[1]=(n%100-a[0])/10;
		a[2]=n/100;
	
		for(i=n-1;i>=1;i--)
		{
			for(j=0;j<200;j++)
			{
				a[j]=a[j]*i;
			}
			for(j=0;j<200;j++)
			{
				  if(a[j]>9)
				  {
				  	   k=a[j];
				  	   a[j]=a[j]%10;
				  	   a[j+1]+=k/10;
				  }
			}
		}
		k=0;
		for(i=199;i>=0;i--)
		{
			if(a[i]>0 && a[i]<=9)
			k++;
			if(k)
			{
				cout<<a[i];
			}
		}
		cout<<endl;
	}
}
