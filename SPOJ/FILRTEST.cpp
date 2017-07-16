#include<bits/stdc++.h>
using namespace std;

int kmp[1000000];
char a[1000000];

int main()
{
	int k;
	cin>>k;
	
	while(k!=-1)
	{
		int i,j,l;
		scanf("%s",a);
		l=strlen(a);
		
		kmp[0]=0;
		j=0;
		for(i=1;i<l;i++)
		{
			if(a[i]==a[j])
			{
				j++;
				kmp[i]=j;
			}
			else
			{
				while(j!=0)
				{
					j=kmp[j-1];
					if(a[j]==a[i])
					{
						j++;
						kmp[i]=j;
						break;
					}
				}
				if(j==0)
				{
					kmp[i]=0;
			    }
			}
		}
		j=(k-kmp[l-1])/(l-kmp[l-1]);
		if(j<=0 || k<l)
		cout<<"0\n";
		else
		cout<<j<<endl;
		cin>>k;
	}
	
}
