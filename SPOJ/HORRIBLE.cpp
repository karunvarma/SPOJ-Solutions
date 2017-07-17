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

ll a[100101],tr[400001],lz[400001];

void build(ll s,ll e,ll n){
    if(s==e){
        tr[n]=lz[n]=0;
        return ;
    }
    ll m=(s+e)/2;
    build(s,m,n*2);
    build(m+1,e,n*2+1);
    tr[n]=lz[n]=0;
}

void update(ll s,ll e,ll n,ll x,ll y,ll z){
    if(lz[n]){
        tr[n]=tr[n]+(e-s+1)*lz[n];
        if(s!=e){
            lz[n*2]+=lz[n];
            lz[n*2+1]+=lz[n];
        }
        lz[n]=0ll;
    }

    if(x>e || y<s)
        return ;

    if(x<=s && y>=e){
        tr[n]+=(e-s+1)*z;
        if(s!=e){
            lz[n*2]+=z;
            lz[n*2+1]+=z;
        }
        return ;
    }

    ll m=(s+e)/2;
    update(s,m,n*2,x,y,z);
    update(m+1,e,n*2+1,x,y,z);
    tr[n]=tr[n*2+1]+tr[n*2];
}

ll query(ll s,ll e,ll n,ll x,ll y){
    if(lz[n]){
        tr[n]=tr[n]+(e-s+1)*lz[n];
        if(s!=e){
            lz[n*2]+=lz[n];
            lz[n*2+1]+=lz[n];
        }
        lz[n]=0ll;
    }

    if(x>e || y<s)
        return 0;

    if(x<=s && y>=e){
        return tr[n];
    }

    ll m=(s+e)/2;
    ll ans=query(s,m,n*2,x,y);
    ans+=query(m+1,e,n*2+1,x,y);
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m,i,j,k,x,y,z;
        cin>>n>>m;

        frp(i,1,n) a[i]=0;

        build(1,n,1);

        while(m--){
            cin>>z;
            if(!z){
                cin>>i>>j>>k;
                update(1,n,1,i,j,k);
            }else{
                cin>>x>>y;
                cout<<query(1,n,1,x,y)<<endl;
            }
        }
    }
}
