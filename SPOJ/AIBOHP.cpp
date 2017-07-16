#include<bits/stdc++.h>
using namespace std;

int a[6101][6101];
char s[6101],p[6101];

int m(int a,int b)
{
	if(a>b)
	return a;
	return b;
}

int main()
{
	int t,i,j,k;
	cin>>t;
	
	for(i=0;i<=6100;i++)
	{
		a[0][i]=0;
		a[i][0]=0;
	}
	
	while(t--)
	{
		 cin>>s;
		 for(i=0;i<strlen(s);i++)
		 {
		 	p[strlen(s)-1-i] = s[i];
		 }
		 p[strlen(s)]=0;
		 
		 int len,l1,l2,l;
		 l1=l2=strlen(s);
		 
		 
		 for(i=1;i<=l1;i++)
		 {
		 	for(j=1;j<=l2;j++)
		 	{
		 		if(s[i-1]==p[j-1])
		 	    a[i][j]=1+a[i-1][j-1];
		 	    
				else
		 	    a[i][j]=m(a[i-1][j],a[i][j-1]);
		 	    
			}
		 }
		 cout<<l1-a[l1][l1]<<endl;
	}
}
