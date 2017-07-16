#include<bits/stdc++.h>
using namespace std;

char s[5001];
long long a[5001];

long long cal(int i)
{
	 if(i==0)
	 {
	 	a[0]=1;
	 	return 1;
	 }
	 else if(i==1)
	 {
	 	  if(s[i-1]=='1' && s[i]>'0')
	 	  {
	 	  	  a[i]=2;
	 	  	  return 2;
		  }
		  else if(s[i-1]=='1')
		  {
		  	a[i]=1;
		  	return 1;
		  }
		  else if(s[i-1]=='2' && s[i]>'0' && s[i]<'7')
		  {
		  	a[i]=2;
		  	return 2;
		  }
		  else if(s[i-1]=='2' && s[i]=='0')
		  {
		  	 a[i]=1;
		  	 return 1;
		  }
		  else
		  {
		  	a[i]=1;
		  	return 1;
		  }
	 }
	
	 if(a[i]!=-1)
	 return a[i];
	 
	 if(s[i-1]=='1' && s[i]>'0')
	 {
	 	 a[i]=cal(i-1)+cal(i-2);
	 	 return a[i-1]+a[i-2];
	 }
	 else if(s[i-1]=='1')
	 {
	 	a[i]=cal(i-2);
	 	return a[i-2];
	 }
	 else if(s[i-1]=='2' && s[i]>'0' && s[i]<'7')
	 {
	 	a[i]=cal(i-1)+cal(i-2);
	 	return a[i-1]+a[i-2];
	 }
	 else if(s[i-1]=='2' && s[i]=='0')
	 {
	 	a[i]=cal(i-2);
	 	return a[i];
	 }
	 else 
	 {
	 	a[i]=cal(i-1);
	 	return a[i-1];
	 }
}

int main()
{
     do
	 {
	     cin>>s;
	     
		 if(s[0]=='0')
		 break;
	 	 
	 	 int i,j,k,l=strlen(s);
	 	 
	     for(i=0;i<l;i++)
		 {
		         a[i]=-1; 		
			 
		 }
		 
		  cout<<cal(l-1)<<endl;	 	
	 }while(1);	
}
