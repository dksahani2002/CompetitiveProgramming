#include <bits/stdc++.h>
using namespace std;

int MinimumPlatforms(vector<pair<int, int>> &trains)
{
    // Complete the function
    vector<pair<int,int>>v;
    for(auto x:trains){
        v.push_back({x.first,1});
        v.push_back({x.second,-1});
    }
    sort(v.begin(),v.end());
    int ans=0,res=0;
    for(auto x:v){
        res+=x.second;
        ans=max(ans,res);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> trains;

    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        trains.push_back({s, t});
    }

    cout << MinimumPlatforms(trains) << '\n';
}