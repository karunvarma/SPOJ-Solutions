#include<bits/stdc++.h>
using namespace std;

int a[25][25],dp[25][25],cost[25][25],n,mn;

int solve(int x,int y){
	
	if((x==n-1 && y==n)||(x==n && y==n-1)){
		dp[x][y]=abs(a[n][n]-a[x][y]);
		return dp[x][y];	
	}
	
	if(dp[x][y]!=INT_MAX){
		return dp[x][y];
	}
	
	
	int p=INT_MAX,q=INT_MAX;
	if(x+1<=n){
		p=max(abs(a[x+1][y]-a[x][y]),solve(x+1,y));
	}
	if(y+1<=n){
		q=max(abs(a[x][y+1]-a[x][y]),solve(x,y+1));
	}
	
	dp[x][y]=min(p,q);
	return dp[x][y];
}

int getcost(int x,int y){
	if((x==n-1 && y==n)||(x==n && y==n-1)){
		return abs(a[n][n]-a[x][y]);	
	}
	
	int p,q;
	if(x+1<=n && y+1<=n){
		  p=max(abs(a[x+1][y]-a[x][y]),solve(x+1,y));
		  q=max(abs(a[x][y+1]-a[x][y]),solve(x,y+1));
		  if(p<=mn && q<=mn){
		  	     cost[x][y]=min(abs(a[x+1][y]-a[x][y])+getcost(x+1,y),abs(a[x][y+1]-a[x][y])+getcost(x,y+1));
		  }else if(p<=mn){
		  	     cost[x][y]=abs(a[x+1][y]-a[x][y])+getcost(x+1,y);
		  }else{
		  	     cost[x][y]=abs(a[x][y+1]-a[x][y])+getcost(x,y+1);
		  }
	}
	else if(x+1<=n){
		cost[x][y]=abs(a[x+1][y]-a[x][y])+getcost(x+1,y);
	}
	else{
		cost[x][y]=abs(a[x][y+1]-a[x][y])+getcost(x,y+1);
	}
	
	return cost[x][y];
}

int main(){
	int q;
	cin>>q;
	while(q--){
		 int i,j,k,t;
		 cin>>n>>t;
		 
		 for(i=1;i<=n;i++){
		 	for(j=1;j<=n;j++){
		 		cin>>a[i][j];
		 		dp[i][j]=INT_MAX;
		 		cost[i][j]=INT_MAX;
			 }
		 }
		 
		 
		 mn=max(a[1][1],solve(1,1));
		 k=a[1][1]+getcost(1,1);
		 if(k<=t){
		 	cout<<"YES : "<<mn<<" "<<t-k<<endl;
		 }else{
		 	cout<<"NO\n";
		 }
	}
}
