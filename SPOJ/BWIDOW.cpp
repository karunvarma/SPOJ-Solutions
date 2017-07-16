#include<bits/stdc++.h>
using namespace std;

int scan()
{
    int n=0;
    char ch=getchar_unlocked();
 
    while (ch<'0'||ch>'9')
    {
        ch=getchar_unlocked();
    }
 
    while (ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar_unlocked();
    }
 
    return n;
}


bool cmp(pair<int,int> p,pair<int,int> q)
{
	if(p.first==q.first)
	return p.second>q.second;
	
	return p.first>q.first;
}

int main()
{
	int t;
	t=scan();
	while(t--)
	{
		int n,in=-1,r,i,j,k;
		n=scan();
		
		vector<pair<int,int> > v;
		r=0;
		for(i=0;i<n;i++)
		{
			j=scan();
			k=scan();
			if(k>r)
			{
				r=k;
				in=i+1;
			}
			v.push_back(make_pair(k,j));
		}
		sort(v.begin(),v.end(),cmp);
		
		r=v[0].second;
		for(i=1;i<n;i++)
		{
			if(r<=v[i].first)
			{
				in=-1;
				break;
			}
		}
        printf("%d\n",in);
	}
}
