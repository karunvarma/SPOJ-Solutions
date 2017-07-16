#include<bits/stdc++.h>
using namespace std;
int main()
{
	do
	{
		long long n1,n2,i,j,k,sum=0,prev1=0,prev2=0;
		
		cin>>n1;
		
		if(n1==0)
		break;
		
		long long a[n1],sum1[n1];
		cin>>a[0];
		for(i=1;i<n1;i++)
		{
		   cin>>a[i];
	    }  
	    sort(a,a+n1);
	    sum1[0]=a[0];
	    for(i=1;i<n1;i++)
	    sum1[i]=sum1[i-1]+a[i];
	    
		cin>>n2;
		long long b[n2],sum2[n2];
		cin>>b[0];
		
		for(i=1;i<n2;i++)
		{
		    cin>>b[i];
	    }
	    sort(b,b+n2);
	    sum2[0]=b[0];
	    for(i=1;i<n2;i++)
	    {
	    	sum2[i]=sum2[i-1]+b[i];
		}
		vector <long long> v1,v2;
		
		i=j=0;
		
		while(i<n1 && j<n2)
		{
			if(a[i]==b[j])
			{
				v1.push_back(i);
				v2.push_back(j);
				i++;
				j++;
			}
			else if(a[i]>b[j])
			j++;
			else
			i++;
		}
		v1.push_back(n1-1);
		v2.push_back(n2-1);
		
		if(v1.size()==1)
		{
			 if(sum1[n1-1]>sum2[n2-1])
			 cout<<sum1[n1-1]<<endl;
			 else
			 cout<<sum2[n2-1]<<endl;
			 continue;
		}
		else
		{
		      k=0;
			  while(k<v1.size())
			  {
			  	   if((sum1[v1[k]]-prev1)>=(sum2[v2[k]]-prev2))
			  	   {
			  	   	  //  cout<<(sum1[v1[k]]-prev1)<<"   "<<(sum2[v2[k]]-prev2)<<endl;
			  	        sum+=sum1[v1[k]]-prev1;
						prev1=sum1[v1[k]];
						prev2=sum2[v2[k]];
						k++;	
				   }
				   else
				   {
				   	    sum+=sum2[v2[k]]-prev2;
						prev1=sum1[v1[k]];
						prev2=sum2[v2[k]];
						k++;
				   }
				   
			  }
			  
		}

		cout<<sum<<endl;
		
	}while(1);
}
