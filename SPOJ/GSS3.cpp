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

struct node{
    ll sum,left,right,best;
}t[200000];
ll a[51000];

node newnode(ll val){
    node temp;
    temp.sum=temp.left=temp.right=temp.best=val;
    return temp;
}

node merg(node a,node b){
    node c;
    c.sum=a.sum+b.sum;
    c.left=max(a.left,a.sum+b.left);
    c.right=max(b.right,a.right+b.sum);
    c.best=max(a.right+b.left,max(a.best,b.best));
    return c;
}

void build(ll s,ll e,ll n){
    if(s==e){
        t[n]=newnode(a[e]);
        return ;
    }
    ll m=(s+e)/2;
    build(s,m,n*2);
    build(m+1,e,n*2+1);
    t[n]=merg(t[n*2],t[n*2+1]);
}

void update(ll s,ll e,ll n,ll x,ll y){
    if(s==e){
        t[n]=newnode(y);
        return ;
    }
    ll m=(s+e)/2;
    if(x<=m)
    update(s,m,n*2,x,y);
    else
    update(m+1,e,n*2+1,x,y);
    t[n]=merg(t[n*2],t[n*2+1]);
}

node query(ll s,ll e,ll n,ll x,ll y){
    if(s>y ||e<x)
        return newnode(INT_MIN/2);
    if(x<=s && y>=e)
        return t[n];
    ll m=(s+e)/2;

    node a=query(s,m,n*2,x,y);
    node b=query(m+1,e,n*2+1,x,y);
    return merg(a,b);
}



int main(){
    ll n,i,j,k,x,y,z;
    cin>>n;

    frp(i,1,n) cin>>a[i];

    build(1,n,1);

    cin>>z;
    while(z--){
        cin>>i>>j>>k;

        if(!i){
            update(1,n,1,j,k);
        }else{
            cout<<query(1,n,1,j,k).best<<endl;
        }
    }
}
