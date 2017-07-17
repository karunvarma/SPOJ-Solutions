#include<bits/stdc++.h>
using namespace std;

long long scan()
{
	char r;
	bool start=false;
	long long ret=0;
	while(true)
	{
		r=getchar_unlocked();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
		{
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start)
		{
			break;
		}
		if(start)ret*=10;
		start=true;
		ret+=r-'0';
	}
	return ret;
}

long long a[200010],b[200010];

long long merge(long long low,long long mid,long long high)
{
	 long long h=low,i=low,j=mid+1,k;
	 
	 long long x,y,z,ans=0;
	 
	 y=low;
	 for(x=mid+1;x<=high;x++)
	 {
	 	  while(a[y]<=a[x] && y<=mid)
	 	  y++;
	 	  
	 	  if(y==mid+1)
	 	  break;
	 	  else
	 	  ans+=(mid+1-y);
	 }
	 
	 while(h<=mid && j<=high)
	 {
	 	   if(a[h]<=a[j])
	 	   b[i]=a[h++];
	 	   
	 	   else
	 	   b[i]=a[j++];
	 	   
	 	   i++;
	 }
	 
	 if(h<=mid)
	 {
	 	for(k=h;k<=mid;k++)
	 	{
	 		 b[i++]=a[k];
		}
	 }
	 else
	 {
	 	for(k=j;k<=high;k++)
	 	{
	 	    b[i++]=a[k];	
		}
	 }
	 
	 for(i=low;i<=high;i++)
	 {
	 	 a[i]=b[i];
	 }
	 return ans;
}

long long solve(long long low,long long high)
{
	long long mid=(low+high)/2;
	long long ans=0;
	
	if(low<high)
	{
		ans=solve(low,mid);
		ans+=solve(mid+1,high);
		ans+=merge(low,mid,high);
	}
	return ans;
}

int main()
{
	long long t;
	t=scan();
	while(t--)
	{
		long long n,i,j,k;
		cin>>n;
		
		for(i=1;i<=n;i++)
		{
			a[i]=scan();
		}
		
		cout<<solve(1,n)<<endl;
	}
}
