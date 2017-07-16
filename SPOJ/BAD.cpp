#include<bits/stdc++.h>
using namespace std;

int scan()
{
	char r;
	bool start=false;
	int ret=0;
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

int cnt[251],v[251][251],ind[251];
bool mark[251][251];

int main()
{
	int t;
	t=scan();
	while(t--)
	{
		int n,i,j,k;
		n=scan();
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				mark[i][j]=false;
				v[i][j]=0;
			}
			mark[i][i]=true;
			cnt[i]=ind[i]=0;
		}
		
		for(i=0;i<n*(n-1)/2;i++)
		{
			j=scan();
			k=scan();
			v[j][ind[j]++]=k;
		}
		
	    int ar[251],top=1;
	    
	    for(i=1;i<=n;i++)
	    {
	    	
	    	for(j=0;v[i][j]!=0;j++)
	    	{
	    		cnt[i]++;
	    		ar[top++]=v[i][j];
	    		mark[i][v[i][j]]=true;
	    		if(cnt[i]==n-1)
	    		{
	    			printf("%d %d\n",i,n-1);
	    			goto bye;
				}
			}
			while(top)
			{
				 k=ar[top-1];
				 top--;
				 
				 for(j=0;j<v[k][j]!=0;j++)
				 {
				 	  if(!mark[i][v[k][j]])
				 	  {
				 	      mark[i][v[k][j]]=true;
						  cnt[i]++; 
						  if(cnt[i]==n-1)
				    	  {
	    						printf("%d %d\n",i,n-1);
	    						goto bye;
						  }	
					  }
				 }
			}
		}
		k=0;
		j=0;
		
		for(i=1;i<=n;i++)
		{
			if(j<cnt[i])
			{
				 k=i;
				 j=cnt[i];	
		    }
		   // cout<<cnt[i]<<" ";
		}
		printf("%d %d\n",k,j);
		bye:;
	}
}
