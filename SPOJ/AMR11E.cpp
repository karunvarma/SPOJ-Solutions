#include<bits/stdc++.h>
using namespace std;

vector < vector<int> > a(10001);
bool b[10001];

void seive()
{
	for(int i=2;i<10000;i++)
	{
		if(b[i]==false)
		{
			int j=2;
			while(i*j<=10000)
			{
				a[i*j].push_back(i);
				b[i*j]=true;
				j++;
			}
		}
	}
}

int main()
{
	for(int i=1;i<=10000;i++)
	{
	  b[i]=false;
    }
    
	seive();
	
	int s[1001],count=0;
	
	for(int i=1;count<=1000;i++)
	{
		if(a[i].size()>=3)
		{
			count++;
			s[count]=i;
			
		}
	}
	long long t;
	cin>>t;
	while(t--)
	{
		int i,j,k,n;
		cin>>n;
		cout<<s[n]<<endl;
	}
}
