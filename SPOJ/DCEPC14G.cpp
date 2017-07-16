#include<bits/stdc++.h>
using namespace std;

inline int scan()
{
  register int c = getchar_unlocked(), x = 0;
  while ((c < 48 || c > 57) && c != '-') 
  {
    c = getchar_unlocked();
  }
  int sign = 1;
  if (c == '-')
  {
    c = getchar_unlocked();
    sign = -1;
  }
  while (c >= 48 && c <= 57)
  {
    x = x * 10 + c - 48;
    c = getchar_unlocked();
  }
  return sign * x;
}

int main()
{
	int t;
	t=scan();
	while(t--)
	{
		int n,i,j,k;
		n=scan();
		
		int p[n];
		for(i=0;i<n;i++)
		{
			p[i]=scan();
		}
		for(i=0;i<n;i++)
		{
			j=scan();
			p[i]=p[i]%(j+1);
		}
		k=p[0];
		for(i=1;i<n;i++)
		{
			k=k^p[i];
		}
		if(k)
		printf("Amit\n");
		else
		printf("Mishra\n");
	}
}
