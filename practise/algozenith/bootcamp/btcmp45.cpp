#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> &grid, int x)
{
	//Complete the function
    int l=0,r=grid.size()-1;
    while(l<=r){
        int mid=l;
        auto it=lower_bound(grid[mid].begin(),grid[mid].end(),x);
        if(it!=grid[mid].end() && *it==x)return 1;
        l++;
    }
    return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(n, vector<int>(m));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	}
	
	int q;
	cin >> q;
	
	while (q--)
	{
		int x;
		cin >> x;
		if (search(grid, x))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}