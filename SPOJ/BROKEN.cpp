#include<bits/stdc++.h>
using namespace std;

#define scanspace(x) scanf("%[^\n\t]s,x")
#define pb push_back
#define mp make_pair
#define gc getchar
#define gcu getchar_unlocked
#define mem(x,y) memset(x,y,sizeof(x))
#define sc2(x,y) sc(x),sc(y)
#define sc3(x,y,z) sc(x),sc(y),sc(z)
#define sc4(x,y,z,w) sc(x),sc(y),sc(z),sc(w)
#define sc5(x,y,z,u,v) sc(x),sc(y),sc(z),sc(u),sc(v)
#define sc6(x,y,z,u,v,w) sc(x),sc(y),sc(z),sc(u),sc(v),sc(w)
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mint map<int,int>
#define miit map<int,int>::iterator
#define mll map<ll,ll>
#define mllit map<ll,ll>::iterator
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pair<int,int> >
#define vppii vector<pair<int,pair<int,int> > > 
#define vpll vector<pair<long long,long long> >
#define vppll vector<pair<long long,pair<long long,long long> > >
#define frp(x,y,z) for(x=y;x<z;x++)
#define frm(x,y,z) for(x=y;x>=z;x--)
#define sec second
#define fir first
#define mod 1000000007

template<typename T>
void sc(T &x){
	char r;
	bool start=false,neg=false;
	T ret=0;
	while(true){
		r=gc();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
		continue;
		if((r-'0'<0 || r-'0'>9) && r!='-' && start)
		break;
		if(start)ret*=10;
		start=true;
		ret+=r-'0';
	}
	if(!neg)
	x= ret;
	else
	x= -ret;
}

template<typename T>
T gcd(T a,T b){
	if(b==0)
	return a;
	return gcd(b,a%b);
}

template <typename T>
T expo(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int limit;
bool checkp[1];
vector<int> prime;

void sieve(){
	mem(checkp,true);
	int i,j;
	prime.pb(2);
	prime.pb(3);
	i=2,j=2;
	while(i*j<=limit){
		checkp[i*j]=false;
		j++;}
	i=3,j=2;
	while(i*j<=limit){
		checkp[i*j]=false;
		j++;}
	for(i=5;i<=limit;i+=6){
		if(checkp[i]){
			prime.pb(i);
			j=2;
			while(i*j<=limit){
				checkp[i*j]=false;
				j++;}}
		if(i+2<=limit)
		if(checkp[i+2]){
			prime.pb(i+2);
			j=2;
			while((i+2)*j<=limit){
				checkp[(i+2)*j]=false;
				j++;}}}
}

//???????????????????????????? POTHA ENDS HERE ?????????????????????????????????????????

int main(){
	
	while(1){
		int i,j,k,n,m,x,y,z,cnt[256];
		mem(cnt,0);
		sc(m);
		
		if(m==0)
		break;
		
	    string s;
	    getline(cin,s);
	    
	    n=s.size();
	    i=0,j=0,z=0,x=0;
	    while(j<n){
	    	while(z<=m && j<n){
	    		cnt[s[j]]++;
	    		if(cnt[s[j]]==1)
	    		z++;
	    		j++;
			}
			if(z>m){
				x=max(x,j-i-1);
			}else{
				x=max(x,j-i);
				break;
			}
			
			while(z>m && i<n){
				cnt[s[i]]--;
				if(cnt[s[i]]==0)
				z--;
				i++;
			}
			
			x=max(x,j-i);
		}
		cout<<x<<endl;
		
	}
}
