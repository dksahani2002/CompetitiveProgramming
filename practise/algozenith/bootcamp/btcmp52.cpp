#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>>&a,int mid){
    int no=a.size()*a[0].size(); 
    int cnt=0;
    for(int i=0;i<a.size();i++){
        cnt+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
    }
    return cnt>=((no+1)/2);
}
int MedianInMatrix(vector<vector<int>> &a)
{
    // Complete the function
    int l=0,r=1e9,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(a,mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << MedianInMatrix(a) << "\n";

    return 0;
}