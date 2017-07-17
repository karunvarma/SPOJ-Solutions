#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,u=0;
	cin>>t;
	while(t--)
	{
		u++;
		
		int r,c,i,j,k,n;
		cin>>r>>c;
		
		string s;
		cin>>s;
		
		char a[r][c];
		
		for(i=0;i<s.size();i++)
		{
			a[i/c][i%c]=s[i];
		}
		
		vector<int> v;
		
		n=min(r,c)/2;
		
		j=0;
		while(j<n)
		{
			for(i=j;i<c-j;i++)
			{
				v.push_back(a[j][i]-'0');
			}
			for(i=j+1;i<r-j;i++)
			{
				v.push_back(a[i][c-j-1]-'0');
			}
			for(i=c-j-2;i>=j;i--)
			{
				v.push_back(a[r-j-1][i]-'0');
			}
			for(i=r-j-2;i>j;i--)
			{
				v.push_back(a[i][j]-'0');
			}
			j++;
		}
		
		if(r>c)
		{
			if(c%2==1)
			{
				for(i=j;i<r-j;i++)
				{
					v.push_back(a[i][j]-'0');
				}
			}
		}
		else
		{
			if(r%2==1)
			{
				for(i=j;i<c-j;i++)
				{
					v.push_back(a[j][i]-'0');
				}
			}
		}
		
		char b[1000];
		k=0;
		
		for(i=0;i+5<=s.size();i+=5)
		{
			 b[k++]= 16*v[i]+8*v[i+1]+4*v[i+2]+2*v[i+3]+v[i+4]+'A'-1;
			 if(16*v[i]+8*v[i+1]+4*v[i+2]+2*v[i+3]+v[i+4]==0)
			 b[k-1]=' ';
		}
		b[k]=0;
		
		cout<<u<<" "<<b<<endl;
	}
	
}
