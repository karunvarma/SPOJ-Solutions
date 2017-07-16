#include<bits/stdc++.h>
using namespace std;

int dp[1100][1100][3],dam[3][2]={3,2,-5,-10,-20,5};

int solve(int h,int a,int i)
{
	if(h<=0 || a<=0)
	return 0;
	
	if(dp[h][a][i]!=-1)
	return dp[h][a][i];
	
	dp[h][a][i]=1+max(solve(h+dam[(i+1)%3][0],a+dam[(i+1)%3][1],(i+1)%3),solve(h+dam[(i+2)%3][0],a+dam[(i+2)%3][1],(i+2)%3));
	return dp[h][a][i];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h,a,i,j,k;
		cin>>h>>a;
		
		for(i=0;i<1100;i++)
		{
			for(j=0;j<1100;j++)
			{
				for(k=0;k<3;k++)
				dp[i][j][k]=-1;
			}
		}
		i=max(solve(h+dam[0][0],a+dam[0][1],0),max(solve(h+dam[1][0],a+dam[1][1],1),solve(h+dam[2][0],a+dam[2][1],2)));
		cout<<i<<endl;
	}
}
