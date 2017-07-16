#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector <int> a;
		vector <int> b;
		vector <int> c;
		long long an,bn,i,j,k=0;
		cin>>an>>bn;
		while(an>0)
		{
			a.push_back(an%10);
			an=an/10;
		}
		while(bn>0)
		{
			b.push_back(bn%10);
			bn=bn/10;
		}
		an=bn=0;
		for(i=0;i<a.size();i++)
		{
			an=an*10+a[i];
		}
		for(i=0;i<b.size();i++)
		{
			bn=bn*10+b[i];
		}
		j=an+bn;
		
		while(j>0)
		{
			i=j%10;
			if(i>0)
			k++;
			if(k>0)
			{
				c.push_back(i);
			}
			j=j/10;
		}
		for(i=0;i<c.size();i++)
		cout<<c[i];
		cout<<endl;
	}
}
