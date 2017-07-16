#include<bits/stdc++.h>
using namespace std;

int dp[10000][101],n,m;
stack<pair<int,int> > s;

int solve(int num,int i)
{
	if(i==0)
	{
        if(num>n)
		return true;
		return false;		
	}
	
	if(dp[num][i]!=-1)
	{	
    	return dp[num][i];
	}
	
	int b=0,t=num,c=1;
	s.push(make_pair(num,i));
	
	if((i%2==1 && m%2==1) || (i%2==0 && m%2==0))
	{
		while(c<10000)
		{
			 int a=t%10;
			 
			 if(a==9)
			 {
			 	 b=b|solve(num-9*c,i-1);
			 }
			 else
			 {
			 	b=b|solve(num+c,i-1);
			 }
			 
			 t=t/10;
			 c=c*10;
		}
	}
	if((i%2==1 && m%2==0) || (i%2==0 && m%2==1))
	{
		b=1;
		while(c<10000)
		{
			 int a=t%10;
			 
			 if(a==9)
			 {
			 	 b=b&solve(num-9*c,i-1);
			 }
			 else
			 {
			 	b=b&solve(num+c,i-1);
			 }
			 
			 t=t/10;
			 c=c*10;
		}
	}
	dp[num][i]=b;
	
	return dp[num][i];
}

int main()
{
	memset(dp,-1,sizeof(dp));
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
	    
		if(solve(n,m))
		cout<<"Ada\n";
		else
		cout<<"Vinit\n";
		
		while(!s.empty())
		{
			dp[s.top().first][s.top().second]=-1;
			s.pop();
		}	
	}
}
