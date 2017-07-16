#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[1000],b[1000];
	scanf("%s",a);
	scanf("%s",b);
	
	while(a[0]=='B' || a[0]=='N')
	{
		 int i=0,c=0,l=strlen(a);
		 
		 while(i<l)
		 {
		 	if(a[i]!=b[i])
		 	{
		 		c++;
		 		while(a[i]!=b[i])
		 		i++;
			}
			i++;
		 }
 		 printf("%d\n",c);
 		 scanf("%s",a);
 		 scanf("%s",b);
	}
}
