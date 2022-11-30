#include <bits/stdc++.h>
using namespace std;
int n,ans;
vector<int>g[300100];
int par[300100];
int subtsz[300100];
void dfs(int node , int parent){
    par[node]=parent;
    subtsz[node]=1;
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node);
            subtsz[node]+=subtsz[v];
        }
    }
    ans+=subtsz[node]*(n-subtsz[node]);
}
int main() {
	cin>>n;
	for(int i=1;i<n;i++){
	    int a,b;
	    cin>>a>>b;
	    g[a].push_back(b);
	    g[b].push_back(a);
	}
	ans=0;
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}