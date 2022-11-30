#include <bits/stdc++.h>
using namespace std;

void RotateMatrix(vector<vector<int>> &v)
{
    // Complete the function
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(i>j) swap(v[i][j],v[j][i]);
        }
    }
    int l=0,r=n-1;
    while(l<r){
        for(int i=0;i<n;i++)swap(v[i][l],v[i][r]);
        l++;r--;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }

    RotateMatrix(v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}