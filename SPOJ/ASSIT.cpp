#include<stdio.h>

int a[20000],b[20000],ans[4000],c=0,c1=0,c2=0;

void pre()
{
	while(c<3000)
	{
	 	ans[c++]=b[0];
		for(int i=1;i<c2;i++)
		{
			if((i)%ans[c-1]!=0)
			{
				a[c1++]=b[i];
			}
		}
		c2=0;
		ans[c++]=a[0];
		for(int i=1;i<c1;i++)
		{
			if((i)%ans[c-1]!=0)
			{
				b[c2++]=a[i];
			}
		}
		c1=0;
	}
}
int main()
{
	int i,n;
	c2=0;
	ans[c++]=2;
	for(i=3;i<=34000;i+=2)
	{
		b[c2++]=i;
	}
	
	pre();
    scanf("%d",&n);
	while(n)
	{
		printf("%d\n",ans[n-1]);
		scanf("%d\n",&n);
	}
}
