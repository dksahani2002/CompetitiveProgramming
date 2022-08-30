#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int n,m;cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j]; 
        } 
    }
    for(int i=0;i<n;i++){
        vector<int>temp=v[i];
        sort(temp.begin(),temp.end());
        if(temp==v[i]){
            if(i==n-1){
                cout<<1<<" "<<1<<endl;
                return;
            }
            continue;
        }

        for(int j=0;j<m;j++){
            if(v[i][j]!=temp[j]){
                for(int k=j;k<m;k++){
                    if(v[i][k]==temp[j]){
                        for(int l=0;l<n;l++){
                            swap(v[l][j],v[l][k]);
                        }
                        for(int s=0;s<n;s++){
                             vector<int>temp=v[s];
                            sort(temp.begin(),temp.end());
                            if(temp==v[s])continue;
                            else {
                                cout<<-1<<endl;
                                return;
                            }
                        }
                        cout<<j+1<<" "<<k+1<<endl;
                        return;
                    }
                }
            }
            
        }
    }
    return;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}