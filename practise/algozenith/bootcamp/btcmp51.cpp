#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second>b.second;
}
int MaxVials(vector<pair<int,int>> &a, int m)
{
    // Complete the function
    sort(a.begin(),a.end(),cmp);
    int ans=0;
    for(auto x:a){
        if(m>=x.first){
            ans+=x.first*x.second;
            m-=x.first;
        }else{
            ans+=x.second*m;
            return ans;
        }
    }
    return ans;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    
    cout << MaxVials(a, m) << '\n';
    return 0;
}