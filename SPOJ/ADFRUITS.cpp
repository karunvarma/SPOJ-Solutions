#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[200],b[200],arr[201][201];
	int dp[201][201];
	
	while(scanf("%s",a)!=EOF)
	{
		cin>>b;
		int l1=strlen(a),l2=strlen(b),i,j,k;
		
		for(i=0;i<=l1;i++)
		{
			dp[i][0]=0;
		}
		for(j=0;j<=l2;j++)
		{
			dp[0][j]=0;
		}
		for(i=1;i<=l1;i++)
		{
			for(j=1;j<=l2;j++)
			{
				if(a[i-1]==b[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
					arr[i][j]='d';
				}
				else if(dp[i-1][j]>dp[i][j-1])
				{
					dp[i][j]=dp[i-1][j];
					arr[i][j]='u';
				}
				else
				{
					dp[i][j]=dp[i][j-1];
					arr[i][j]='l';
				}
			}
		}
		
		i=l1,j=l2;
		stack<char> s;
		while( i && j)
		{
			if(arr[i][j]=='d')
			{
				s.push(a[i-1]);
				i--;
				j--;
			}
			else if(arr[i][j]=='u')
			i--;
			else
			j--;
		}
		i=0,j=0;
		while(i<l1 && j<l2 && !s.empty())
		{
			while(a[i]!=s.top())
			{
				cout<<a[i];
				i++;
			}
			while(b[j]!=s.top())
			{
				cout<<b[j];
				j++;
			}
			cout<<s.top();
			i++;
			j++;
			s.pop();
		}
		for(;i<l1;i++)
		cout<<a[i];
		for(;j<l2;j++)
		cout<<b[j];
		cout<<endl;
	}
}
