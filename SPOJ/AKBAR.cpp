#include<bits/stdc++.h>
using namespace std;

bool visit[1000001];
long long st[1000001];
long long pro[1000001];
long long dis[1000001];

void fastscan(long long &x)
    {
        register long long c;
        x =0;
        c=getchar();
        
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        
    }
int main()
{
      long long t;
      fastscan(t);
      while(t--)
      {
            long long n,r,m,i,j,k,cur;
           
             fastscan(n);
             fastscan(r);
             fastscan(m);
          
            vector <vector <long long > > v(n+1);
            
			vector <long long> nod;
            
			for(i=1;i<=n;i++)
            st[i]=-1;
           
		    while(r--)
            {
                fastscan(i);
                fastscan(j);
                v[i].push_back(j);
                v[j].push_back(i);
            }
            
            for(i=1;i<n+1;i++)
            {
                pro[i]=0;
            }
            for(j=1;j<n+1;j++)
            {
                   visit[j]=false;
            }
            while(m--)
            {
                fastscan(i);
                fastscan(j);
                nod.push_back(i);
                st[i]=j;
                pro[i]++;
            }
            stack <long long> vi;
            
            for(i=0;i<nod.size();i++)
            {
                while(!vi.empty())
                {
                	visit[vi.top()]=false;
                	vi.pop();
				}
                queue <long long > q;
                
                q.push(nod[i]);
                vi.push(nod[i]);
                visit[nod[i]]=true;
                dis[nod[i]]=0;
    
                if(pro[nod[i]]>1)
                    {
                    cout<<"No\n";
                    goto hell;
                }
                
                while(!q.empty())
                {
                     cur=q.front();
                     q.pop();
                     
                     if(dis[cur]>=st[nod[i]])
                     break;
                    
                     else
                     {
                         for(j=0;j<v[cur].size();j++)
                         {
                               if(visit[v[cur][j]]==false)
                               {
                                     dis[v[cur][j]]=dis[cur]+1;
                                     q.push(v[cur][j]);
                                      vi.push(v[cur][j]);
                                     pro[v[cur][j]]++;
                                     if( pro[v[cur][j]]>1)
                                     {
                                         cout<<"No\n";
                                          goto hell;
                                     }
                                     if(st[v[cur][j]]!=-1)
                                         {
                                          cout<<"No\n";
                                          goto hell;
                                     }
                                    visit[v[cur][j]]=true;
                               }
                         }
                     }    
                }
            }
            for(i=1;i<n+1;i++)
            {
                if(pro[i]==0)
                {
                   cout<<"No\n";
                   goto hell;
                }
            }
            cout<<"Yes\n";
            hell:;
      }
}
