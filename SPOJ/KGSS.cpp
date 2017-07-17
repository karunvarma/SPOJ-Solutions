#include<bits/stdc++.h>
using namespace std;

struct node{
	int p,q;
}t[400000];

int a[100001];

node merge(node x,node y){
	node temp;
	if(x.p>=y.p){
		temp.p=x.p;
		if(x.q>=y.p){
			temp.q=x.q;
		}else{
			temp.q=y.p;
		}
	}else{
		temp.p=y.p;
		if(x.p<=y.q){
			temp.q=y.q;
		}else{
			temp.q=x.p;
		}
	}
	return temp;
}

void build(int s,int e,int n){
	 if(s==e){
	 	 t[n].p=a[s];
	 	 t[n].q=INT_MIN;
	 	 return ;
	 }
	 
	 int m=(s+e)/2;
	 build(s,m,n*2);
	 build(m+1,e,n*2+1);
	 
	 t[n]=merge(t[n*2],t[n*2+1]);
}

void update(int s,int e,int n,int x,int y){
	if(s==e){
		t[n].p=y;
		return ;
		
	}
	int m=(s+e)/2;
	
	if(x<=m){
		update(s,m,n*2,x,y);
	}else{
		update(m+1,e,n*2+1,x,y);
	}
	
	t[n]=merge(t[n*2],t[n*2+1]);
}

node query(int s,int e,int n,int x,int y){
	if(s>=x && y>=e)
	return t[n];
	
	int m=(s+e)/2;
	
	if(x<=m && y>m){
		return merge(query(s,m,n*2,x,y),query(m+1,e,n*2+1,x,y));
	}else if(y<=m){
		return query(s,m,n*2,x,y);
	}else{
		return query(m+1,e,n*2+1,x,y);
	}
}

int main(){
	int n,i,j,k,m;
	cin>>n;
	
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	
	build(1,n,1);
	
	cin>>m;
	while(m--){
		char c;
		cin>>c;
		
		if(c=='U'){
			cin>>i>>j;
			update(1,n,1,i,j);
		}else{
			cin>>i>>j;
			node x=query(1,n,1,i,j);
			cout<<x.p+x.q<<endl;
		}
	}
}
