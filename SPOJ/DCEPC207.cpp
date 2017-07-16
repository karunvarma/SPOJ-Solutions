#include<bits/stdc++.h>
using namespace std;

char s[10011],a[10011],mx[10011];

int main()
{
	int t,u;
	cin>>t;
	getchar();
	for(u=1;u<=t;u++)
	{
		 cout<<"Case #"<<u<<":\n";
	     int l,i,j,k,c,key=0,cnt[26];
		 char ch;
		 
		 gets(s);
		 l=strlen(s);
		 
		 vector<string> v;
		 c=0;
		 
		 for(i=0;i<26;i++)
		 cnt[i]=0;
		 
		 for(i=0;i<l;i++)
		 {
		 	 if(s[i]!=' ')
		 	 {
		 	 	 a[c++]=s[i];
		 	 	 cnt[s[i]-'a']++;
		 	 	 
			 }
			 else
			 {
			 	 a[c]=0;
			 	 c=0;
			 	 v.push_back(a);
			 }
		 }
		 if(c!=0)
	     {
	     	 a[c]=0;
			 c=0;
			 v.push_back(a);
		 }
		 
		 j=0;
		 for(i=0;i<26;i++)
		 {
		 	 if(j<cnt[i])
		 	 {
		 	 	j=cnt[i];
		 	 	ch=i+'a';
			 }
		 }
		 
		 for(i=0;i<v.size();i++)
	     {
	     	  for(j=0;j<26;j++)
	     	  cnt[j]=0;
	     	  
	     	  for(k=0;v[i][k]!=0;k++)
	          {
	          	   cnt[v[i][k]-'a']++;
			  }
			  
			  k=0;
			  c=0;
			  for(j=0;j<26;j++)
		      {
		      	   if(k<cnt[j])
		      	   {
		      	       k=cnt[j];
						 c=j;
						 key=0;	
				   }
				   else if(k==cnt[j])
				   {
				   	   key=1;
				   }
			  }
			  j=c+'a';
			  if(!key)
			  mx[i]=char(j);
			  else
			  mx[i]=1;
		 }
		 
		 
		 for(i=0;i<v.size();i++)
		 {
		 	  if(mx[i]==ch)
		 	  {
		 	      cout<<v[i]<<endl;	
			  }
		 }
	}
}
