#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,j,k,n;
	cin>>n;
	long long a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	cin>>k;
	
    deque<long long> q;
    
    for(i=0;i<k;i++)
    {
    	while(!q.empty() && a[i]>=a[q.back()])
    	q.pop_back();
    	q.push_back(i);
	}
	
	cout<<a[q.front()];
	
	for(;i<n;i++)
	{
		while(!q.empty() && q.front()<=i-k)
		q.pop_front();
		while(!q.empty() && a[i]>=a[q.back()])
		q.pop_back();
		q.push_back(i);
		cout<<" "<<a[q.front()];
	}
}
