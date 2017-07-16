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
    int sum,left;
}t[200000];
int a[30111];

node newnod(int val){
    node temp;
    temp.sum=val;
    temp.left=val;
    return temp;
}

node merg(node a,node b){
    node c;
    c.sum=a.sum+b.sum;
    c.left=min(a.left,a.sum+b.left);
    return c;
}

void build(int s,int e,int n){
    if(s==e){
        t[n]=newnod(a[s]);
        return ;
    }

    int m=(s+e)/2;
    build(s,m,n*2);
    build(m+1,e,n*2+1);
    t[n]=merg(t[n*2],t[n*2+1]);
}

void update(int s,int e,int n,int x){
    if(s==e){
        if(a[s]==1) a[s]=-1;
        else a[s]=1;
        t[n]=newnod(a[s]);
        return;
    }

    int m=(s+e)/2;
    if(x<=m)
        update(s,m,n*2,x);
    else
        update(m+1,e,n*2+1,x);
    t[n]=merg(t[n*2],t[n*2+1]);
}

int main(){
    int u=10;
    while(u--){
        cout<<"Test "<<10-u<<":\n";
        int n,i,k,z;
        cin>>n;
        frp(i,1,n){
            char x;
            cin>>x;
            if(x=='(')
               a[i]=1;
            else
               a[i]=-1;
         }

          build(1,n,1);

          cin>>z;
          while(z--){
              cin>>k;
              if(!k){
                 if(t[1].sum==0 && t[1].left==0){
                   cout<<"YES\n";
                 }else{
                   cout<<"NO\n";
                 }
              }else{
                 update(1,n,1,k);
              }
          }
    }
}


