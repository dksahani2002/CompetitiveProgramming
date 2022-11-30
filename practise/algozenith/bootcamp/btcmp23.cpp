#include <bits/stdc++.h>
using namespace std;

int FindCeleb(vector<vector<int>> &a)
{
    int n=a.size();
    // Complete the solution
    vector<int>v(n),q(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(a[i][j])v[j]++;
           else q[i]++; 
        }
    }
    for(int i=0;i<n;i++){
        if(v[i]==n-1 && q[i]==n)return i+1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << FindCeleb(a) << '\n';
}