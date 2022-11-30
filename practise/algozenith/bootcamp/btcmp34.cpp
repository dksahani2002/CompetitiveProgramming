#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int nn;
int dp[100100];
bool rec(int i){
    if(i==nn-1)return 1;
    if(i>=nn)return 0;
    if(dp[i]!=-1)return dp[i];
    bool ans=false;
    for(int j=1;j<=v[i];j++){
        if(rec(i+j))return  dp[i]=1;
    }
    return  dp[i]=0;
}
bool isReach(vector<int> jump)
{
	// Complete the function
    v=jump;
    nn=v.size();
    for(int i=0;i<nn;i++){
        cin>>v[i];
        dp[i]=-1;
    }
    dp[nn]=-1;
    return rec(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> jump(n);
	for (auto &i : jump)
		cin >> i;

	if (isReach(jump))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}