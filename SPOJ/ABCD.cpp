/* 
    Har Har Mahadev
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<long long,long long> >
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()
#define frp(i,x,y) for(i=x;i<=y;i++)
#define frn(i,x,y) for(i=x;i>=y;i--)
#define mod 1000000007ll
#define FILE freopen("input.in", "rt", stdin),freopen("output.txt", "wt", stdout);


template <class T>
T expo(T x,T n) { T result=1; while(n>0){ if(n%2==1) result=(result*x)%mod; x=(x*x)%mod; n=n/2; } return result; }

// ------------------------------------------- Potha Ends Here------------------------------------------------ //

int main(){
	int n,i,j,k,p=-1,x,y,z;
	cin>>n;
	n=n*2;
	string a,b;
	cin>>a;
	b=a;
	
	bool chk[4];
	
	for(i=0;i<n;i+=2){
		for(j=0;j<4;j++){
			chk[j]=false;
		}
		chk[a[i]-'A']=chk[a[i+1]-'A']=true;
		
		k=0,x=i;
		for(j=0;j<4;j++){
			if(!chk[j]){
				 if(p!=j){
			         b[x]=j+'A';
					 break;	 	 
				 }else{
				 	b[x+1]=j+'A';
				 	p=j;
				 	k=1;
				 }
			}
		}
		
		if(k)
		continue;
		
		for(;j<4;j++){
			if(!chk[j]){
				 	b[x+1]=j+'A';
				 	p=j;
				 }
		}
	}
	cout<<b<<endl;
}
