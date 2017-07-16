#include<bits/stdc++.h>
using namespace std;
#define mx 1000000007
void multiply(long long F[2][2], long long M[2][2]);
 
void power(long long F[2][2], long long n);
 

long long fib(long long n)
{
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 
void power(long long F[2][2], long long n)
{
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  ((F[0][0]*M[0][0])%mx + (F[0][1]*M[1][0])%mx)%mx;
  long long y =  ((F[0][0]*M[0][1])%mx + (F[0][1]*M[1][1])%mx)%mx;
  long long z =  ((F[1][0]*M[0][0])%mx + (F[1][1]*M[1][0])%mx)%mx;
  long long w =  ((F[1][0]*M[0][1])%mx + (F[1][1]*M[1][1])%mx)%mx;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 
int main()
{
     int t;
     cin>>t;
     while(t--)
     {
     	long long n,m;
     	cin>>n>>m;
     	cout<<(fib(m+2)-fib(n+1)+mx)%1000000007<<endl;
	 }
}
