#include<bits/stdc++.h>
using namespace std;

int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97,101,103};
int num[1000000],cnt=0;
int n[1000000],c=0;

int main()
{
	int i,j,k,t;
	for(i=1;i<=1000000;i++)
	{
		for(j=0;a[j]*a[j]*a[j]<=i;j++)
		{
			if(i%a[j]==0)
			{
				k=0;t=i;
				while(t%a[j]==0 && t>=a[j])
				{
					k++;
					t=t/a[j];
				}
				if(k>=3)
				{
					n[c++]=i;
					goto hell;
				}
			}
		}
		num[cnt++]=i;
		hell:;
	}
	
	
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		cin>>i;
        
        if(binary_search(n,n+c,i)==true)
        {
        	cout<<"Case "<<u<<": Not Cube Free\n";
		}
		else
		{
			cout<<"Case "<<u<<": "<<lower_bound(num,num+cnt,i)-num+1<<endl;;
		}
	}
}
