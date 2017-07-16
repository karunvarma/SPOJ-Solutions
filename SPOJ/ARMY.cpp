#include<bits/stdc++.h>
using namespace std;

int main()
{
	 long long t;
	 cin>>t;
	 while(t--)
	 {
	 	long long n1,n2,i,j;
	 	cin>>n1>>n2;
	 	
	 	priority_queue<long long> q1,q2;
	 	
	 	for(i=0;i<n1;i++)
	 	{
	 		cin>>j;
	 		q1.push(-j);
		}
		for(i=0;i<n2;i++)
		{
			cin>>j;
			q2.push(-j);
		}
		while(!q1.empty() && !q2.empty())
		{
			if(-q1.top()<-q2.top())
			{
				q1.pop();
			}
			else
			{
				q2.pop();
			}
		}
		if(!q1.empty())
		{
			cout<<"Godzilla\n";
		}
		else
		{
			cout<<"MechaGodzilla\n";
		}
	 }
}
