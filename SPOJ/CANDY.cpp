#include<iostream>
using namespace std;
int main()
{
     int n,i,j,ans,avg2;
     float avg1;
     cin>>n;
     do
     {
     	int a[n];
     	avg2=avg1=ans=0;
     	for(i=0;i<n;i++)
     	{
     		cin>>a[i];
     		avg1+=a[i];
		}
		avg1=avg1/n;
		avg2=avg1;
		if(avg2==avg1)
		{
			for(i=0;i<n;i++)
			{
				if(a[i]>avg1)
				{
					ans+=a[i]-avg1;
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<"-1\n";
		}
		cin>>n;
	 }while(n!=-1);
}
