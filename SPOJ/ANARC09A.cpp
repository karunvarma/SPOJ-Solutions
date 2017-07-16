#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[10000];
	int t=0;
	
	do
	{
		 cin>>s;
		 t++;
		 if(s[0]=='-')
		 {
		 	break;
		 }
		 
		 stack <char> a;
		 int i,j=0,k=0;
		 
		 for(i=0;i<strlen(s);i++)
		 {
		 	  if(s[i]=='{')
		 	  a.push('{');
		 	  else
		 	  {
		 	       if(a.empty())
					{
						a.push('{');
					    j++;
					}
					else
					{
						a.pop();
					}	
			  }
		 }
		 while(!a.empty())
		 {
		 	k++;
		 	a.pop();
		 }
		 j+=k/2;
		cout<<t<<". "<<j<<endl;
	}while(1);
}
