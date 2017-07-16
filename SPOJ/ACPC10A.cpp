#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
    do
    {
    	cin>>a>>b>>c;
    	
    	if(a==0 && b==0 && c==0)
    	break;
    	else
    	{
    		if((b!=c) && (2*b==a+c))
    		{
    			cout<<"AP "<<c+c-b<<endl;
			}
			else
			{
				cout<<"GP "<<c*c/b<<endl;
			}
		}
	}while(1);
}
